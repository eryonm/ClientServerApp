#include "ServerForm.h"

#include <clocale>


using namespace System;
using namespace System::Threading;
using namespace System::Reflection;
using namespace System::Windows::Forms;
using namespace std;


//[assembly:AssemblyVersionAttribute("4.6.1")];

[STAThreadAttribute]

int main()
//int main (array＜String^＞^args )
{
	setlocale(LC_ALL, "ru");

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	ServerForm form;
	Application::Run(%form);
	
	return 0;
}


void ServerForm::MakeServer()
{
	int errorOnStart;
	thread_s = gcnew System::Threading::Thread(gcnew System::Threading::ThreadStart(this, &ServerForm::ReadDataServer));

	WORD wVersionRequired;
	WSADATA wsaData;

	wVersionRequired = MAKEWORD(2, 2);
	errorOnStart = WSAStartup(wVersionRequired, &wsaData);

	if (errorOnStart != 0)
	{
		System::Windows::Forms::MessageBox::Show("Произошла ошибка WSAGetLastError: " +
			WSAGetLastError().ToString());
		Close();
	}

	ServerSocketsBuf::server_socket = socket(AF_INET, SOCK_STREAM, 0);
	ServerSocketsBuf::client_socket = socket(AF_INET, SOCK_STREAM, 0);

	if (ServerSocketsBuf::server_socket == -1)
	{
		System::Windows::Forms::MessageBox::Show("Произошла ошибка WSAGetLastError: "
			+ WSAGetLastError().ToString());
		closesocket(ServerSocketsBuf::server_socket);
		WSACleanup();
		Close();
	}
	else {
		ServerForm::server_name->Text = L"SERVER 12345";
	}

	ServerSocketsBuf::s_in.sin_family = AF_INET;
	ServerSocketsBuf::s_in.sin_port = htons(27016);
	ServerSocketsBuf::s_in.sin_addr.S_un.S_addr = inet_addr("192.168.1.70"); // main PC's IP

	ServerSocketsBuf::failure = bind(ServerSocketsBuf::server_socket, (sockaddr*)&ServerSocketsBuf::s_in, sizeof(ServerSocketsBuf::s_in));
	if (ServerSocketsBuf::failure < 0)
	{
		System::Windows::Forms::MessageBox::Show("Произошла ошибка WSAGetLastError: " +
			WSAGetLastError().ToString());

		closesocket(ServerSocketsBuf::server_socket);
		WSACleanup();
		Close();
	}


	ServerSocketsBuf::failure = listen(ServerSocketsBuf::server_socket, SOMAXCONN);
	if (ServerSocketsBuf::failure < 0)
	{
		System::Windows::Forms::MessageBox::Show("Произошла ошибка WSAGetLastError: " +
			WSAGetLastError().ToString());

		closesocket(ServerSocketsBuf::server_socket);
		WSACleanup();
		Close();
	}

	ServerSocketsBuf::client_socket = accept(ServerSocketsBuf::server_socket, (sockaddr*)&ServerSocketsBuf::s_in, 0);

	if (ServerSocketsBuf::client_socket == SOCKET_ERROR)
	{
		System::Windows::Forms::MessageBox::Show("Произошла ошибка WSAGetLastError: " +
			WSAGetLastError().ToString());

		closesocket(ServerSocketsBuf::server_socket);
		WSACleanup();
		Close();
	}

	thread_s->Start();
}


void ServerForm::SendMsgToClient()
{
	marshal_context context;

	std::string msg = context.marshal_as<std::string>(tb1Server->Text);
	System::String ^message = marshal_as<String^>(msg);

	lb1Server->Items->Add(message);
	tb1Server->Clear();

	ServerSocketsBuf::failure = send(ServerSocketsBuf::client_socket, msg.c_str(), 512, 0);
	if (ServerSocketsBuf::failure < 0)
	{
		System::Windows::Forms::MessageBox::Show("Произошла ошибка WSAGetLastError: " +
			WSAGetLastError().ToString());
		closesocket(ServerSocketsBuf::client_socket);
		WSACleanup();
	}
	//throw gcnew System::NotImplementedException();
}

void ServerForm::ReadDataServer()
{
	do {
		ServerSocketsBuf::failure = recv(ServerSocketsBuf::client_socket, ServerSocketsBuf::recvbuf_server, 512, 0);
		if (ServerSocketsBuf::failure > 0) {
			System::String ^message_server = gcnew String(ServerSocketsBuf::recvbuf_server);
			lb1Server->Items->Add("Client 12345: " + message_server);
			SetDateTime();
		}
		else if (ServerSocketsBuf::failure == 0) {
			System::Windows::Forms::MessageBox::Show("Соединение завершено!");

		}
		/*else {

			System::Windows::Forms::MessageBox::Show("Клиент отключился или произошла ошибка WSAGetLastError: " +
				WSAGetLastError().ToString());
			Close();

		}*/
	} while (ServerSocketsBuf::failure > 0);
}

void ServerForm::Disconnect()
{	
			this->server_name->Text = L"Server's name";
			std::string server_msg_disconnect = "Server Disconnected";
			ServerSocketsBuf::failure = send(ServerSocketsBuf::client_socket, server_msg_disconnect.c_str(), 512, 0);
			if (ServerSocketsBuf::failure < 0)
			{
				System::Windows::Forms::MessageBox::Show("Произошла ошибка WSAGetLastError: " +
					WSAGetLastError().ToString());
				closesocket(ServerSocketsBuf::client_socket);
				WSACleanup();
			}
			
			closesocket(ServerSocketsBuf::client_socket);
			closesocket(ServerSocketsBuf::server_socket);
			WSACleanup();

			ServerSocketsBuf::client_socket = INVALID_SOCKET;
			ServerSocketsBuf::server_socket = INVALID_SOCKET;
	//throw gcnew System::NotImplementedException();
}

