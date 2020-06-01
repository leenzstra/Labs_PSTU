#pragma once

namespace Calc {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Error : public System::Windows::Forms::Form
	{
	public:
		Error(bool night, String^ e)
		{
			InitializeComponent();
			nightmode = night;
			error = e;
		}

	protected:

		~Error()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ ErrorOK;
	private: System::Windows::Forms::Label^ LabelError;
	private: System::Windows::Forms::Timer^ ErrorTimer;
	private: System::ComponentModel::IContainer^ components;
	private: System::Windows::Forms::Panel^ PanelError2;
	private: System::Windows::Forms::Timer^ redTimer;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Timer^ nonredTimer;

		void nightmodeYes()
		{
			Error::ForeColor = Color::White;
			ErrorOK->BackColor = PrimaryDark;
			this->BackColor = PrimaryDark;
			PanelError2->BackColor = ThemeColor;
		}
		void nightmodeNo()
		{
			Error::ForeColor = Color::Black;
			ErrorOK->BackColor = PrimaryLight;
			this->BackColor = PrimaryLight;
			PanelError2->BackColor = ThemeColor;
		}


#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Error::typeid));
			this->ErrorOK = (gcnew System::Windows::Forms::Button());
			this->LabelError = (gcnew System::Windows::Forms::Label());
			this->ErrorTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->PanelError2 = (gcnew System::Windows::Forms::Panel());
			this->redTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->nonredTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// ErrorOK
			// 
			this->ErrorOK->BackColor = System::Drawing::Color::White;
			this->ErrorOK->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ErrorOK.BackgroundImage")));
			this->ErrorOK->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ErrorOK->FlatAppearance->BorderSize = 0;
			this->ErrorOK->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ErrorOK->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ErrorOK->Location = System::Drawing::Point(149, 157);
			this->ErrorOK->Margin = System::Windows::Forms::Padding(0);
			this->ErrorOK->Name = L"ErrorOK";
			this->ErrorOK->Size = System::Drawing::Size(100, 30);
			this->ErrorOK->TabIndex = 9;
			this->ErrorOK->UseVisualStyleBackColor = false;
			this->ErrorOK->Click += gcnew System::EventHandler(this, &Error::ErrorOK_Click);
			// 
			// LabelError
			// 
			this->LabelError->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->LabelError->BackColor = System::Drawing::Color::Transparent;
			this->LabelError->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->LabelError->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->LabelError->Location = System::Drawing::Point(3, 75);
			this->LabelError->Name = L"LabelError";
			this->LabelError->Size = System::Drawing::Size(394, 48);
			this->LabelError->TabIndex = 10;
			this->LabelError->Text = L"Error";
			this->LabelError->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// ErrorTimer
			// 
			this->ErrorTimer->Interval = 5;
			this->ErrorTimer->Tick += gcnew System::EventHandler(this, &Error::ErrorTimer_Tick);
			// 
			// PanelError2
			// 
			this->PanelError2->BackColor = System::Drawing::Color::Black;
			this->PanelError2->Dock = System::Windows::Forms::DockStyle::Top;
			this->PanelError2->Location = System::Drawing::Point(0, 0);
			this->PanelError2->Name = L"PanelError2";
			this->PanelError2->Size = System::Drawing::Size(400, 5);
			this->PanelError2->TabIndex = 14;
			// 
			// redTimer
			// 
			this->redTimer->Interval = 1;
			this->redTimer->Tick += gcnew System::EventHandler(this, &Error::redTimer_Tick);
			// 
			// nonredTimer
			// 
			this->nonredTimer->Interval = 1;
			this->nonredTimer->Tick += gcnew System::EventHandler(this, &Error::nonredTimer_Tick);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial Black", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(12, 17);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(108, 30);
			this->label2->TabIndex = 43;
			this->label2->Text = L"Îøèáêà";
			// 
			// Error
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(400, 223);
			this->ControlBox = false;
			this->Controls->Add(this->label2);
			this->Controls->Add(this->PanelError2);
			this->Controls->Add(this->LabelError);
			this->Controls->Add(this->ErrorOK);
			this->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Error";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Error";
			this->TopMost = true;
			this->Load += gcnew System::EventHandler(this, &Error::Error_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		Color SecondaryDark = Color::FromArgb(53, 60, 71);	//blackier
		Color PrimaryDark = Color::FromArgb(62, 69, 83);	//not much black
		Color SecondaryLight = Color::FromArgb(255, 255, 255);	//light
		Color ThemeColor = Color::FromArgb(126, 20, 255);	//blue
		Color PrimaryLight = Color::FromArgb(246, 250, 253); //whiter

		bool nightmode = false;
		int red;
		int nonred;
		int i;

		String^ error = "Error";

	private: System::Void Error_Load(System::Object^ sender, System::EventArgs^ e) 
	{

		if (nightmode)
			nightmodeYes();
		else
			nightmodeNo();
		LabelError->Text = error;
		this->Opacity = 1;
		red = 255;
		nonred = 0;
		i = 0;
		redTimer->Start();
		
	}
	private: System::Void ErrorOK_Click(System::Object^ sender, System::EventArgs^ e)
	{
		ErrorTimer->Start();
	}
	private: System::Void ErrorTimer_Tick(System::Object^ sender, System::EventArgs^ e)
	{
		this->Opacity -= 0.1;
		if (this->Opacity == 0)
		{
			ErrorTimer->Stop();
			this->Close();
		}
	}

	private: System::Void redTimer_Tick(System::Object^ sender, System::EventArgs^ e)
	{
		if (nightmode)
		{
			nonred += 15;
			PanelError2->BackColor = Color::FromArgb(nonred, 0, 0);
			if (nonred == 255)
			{
				redTimer->Stop();
				nonredTimer->Start();
				nonred = 0;
			}
		}
		else
		{
			red -= 15;
			PanelError2->BackColor = Color::FromArgb(245, red, red);
			if (red == 0)
			{
				redTimer->Stop();
				red = 255;
				i++;
				if (i < 3)
					nonredTimer->Start();
			}
		}
	}
	private: System::Void nonredTimer_Tick(System::Object^ sender, System::EventArgs^ e)
	{
		if (nightmode) 
		{
			red -= 15;
			PanelError2->BackColor = Color::FromArgb(red, 0, 0);

			if (red == 0)
			{
				nonredTimer->Stop();
				red = 255;
				i++;
				if (i < 2)
					redTimer->Start();
				else
					PanelError2->BackColor = ThemeColor;
			}
		}
		else
		{
			nonred += 15;
			PanelError2->BackColor = Color::FromArgb(245, nonred, nonred);

			if (nonred == 240)
			{
				nonredTimer->Stop();
				if (i < 2)
					redTimer->Start();
				else
					PanelError2->BackColor = ThemeColor;
				nonred = 0;
			}
		}
	}
};
}
