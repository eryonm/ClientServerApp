#include "FormClient.h"
//#include "ServerForm.h"

using namespace System;
using namespace System::Globalization;
using namespace System::Reflection;
using namespace System::Windows::Forms;
using namespace std;




[STAThreadAttribute]

int main()
//int main (array＜String^＞^args )
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	FormClient form;
	Application::Run(%form);



	return 0;
}


void FormClient::FormClient::MakeClient()
{

	WORD wversionRequired;
	WSADATA wsadata;
	thread_c = gcnew System::Threading::Thread(gcnew System::Threading::ThreadStart(this, &FormClient::ReadDataClient));


	int err;

	wversionRequired = MAKEWORD(2, 2);
	err = WSAStartup(wversionRequired, &wsadata);

	if (err != 0)
	{
		System::Windows::Forms::MessageBox::Show("Произошла ошибка WSAGetLastError: " +
			WSAGetLastError().ToString());
		Close();
	}

	socketsclient::serversocket = socket(AF_INET, SOCK_STREAM, 0);
	socketsclient::clientsocket = socket(AF_INET, SOCK_STREAM, 0);

	if (socketsclient::serversocket == -1)
	{
		System::Windows::Forms::MessageBox::Show("Произошла ошибка WSAGetLastError: "
			+ WSAGetLastError().ToString());
		closesocket(socketsclient::serversocket);
		WSACleanup();
		Close();
	}

	socketsclient::cs_in.sin_family = AF_INET;
	socketsclient::cs_in.sin_port = htons(27016);
	socketsclient::cs_in.sin_addr.S_un.S_addr = inet_addr("192.168.1.70"); // main PC's IP

	socketsclient::failureC = connect(socketsclient::serversocket, (sockaddr*)&socketsclient::cs_in, sizeof(socketsclient::cs_in));
	if (socketsclient::failureC < 0)
	{
		System::Windows::Forms::MessageBox::Show("Произошла ошибка WSAGetLastError: " +
			WSAGetLastError().ToString());
		closesocket(socketsclient::clientsocket);
		WSACleanup();
		Close();
	}
	else {
		FormClient::label1->Text = L"CLIENT 12345";
	}

	thread_c->Start();

	//throw gcnew System::NotImplementedException();
}

void FormClient::ReadDataClient()
{

	do {
		socketsclient::failureC = recv(socketsclient::serversocket, socketsclient::recvbufC, 512, 0);
		if (socketsclient::failureC > 0) {
			System::String ^message_client = gcnew String(socketsclient::recvbufC);
			lb1Client->Items->Add("Server 12345: " + message_client);
			SetDateTime();
		}
		else if (socketsclient::failureC == 0) {
			System::Windows::Forms::MessageBox::Show("Соединение завершено!");
		}
		/*else {

			System::Windows::Forms::MessageBox::Show("Сервер отключился или произошла ошибка WSAGetLastError: " +
				WSAGetLastError().ToString());
			Close();
		}*/
	} while (socketsclient::failureC > 0);

}

void FormClient::SendMsgToServer()
{
	marshal_context context;

	std::string msg_client = context.marshal_as<std::string>(tb1Client->Text);
	System::String ^message_client = marshal_as<String^>(msg_client);

	lb1Client->Items->Add(message_client);
	tb1Client->Clear();

	socketsclient::failureC = send(socketsclient::serversocket, msg_client.c_str(), 512, 0);
	if (socketsclient::failureC < 0)
	{
		System::Windows::Forms::MessageBox::Show("Произошла ошибка WSAGetLastError: " +
			WSAGetLastError().ToString());
		closesocket(socketsclient::clientsocket);
		WSACleanup();
	}
}