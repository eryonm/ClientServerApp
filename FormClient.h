#pragma once
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <winsock2.h>
#include <msclr/marshal_cppstd.h>
using namespace System::Threading;
using namespace System::Runtime::InteropServices;
using namespace msclr::interop;
#pragma comment (lib, "ws2_32.lib")

namespace socketsclient{
	SOCKET serversocket; SOCKET clientsocket; char recvbufC[512];
	struct sockaddr_in cs_in; int failureC;
}



	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	
	/// <summary>
	/// Сводка для FormClient
	/// </summary>
	public ref class FormClient : public System::Windows::Forms::Form
	{
	public:
		FormClient(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

		System::Threading::Thread ^thread_c;

		void MakeClient();

		void ReadDataClient();
	
		void SendMsgToServer();
	

		void SetDateTime()
		{
			DateTimeOffset dto_client;

			System::String::Object^ dateobj_client = dto_client.UtcNow.AddHours(6);
			lb2Client->Items->Add(dateobj_client);
		}
	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~FormClient()
		{
			if (components)
			{
				
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  connect_client;
	private: System::Windows::Forms::Button^  sendmsg_client;
	protected:

	protected:

	protected:

	public: System::Windows::Forms::Label^  label1;
	public: System::Windows::Forms::ListBox^  lb1Client;
	public: System::Windows::Forms::ListBox^  lb2Client;
	private: System::Windows::Forms::TextBox^  tb1Client;
	public:



	private:


	private:

	private:


	private: System::Windows::Forms::Button^  disconnect_client;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->connect_client = (gcnew System::Windows::Forms::Button());
			this->sendmsg_client = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lb1Client = (gcnew System::Windows::Forms::ListBox());
			this->lb2Client = (gcnew System::Windows::Forms::ListBox());
			this->tb1Client = (gcnew System::Windows::Forms::TextBox());
			this->disconnect_client = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// connect_client
			// 
			this->connect_client->Font = (gcnew System::Drawing::Font(L"GOST Common", 9.749999F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->connect_client->Location = System::Drawing::Point(0, 0);
			this->connect_client->Margin = System::Windows::Forms::Padding(4);
			this->connect_client->Name = L"connect_client";
			this->connect_client->Size = System::Drawing::Size(100, 31);
			this->connect_client->TabIndex = 0;
			this->connect_client->Text = L"Connect";
			this->connect_client->UseVisualStyleBackColor = true;
			this->connect_client->Click += gcnew System::EventHandler(this, &FormClient::connect_client_Click);
			// 
			// sendmsg_client
			// 
			this->sendmsg_client->Font = (gcnew System::Drawing::Font(L"GOST Common", 9.749999F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->sendmsg_client->Location = System::Drawing::Point(574, 240);
			this->sendmsg_client->Margin = System::Windows::Forms::Padding(4);
			this->sendmsg_client->Name = L"sendmsg_client";
			this->sendmsg_client->Size = System::Drawing::Size(100, 54);
			this->sendmsg_client->TabIndex = 1;
			this->sendmsg_client->Text = L"Send";
			this->sendmsg_client->UseVisualStyleBackColor = true;
			this->sendmsg_client->Click += gcnew System::EventHandler(this, &FormClient::sendmsg_client_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(131, 31);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(86, 16);
			this->label1->TabIndex = 2;
			this->label1->Text = L"User\'s name";
			// 
			// lb1Client
			// 
			this->lb1Client->FormattingEnabled = true;
			this->lb1Client->HorizontalScrollbar = true;
			this->lb1Client->ItemHeight = 16;
			this->lb1Client->Location = System::Drawing::Point(123, 68);
			this->lb1Client->Margin = System::Windows::Forms::Padding(4);
			this->lb1Client->Name = L"lb1Client";
			this->lb1Client->ScrollAlwaysVisible = true;
			this->lb1Client->Size = System::Drawing::Size(551, 164);
			this->lb1Client->TabIndex = 3;
			// 
			// lb2Client
			// 
			this->lb2Client->FormattingEnabled = true;
			this->lb2Client->HorizontalScrollbar = true;
			this->lb2Client->ItemHeight = 16;
			this->lb2Client->Location = System::Drawing::Point(0, 68);
			this->lb2Client->Margin = System::Windows::Forms::Padding(4);
			this->lb2Client->Name = L"lb2Client";
			this->lb2Client->ScrollAlwaysVisible = true;
			this->lb2Client->Size = System::Drawing::Size(115, 164);
			this->lb2Client->TabIndex = 4;
			// 
			// tb1Client
			// 
			this->tb1Client->Location = System::Drawing::Point(0, 240);
			this->tb1Client->Margin = System::Windows::Forms::Padding(4);
			this->tb1Client->Multiline = true;
			this->tb1Client->Name = L"tb1Client";
			this->tb1Client->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->tb1Client->Size = System::Drawing::Size(573, 149);
			this->tb1Client->TabIndex = 5;
			this->tb1Client->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &FormClient::textBox1_KeyUp);
			// 
			// disconnect_client
			// 
			this->disconnect_client->Font = (gcnew System::Drawing::Font(L"GOST Common", 9.749999F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->disconnect_client->Location = System::Drawing::Point(0, 38);
			this->disconnect_client->Margin = System::Windows::Forms::Padding(4);
			this->disconnect_client->Name = L"disconnect_client";
			this->disconnect_client->Size = System::Drawing::Size(100, 28);
			this->disconnect_client->TabIndex = 6;
			this->disconnect_client->Text = L"Disconnect";
			this->disconnect_client->UseVisualStyleBackColor = true;
			this->disconnect_client->Click += gcnew System::EventHandler(this, &FormClient::disconnect_client_Click);
			// 
			// FormClient
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(675, 390);
			this->Controls->Add(this->disconnect_client);
			this->Controls->Add(this->tb1Client);
			this->Controls->Add(this->lb2Client);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->sendmsg_client);
			this->Controls->Add(this->connect_client);
			this->Controls->Add(this->lb1Client);
			this->Font = (gcnew System::Drawing::Font(L"Ink Free", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(4);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"FormClient";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FormClient";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	private: System::Void connect_client_Click(System::Object^  sender, System::EventArgs^  e) {
		MakeClient();
		
	}
	private: System::Void disconnect_client_Click(System::Object^  sender, System::EventArgs^  e) {
		this->label1->Text = L"User's name";
		std::string client_msg_disconnect = "Disconnected";
		socketsclient::failureC = send(socketsclient::serversocket, client_msg_disconnect.c_str(), 512, 0);
		if (socketsclient::failureC < 0)
		{
			System::Windows::Forms::MessageBox::Show("Произошла ошибка WSAGetLastError: " +
				WSAGetLastError().ToString());
			closesocket(socketsclient::clientsocket);
			WSACleanup();
		}
		SetDateTime();
		thread_c->Abort();

		closesocket(socketsclient::serversocket);
		closesocket(socketsclient::clientsocket);
		WSACleanup();
		socketsclient::clientsocket = INVALID_SOCKET;
		socketsclient::serversocket = INVALID_SOCKET;

	}
private: System::Void sendmsg_client_Click(System::Object^  sender, System::EventArgs^  e) {

	SendMsgToServer();
	SetDateTime();
}

		 private: System::Void textBox1_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {

			 if (e->KeyCode == Keys::Enter)
			 {
				 sendmsg_client_Click(sender, e);
			 }
		 }
};


