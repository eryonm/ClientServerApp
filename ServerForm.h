#pragma once
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <winsock2.h>
#include <msclr/marshal_cppstd.h>
#include <string>
#pragma comment (lib, "ws2_32.lib")

namespace ServerSocketsBuf {
	SOCKET server_socket; SOCKET client_socket;
	char recvbuf_server[512];
	struct sockaddr_in s_in; int failure;

}



	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;
	using namespace msclr::interop;
	

	/// <summary>
	/// —водка дл€ ServerForm
	/// </summary>
	public ref class ServerForm : public System::Windows::Forms::Form
	{
	public:
		ServerForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
	


	
	public: System::Threading::Thread ^thread_s;

			
			void MakeServer();
			void SendMsgToClient();
			void ReadDataServer();
			void Disconnect();


		void SetDateTime()
		{
			DateTimeOffset dto;

			System::String::Object^ dateobj = dto.UtcNow.AddHours(6);
			lb2Server->Items->Add(dateobj);
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~ServerForm()
		{
			if (components)
			{

				delete components;
			}
		}
	private: System::Windows::Forms::Button^  connect_server;
	private: System::Windows::Forms::Button^  sendmsg_server;
	protected:



	public: System::Windows::Forms::ListBox^  lb1Server;
	private: System::Windows::Forms::ListBox^  lb2Server;
	public:
	private:
	public:

	protected:



	public: System::Windows::Forms::Label^  server_name;
	private: System::Windows::Forms::TextBox^  tb1Server;
	public:


	private: System::Windows::Forms::Button^  disconnect_server;

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->connect_server = (gcnew System::Windows::Forms::Button());
			this->sendmsg_server = (gcnew System::Windows::Forms::Button());
			this->lb1Server = (gcnew System::Windows::Forms::ListBox());
			this->lb2Server = (gcnew System::Windows::Forms::ListBox());
			this->server_name = (gcnew System::Windows::Forms::Label());
			this->tb1Server = (gcnew System::Windows::Forms::TextBox());
			this->disconnect_server = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// connect_server
			// 
			this->connect_server->Location = System::Drawing::Point(0, 1);
			this->connect_server->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->connect_server->Name = L"connect_server";
			this->connect_server->Size = System::Drawing::Size(88, 32);
			this->connect_server->TabIndex = 0;
			this->connect_server->Text = L"Connect";
			this->connect_server->UseVisualStyleBackColor = true;
			this->connect_server->Click += gcnew System::EventHandler(this, &ServerForm::connect_w_client_Click);
			// 
			// sendmsg_server
			// 
			this->sendmsg_server->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->sendmsg_server->Location = System::Drawing::Point(651, 250);
			this->sendmsg_server->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->sendmsg_server->Name = L"sendmsg_server";
			this->sendmsg_server->Size = System::Drawing::Size(88, 34);
			this->sendmsg_server->TabIndex = 1;
			this->sendmsg_server->Text = L"Send";
			this->sendmsg_server->UseVisualStyleBackColor = true;
			this->sendmsg_server->Click += gcnew System::EventHandler(this, &ServerForm::sendmsg_server_Click);
			// 
			// lb1Server
			// 
			this->lb1Server->FormattingEnabled = true;
			this->lb1Server->HorizontalScrollbar = true;
			this->lb1Server->ItemHeight = 16;
			this->lb1Server->Location = System::Drawing::Point(132, 86);
			this->lb1Server->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->lb1Server->Name = L"lb1Server";
			this->lb1Server->ScrollAlwaysVisible = true;
			this->lb1Server->Size = System::Drawing::Size(607, 164);
			this->lb1Server->TabIndex = 2;
			// 
			// lb2Server
			// 
			this->lb2Server->FormattingEnabled = true;
			this->lb2Server->HorizontalScrollbar = true;
			this->lb2Server->ItemHeight = 16;
			this->lb2Server->Location = System::Drawing::Point(0, 86);
			this->lb2Server->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->lb2Server->Name = L"lb2Server";
			this->lb2Server->ScrollAlwaysVisible = true;
			this->lb2Server->Size = System::Drawing::Size(132, 164);
			this->lb2Server->TabIndex = 3;
			// 
			// server_name
			// 
			this->server_name->AutoSize = true;
			this->server_name->Location = System::Drawing::Point(96, 28);
			this->server_name->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->server_name->Name = L"server_name";
			this->server_name->Size = System::Drawing::Size(85, 16);
			this->server_name->TabIndex = 4;
			this->server_name->Text = L"Server\'s name";
			// 
			// tb1Server
			// 
			this->tb1Server->Location = System::Drawing::Point(0, 250);
			this->tb1Server->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->tb1Server->Multiline = true;
			this->tb1Server->Name = L"tb1Server";
			this->tb1Server->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->tb1Server->Size = System::Drawing::Size(643, 147);
			this->tb1Server->TabIndex = 5;
			this->tb1Server->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &ServerForm::textBox1_KeyUp);
			// 
			// disconnect_server
			// 
			this->disconnect_server->Location = System::Drawing::Point(0, 39);
			this->disconnect_server->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->disconnect_server->Name = L"disconnect_server";
			this->disconnect_server->Size = System::Drawing::Size(88, 29);
			this->disconnect_server->TabIndex = 6;
			this->disconnect_server->Text = L"Disconnect";
			this->disconnect_server->UseVisualStyleBackColor = true;
			this->disconnect_server->Click += gcnew System::EventHandler(this, &ServerForm::disconnect_server_Click);
			// 
			// ServerForm
			// 
			this->AllowDrop = true;
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(739, 397);
			this->Controls->Add(this->disconnect_server);
			this->Controls->Add(this->tb1Server);
			this->Controls->Add(this->server_name);
			this->Controls->Add(this->lb2Server);
			this->Controls->Add(this->lb1Server);
			this->Controls->Add(this->sendmsg_server);
			this->Controls->Add(this->connect_server);
			this->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ForeColor = System::Drawing::Color::Black;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"ServerForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"ServerForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public: System::Void sendmsg_server_Click(System::Object^  sender, System::EventArgs^  e)
	{
		SendMsgToClient();
		SetDateTime();

	}
	private: System::Void connect_w_client_Click(System::Object^  sender, System::EventArgs^  e) {

		MakeServer();
	}

	private: System::Void disconnect_server_Click(System::Object^  sender, System::EventArgs^  e) {
		Disconnect();
		thread_s->Abort();
	}
	private: System::Void textBox1_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {

		if (e->KeyCode == Keys::Enter)
		{
			sendmsg_server_Click(sender, e);
		}
	}

};

