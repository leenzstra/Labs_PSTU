#pragma once
#include "SplashScreen.h"
#include "Error.h"
#include "history.h"
#include "mathBase.h"
#include "complexCoeff.h"
#include <string>
#include <msclr/marshal_cppstd.h>
#include <fstream>

namespace Calc {
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	public ref class CalcForm : public System::Windows::Forms::Form
	{
	public:
		CalcForm(void)
		{
			InitializeComponent();
		}
	protected:
		~CalcForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Timer^ timer2;
	private: System::ComponentModel::IContainer^ components;
	private: System::Windows::Forms::Button^ butClose;
	private: System::Windows::Forms::TextBox^ BoxA;
	private: System::Windows::Forms::TextBox^ BoxB;
	private: System::Windows::Forms::TextBox^ BoxC;
	private: System::Windows::Forms::TextBox^ BoxX2;
	private: System::Windows::Forms::TextBox^ BoxX1;
	private: System::Windows::Forms::Button^ SolveButton;
	private: System::Windows::Forms::PictureBox^ nightModePic;
	private: System::Windows::Forms::Timer^ timer3;
	private: System::Windows::Forms::Timer^ timer4;
	private: System::Windows::Forms::TextBox^ historyBox;
	private: System::Windows::Forms::PictureBox^ dayModePic;
	private: System::Windows::Forms::Button^ butMinimize;
	private: System::Windows::Forms::Button^ butClear;
	private: System::Windows::Forms::Panel^ greenPanel;
	private: System::Windows::Forms::Timer^ HelpTimer;
	private: System::Windows::Forms::Label^ HelpLabel;
	private: System::Windows::Forms::Panel^ staticPanel;
	private: System::Windows::Forms::Panel^ openerPanel;
	private: System::Windows::Forms::Button^ helpButton;
	private: System::Windows::Forms::Panel^ clearPanel;
	private: System::Windows::Forms::Timer^ ClearTimer;
	private: System::Windows::Forms::Panel^ ClearPanelDynamic;
	private: System::Windows::Forms::Panel^ ClearPanelStatic;
	private: System::Windows::Forms::Timer^ DynamicClearTimer;
	private: System::Windows::Forms::Label^ labelX2;
	private: System::Windows::Forms::Label^ labelX;
	private: System::Windows::Forms::Label^ label0;
	private: System::Windows::Forms::Button^ clearInputButton;
	private: System::Windows::Forms::Label^ sqr;
	private: System::Windows::Forms::Panel^ progressPanel;
	private: System::Windows::Forms::PictureBox^ progressPic;
	private: System::Windows::Forms::Timer^ ProgressTimer;
	private: System::Windows::Forms::TextBox^ boxDiscr;
	private: System::Windows::Forms::PictureBox^ boxRed;
	private: System::Windows::Forms::PictureBox^ boxBlue;
	private: System::Windows::Forms::PictureBox^ boxGreen;
	private: System::Windows::Forms::Label^ colorsLabel;
	private: System::Windows::Forms::Panel^ progressOpenerPanel;
	private: System::Windows::Forms::Label^ RootLabel;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Timer^ HeaderTimer;
	private: System::Windows::Forms::Label^ HeaderLabel4;
	private: System::Windows::Forms::Label^ HeaderLabel3;
	private: System::Windows::Forms::Label^ HeaderLabel2;
	private: System::Windows::Forms::Label^ HeaderLabel1;
	private: System::Windows::Forms::Panel^ HeaderPanelUp;
	private: System::Windows::Forms::Panel^ LeftPanel;
	private: System::Windows::Forms::PictureBox^ ProgressPicBlack;
	private: System::Windows::Forms::PictureBox^ ProgressPicBlue;
	private: System::Windows::Forms::Button^ buttonMenu;
	private: System::Windows::Forms::PictureBox^ TipPic;
	private: System::Windows::Forms::Label^ TipLabel;
	private: System::Windows::Forms::RadioButton^ complexSwitcher1;
	private: System::Windows::Forms::RadioButton^ complexSwitcher2;
	private: System::Windows::Forms::Label^ HelpLabel2;
	private: System::Windows::Forms::Panel^ HeaderDynamicPanel;
	private: System::Windows::Forms::Panel^ HeaderPanel;
	private: System::Windows::Forms::Panel^ panelQuadric;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::PictureBox^ checkPic;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ histLabel;
	private: System::Windows::Forms::Panel^ ActiveModePanel;
	private: System::Windows::Forms::Label^ SolvedLabel;
	private: System::Windows::Forms::Label^ SolvedNumLabel;
	private: System::Windows::Forms::Splitter^ splitter1;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(CalcForm::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->HeaderPanel = (gcnew System::Windows::Forms::Panel());
			this->HeaderLabel4 = (gcnew System::Windows::Forms::Label());
			this->HeaderLabel3 = (gcnew System::Windows::Forms::Label());
			this->HeaderLabel2 = (gcnew System::Windows::Forms::Label());
			this->HeaderLabel1 = (gcnew System::Windows::Forms::Label());
			this->butClose = (gcnew System::Windows::Forms::Button());
			this->butMinimize = (gcnew System::Windows::Forms::Button());
			this->helpButton = (gcnew System::Windows::Forms::Button());
			this->dayModePic = (gcnew System::Windows::Forms::PictureBox());
			this->nightModePic = (gcnew System::Windows::Forms::PictureBox());
			this->BoxA = (gcnew System::Windows::Forms::TextBox());
			this->BoxB = (gcnew System::Windows::Forms::TextBox());
			this->BoxC = (gcnew System::Windows::Forms::TextBox());
			this->BoxX2 = (gcnew System::Windows::Forms::TextBox());
			this->BoxX1 = (gcnew System::Windows::Forms::TextBox());
			this->SolveButton = (gcnew System::Windows::Forms::Button());
			this->timer3 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer4 = (gcnew System::Windows::Forms::Timer(this->components));
			this->historyBox = (gcnew System::Windows::Forms::TextBox());
			this->butClear = (gcnew System::Windows::Forms::Button());
			this->HelpLabel = (gcnew System::Windows::Forms::Label());
			this->greenPanel = (gcnew System::Windows::Forms::Panel());
			this->HelpTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->staticPanel = (gcnew System::Windows::Forms::Panel());
			this->openerPanel = (gcnew System::Windows::Forms::Panel());
			this->boxRed = (gcnew System::Windows::Forms::PictureBox());
			this->boxBlue = (gcnew System::Windows::Forms::PictureBox());
			this->boxGreen = (gcnew System::Windows::Forms::PictureBox());
			this->colorsLabel = (gcnew System::Windows::Forms::Label());
			this->HelpLabel2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->clearPanel = (gcnew System::Windows::Forms::Panel());
			this->ClearTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->ClearPanelDynamic = (gcnew System::Windows::Forms::Panel());
			this->ClearPanelStatic = (gcnew System::Windows::Forms::Panel());
			this->DynamicClearTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->labelX2 = (gcnew System::Windows::Forms::Label());
			this->labelX = (gcnew System::Windows::Forms::Label());
			this->label0 = (gcnew System::Windows::Forms::Label());
			this->clearInputButton = (gcnew System::Windows::Forms::Button());
			this->sqr = (gcnew System::Windows::Forms::Label());
			this->progressPanel = (gcnew System::Windows::Forms::Panel());
			this->progressOpenerPanel = (gcnew System::Windows::Forms::Panel());
			this->ProgressPicBlue = (gcnew System::Windows::Forms::PictureBox());
			this->ProgressPicBlack = (gcnew System::Windows::Forms::PictureBox());
			this->progressPic = (gcnew System::Windows::Forms::PictureBox());
			this->ProgressTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->boxDiscr = (gcnew System::Windows::Forms::TextBox());
			this->RootLabel = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->HeaderTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->HeaderPanelUp = (gcnew System::Windows::Forms::Panel());
			this->TipPic = (gcnew System::Windows::Forms::PictureBox());
			this->TipLabel = (gcnew System::Windows::Forms::Label());
			this->HeaderDynamicPanel = (gcnew System::Windows::Forms::Panel());
			this->buttonMenu = (gcnew System::Windows::Forms::Button());
			this->complexSwitcher2 = (gcnew System::Windows::Forms::RadioButton());
			this->complexSwitcher1 = (gcnew System::Windows::Forms::RadioButton());
			this->LeftPanel = (gcnew System::Windows::Forms::Panel());
			this->panelQuadric = (gcnew System::Windows::Forms::Panel());
			this->checkPic = (gcnew System::Windows::Forms::PictureBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->splitter1 = (gcnew System::Windows::Forms::Splitter());
			this->histLabel = (gcnew System::Windows::Forms::Label());
			this->ActiveModePanel = (gcnew System::Windows::Forms::Panel());
			this->SolvedLabel = (gcnew System::Windows::Forms::Label());
			this->SolvedNumLabel = (gcnew System::Windows::Forms::Label());
			this->HeaderPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dayModePic))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nightModePic))->BeginInit();
			this->staticPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->boxRed))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->boxBlue))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->boxGreen))->BeginInit();
			this->ClearPanelStatic->SuspendLayout();
			this->progressPanel->SuspendLayout();
			this->progressOpenerPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ProgressPicBlue))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ProgressPicBlack))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->progressPic))->BeginInit();
			this->HeaderPanelUp->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TipPic))->BeginInit();
			this->LeftPanel->SuspendLayout();
			this->panelQuadric->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->checkPic))->BeginInit();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &CalcForm::timerMinimize_Tick);
			// 
			// timer2
			// 
			this->timer2->Tick += gcnew System::EventHandler(this, &CalcForm::timerClose_Tick);
			// 
			// HeaderPanel
			// 
			this->HeaderPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(232)), static_cast<System::Int32>(static_cast<System::Byte>(252)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->HeaderPanel->Controls->Add(this->HeaderLabel4);
			this->HeaderPanel->Controls->Add(this->HeaderLabel3);
			this->HeaderPanel->Controls->Add(this->HeaderLabel2);
			this->HeaderPanel->Controls->Add(this->HeaderLabel1);
			this->HeaderPanel->Controls->Add(this->butClose);
			this->HeaderPanel->Controls->Add(this->butMinimize);
			this->HeaderPanel->Controls->Add(this->helpButton);
			this->HeaderPanel->Controls->Add(this->dayModePic);
			this->HeaderPanel->Controls->Add(this->nightModePic);
			this->HeaderPanel->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->HeaderPanel->Dock = System::Windows::Forms::DockStyle::Right;
			this->HeaderPanel->Location = System::Drawing::Point(0, 0);
			this->HeaderPanel->Margin = System::Windows::Forms::Padding(2);
			this->HeaderPanel->Name = L"HeaderPanel";
			this->HeaderPanel->Size = System::Drawing::Size(60, 720);
			this->HeaderPanel->TabIndex = 2;
			// 
			// HeaderLabel4
			// 
			this->HeaderLabel4->BackColor = System::Drawing::Color::Transparent;
			this->HeaderLabel4->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Bold));
			this->HeaderLabel4->Location = System::Drawing::Point(61, 681);
			this->HeaderLabel4->Name = L"HeaderLabel4";
			this->HeaderLabel4->Size = System::Drawing::Size(92, 26);
			this->HeaderLabel4->TabIndex = 44;
			this->HeaderLabel4->Text = L"Закрыть";
			this->HeaderLabel4->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// HeaderLabel3
			// 
			this->HeaderLabel3->BackColor = System::Drawing::Color::Transparent;
			this->HeaderLabel3->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Bold));
			this->HeaderLabel3->Location = System::Drawing::Point(65, 622);
			this->HeaderLabel3->Name = L"HeaderLabel3";
			this->HeaderLabel3->Size = System::Drawing::Size(83, 21);
			this->HeaderLabel3->TabIndex = 43;
			this->HeaderLabel3->Text = L"Скрыть";
			this->HeaderLabel3->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// HeaderLabel2
			// 
			this->HeaderLabel2->BackColor = System::Drawing::Color::Transparent;
			this->HeaderLabel2->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->HeaderLabel2->Location = System::Drawing::Point(60, 559);
			this->HeaderLabel2->Name = L"HeaderLabel2";
			this->HeaderLabel2->Size = System::Drawing::Size(93, 21);
			this->HeaderLabel2->TabIndex = 42;
			this->HeaderLabel2->Text = L"Помощь";
			this->HeaderLabel2->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// HeaderLabel1
			// 
			this->HeaderLabel1->BackColor = System::Drawing::Color::Transparent;
			this->HeaderLabel1->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->HeaderLabel1->Location = System::Drawing::Point(63, 28);
			this->HeaderLabel1->Name = L"HeaderLabel1";
			this->HeaderLabel1->Size = System::Drawing::Size(72, 26);
			this->HeaderLabel1->TabIndex = 41;
			this->HeaderLabel1->Text = L"Тема";
			this->HeaderLabel1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// butClose
			// 
			this->butClose->BackColor = System::Drawing::Color::Transparent;
			this->butClose->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"butClose.BackgroundImage")));
			this->butClose->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->butClose->FlatAppearance->BorderSize = 0;
			this->butClose->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->butClose->Location = System::Drawing::Point(14, 678);
			this->butClose->Name = L"butClose";
			this->butClose->Size = System::Drawing::Size(32, 32);
			this->butClose->TabIndex = 10;
			this->butClose->UseVisualStyleBackColor = false;
			this->butClose->Click += gcnew System::EventHandler(this, &CalcForm::buttonCloseWindow_Click);
			// 
			// butMinimize
			// 
			this->butMinimize->BackColor = System::Drawing::Color::Transparent;
			this->butMinimize->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"butMinimize.BackgroundImage")));
			this->butMinimize->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->butMinimize->FlatAppearance->BorderSize = 0;
			this->butMinimize->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->butMinimize->Location = System::Drawing::Point(14, 622);
			this->butMinimize->Name = L"butMinimize";
			this->butMinimize->Size = System::Drawing::Size(32, 32);
			this->butMinimize->TabIndex = 11;
			this->butMinimize->UseVisualStyleBackColor = false;
			this->butMinimize->Click += gcnew System::EventHandler(this, &CalcForm::buttonMinimizeWindow_Click);
			// 
			// helpButton
			// 
			this->helpButton->BackColor = System::Drawing::Color::Transparent;
			this->helpButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"helpButton.BackgroundImage")));
			this->helpButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->helpButton->FlatAppearance->BorderSize = 0;
			this->helpButton->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->helpButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->helpButton->Location = System::Drawing::Point(14, 563);
			this->helpButton->Name = L"helpButton";
			this->helpButton->Size = System::Drawing::Size(32, 32);
			this->helpButton->TabIndex = 12;
			this->helpButton->UseVisualStyleBackColor = false;
			this->helpButton->Click += gcnew System::EventHandler(this, &CalcForm::buttonHelp_Click);
			// 
			// dayModePic
			// 
			this->dayModePic->BackColor = System::Drawing::Color::Transparent;
			this->dayModePic->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"dayModePic.BackgroundImage")));
			this->dayModePic->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->dayModePic->Location = System::Drawing::Point(13, 12);
			this->dayModePic->Name = L"dayModePic";
			this->dayModePic->Size = System::Drawing::Size(32, 32);
			this->dayModePic->TabIndex = 10;
			this->dayModePic->TabStop = false;
			this->dayModePic->Visible = false;
			this->dayModePic->Click += gcnew System::EventHandler(this, &CalcForm::dayModePic_Click);
			// 
			// nightModePic
			// 
			this->nightModePic->BackColor = System::Drawing::Color::Transparent;
			this->nightModePic->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"nightModePic.BackgroundImage")));
			this->nightModePic->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->nightModePic->Location = System::Drawing::Point(13, 12);
			this->nightModePic->Name = L"nightModePic";
			this->nightModePic->Size = System::Drawing::Size(32, 32);
			this->nightModePic->TabIndex = 9;
			this->nightModePic->TabStop = false;
			this->nightModePic->Click += gcnew System::EventHandler(this, &CalcForm::nightModePic_Click);
			// 
			// BoxA
			// 
			this->BoxA->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(252)), static_cast<System::Int32>(static_cast<System::Byte>(236)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->BoxA->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->BoxA->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->BoxA->Location = System::Drawing::Point(46, 94);
			this->BoxA->Name = L"BoxA";
			this->BoxA->Size = System::Drawing::Size(170, 24);
			this->BoxA->TabIndex = 3;
			this->BoxA->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->BoxA->TextChanged += gcnew System::EventHandler(this, &CalcForm::BoxA_TextChanged);
			// 
			// BoxB
			// 
			this->BoxB->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(252)), static_cast<System::Int32>(static_cast<System::Byte>(236)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->BoxB->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->BoxB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->BoxB->Location = System::Drawing::Point(297, 94);
			this->BoxB->Name = L"BoxB";
			this->BoxB->Size = System::Drawing::Size(170, 24);
			this->BoxB->TabIndex = 4;
			this->BoxB->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->BoxB->TextChanged += gcnew System::EventHandler(this, &CalcForm::BoxB_TextChanged);
			// 
			// BoxC
			// 
			this->BoxC->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(252)), static_cast<System::Int32>(static_cast<System::Byte>(236)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->BoxC->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->BoxC->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->BoxC->Location = System::Drawing::Point(527, 93);
			this->BoxC->Name = L"BoxC";
			this->BoxC->Size = System::Drawing::Size(170, 24);
			this->BoxC->TabIndex = 5;
			this->BoxC->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->BoxC->TextChanged += gcnew System::EventHandler(this, &CalcForm::BoxC_TextChanged);
			// 
			// BoxX2
			// 
			this->BoxX2->BackColor = System::Drawing::Color::WhiteSmoke;
			this->BoxX2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->BoxX2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->BoxX2->Location = System::Drawing::Point(127, 233);
			this->BoxX2->Name = L"BoxX2";
			this->BoxX2->ReadOnly = true;
			this->BoxX2->Size = System::Drawing::Size(264, 24);
			this->BoxX2->TabIndex = 6;
			// 
			// BoxX1
			// 
			this->BoxX1->BackColor = System::Drawing::Color::WhiteSmoke;
			this->BoxX1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->BoxX1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->BoxX1->Location = System::Drawing::Point(127, 171);
			this->BoxX1->Name = L"BoxX1";
			this->BoxX1->ReadOnly = true;
			this->BoxX1->Size = System::Drawing::Size(264, 24);
			this->BoxX1->TabIndex = 7;
			// 
			// SolveButton
			// 
			this->SolveButton->BackColor = System::Drawing::Color::Transparent;
			this->SolveButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"SolveButton.BackgroundImage")));
			this->SolveButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->SolveButton->FlatAppearance->BorderSize = 0;
			this->SolveButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->SolveButton->Font = (gcnew System::Drawing::Font(L"Arial", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->SolveButton->Location = System::Drawing::Point(177, 353);
			this->SolveButton->Name = L"SolveButton";
			this->SolveButton->Size = System::Drawing::Size(150, 45);
			this->SolveButton->TabIndex = 8;
			this->SolveButton->UseVisualStyleBackColor = false;
			this->SolveButton->Click += gcnew System::EventHandler(this, &CalcForm::Solve_Click);
			// 
			// timer3
			// 
			this->timer3->Tick += gcnew System::EventHandler(this, &CalcForm::timerThemeChange_Tick);
			// 
			// timer4
			// 
			this->timer4->Tick += gcnew System::EventHandler(this, &CalcForm::timerThemeChange2_Tick);
			// 
			// historyBox
			// 
			this->historyBox->BackColor = System::Drawing::Color::White;
			this->historyBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->historyBox->Cursor = System::Windows::Forms::Cursors::Hand;
			this->historyBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->historyBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->historyBox->Location = System::Drawing::Point(0, 0);
			this->historyBox->Multiline = true;
			this->historyBox->Name = L"historyBox";
			this->historyBox->ReadOnly = true;
			this->historyBox->Size = System::Drawing::Size(330, 525);
			this->historyBox->TabIndex = 9;
			// 
			// butClear
			// 
			this->butClear->BackColor = System::Drawing::Color::Transparent;
			this->butClear->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"butClear.BackgroundImage")));
			this->butClear->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->butClear->FlatAppearance->BorderSize = 0;
			this->butClear->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->butClear->Location = System::Drawing::Point(1127, 93);
			this->butClear->Name = L"butClear";
			this->butClear->Size = System::Drawing::Size(100, 30);
			this->butClear->TabIndex = 12;
			this->butClear->UseVisualStyleBackColor = false;
			this->butClear->Click += gcnew System::EventHandler(this, &CalcForm::buttonHistoryClear_Click);
			// 
			// HelpLabel
			// 
			this->HelpLabel->BackColor = System::Drawing::Color::Transparent;
			this->HelpLabel->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->HelpLabel->Font = (gcnew System::Drawing::Font(L"Arial", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->HelpLabel->ForeColor = System::Drawing::Color::Black;
			this->HelpLabel->Location = System::Drawing::Point(106, 20);
			this->HelpLabel->Name = L"HelpLabel";
			this->HelpLabel->Size = System::Drawing::Size(538, 39);
			this->HelpLabel->TabIndex = 17;
			this->HelpLabel->Text = L"                                     Действительные                          Комп"
				L"лексные\r\n                                      коэффициенты                     "
				L"     коэффициенты";
			// 
			// greenPanel
			// 
			this->greenPanel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->greenPanel->Location = System::Drawing::Point(0, 185);
			this->greenPanel->Name = L"greenPanel";
			this->greenPanel->Size = System::Drawing::Size(800, 5);
			this->greenPanel->TabIndex = 16;
			// 
			// HelpTimer
			// 
			this->HelpTimer->Interval = 1;
			this->HelpTimer->Tick += gcnew System::EventHandler(this, &CalcForm::timerHelpOpener_Tick);
			// 
			// staticPanel
			// 
			this->staticPanel->BackColor = System::Drawing::Color::White;
			this->staticPanel->Controls->Add(this->openerPanel);
			this->staticPanel->Controls->Add(this->greenPanel);
			this->staticPanel->Controls->Add(this->boxRed);
			this->staticPanel->Controls->Add(this->boxBlue);
			this->staticPanel->Controls->Add(this->boxGreen);
			this->staticPanel->Controls->Add(this->colorsLabel);
			this->staticPanel->Controls->Add(this->HelpLabel2);
			this->staticPanel->Controls->Add(this->label3);
			this->staticPanel->Controls->Add(this->HelpLabel);
			this->staticPanel->Location = System::Drawing::Point(91, 530);
			this->staticPanel->MaximumSize = System::Drawing::Size(1000, 190);
			this->staticPanel->MinimumSize = System::Drawing::Size(530, 190);
			this->staticPanel->Name = L"staticPanel";
			this->staticPanel->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->staticPanel->Size = System::Drawing::Size(800, 190);
			this->staticPanel->TabIndex = 18;
			// 
			// openerPanel
			// 
			this->openerPanel->BackColor = System::Drawing::Color::Transparent;
			this->openerPanel->Dock = System::Windows::Forms::DockStyle::Right;
			this->openerPanel->Location = System::Drawing::Point(777, 0);
			this->openerPanel->Name = L"openerPanel";
			this->openerPanel->Size = System::Drawing::Size(23, 190);
			this->openerPanel->TabIndex = 18;
			// 
			// boxRed
			// 
			this->boxRed->BackColor = System::Drawing::Color::Transparent;
			this->boxRed->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"boxRed.BackgroundImage")));
			this->boxRed->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->boxRed->Location = System::Drawing::Point(647, 37);
			this->boxRed->Name = L"boxRed";
			this->boxRed->Size = System::Drawing::Size(20, 20);
			this->boxRed->TabIndex = 28;
			this->boxRed->TabStop = false;
			// 
			// boxBlue
			// 
			this->boxBlue->BackColor = System::Drawing::Color::Transparent;
			this->boxBlue->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"boxBlue.BackgroundImage")));
			this->boxBlue->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->boxBlue->Location = System::Drawing::Point(647, 82);
			this->boxBlue->Name = L"boxBlue";
			this->boxBlue->Size = System::Drawing::Size(20, 20);
			this->boxBlue->TabIndex = 29;
			this->boxBlue->TabStop = false;
			// 
			// boxGreen
			// 
			this->boxGreen->BackColor = System::Drawing::Color::Transparent;
			this->boxGreen->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"boxGreen.BackgroundImage")));
			this->boxGreen->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->boxGreen->Location = System::Drawing::Point(647, 129);
			this->boxGreen->Name = L"boxGreen";
			this->boxGreen->Size = System::Drawing::Size(20, 20);
			this->boxGreen->TabIndex = 30;
			this->boxGreen->TabStop = false;
			// 
			// colorsLabel
			// 
			this->colorsLabel->BackColor = System::Drawing::Color::Transparent;
			this->colorsLabel->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->colorsLabel->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->colorsLabel->ForeColor = System::Drawing::Color::Black;
			this->colorsLabel->Location = System::Drawing::Point(673, 33);
			this->colorsLabel->Name = L"colorsLabel";
			this->colorsLabel->Size = System::Drawing::Size(112, 133);
			this->colorsLabel->TabIndex = 31;
			this->colorsLabel->Text = L"Ошибка\r\n\r\nПусто\r\n\r\nНет ошибок";
			// 
			// HelpLabel2
			// 
			this->HelpLabel2->BackColor = System::Drawing::Color::Transparent;
			this->HelpLabel2->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->HelpLabel2->Font = (gcnew System::Drawing::Font(L"Arial", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->HelpLabel2->ForeColor = System::Drawing::Color::Black;
			this->HelpLabel2->Location = System::Drawing::Point(113, 70);
			this->HelpLabel2->Name = L"HelpLabel2";
			this->HelpLabel2->Size = System::Drawing::Size(538, 110);
			this->HelpLabel2->TabIndex = 32;
			this->HelpLabel2->Text = resources->GetString(L"HelpLabel2.Text");
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Arial Black", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(14, 14);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(111, 30);
			this->label3->TabIndex = 46;
			this->label3->Text = L"Помощь";
			// 
			// clearPanel
			// 
			this->clearPanel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->clearPanel->Location = System::Drawing::Point(914, 658);
			this->clearPanel->Name = L"clearPanel";
			this->clearPanel->Size = System::Drawing::Size(330, 10);
			this->clearPanel->TabIndex = 28;
			// 
			// ClearTimer
			// 
			this->ClearTimer->Interval = 10;
			this->ClearTimer->Tick += gcnew System::EventHandler(this, &CalcForm::timerHistoryBeauty_Tick);
			// 
			// ClearPanelDynamic
			// 
			this->ClearPanelDynamic->BackColor = System::Drawing::Color::White;
			this->ClearPanelDynamic->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClearPanelDynamic->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->ClearPanelDynamic->Location = System::Drawing::Point(0, 501);
			this->ClearPanelDynamic->Name = L"ClearPanelDynamic";
			this->ClearPanelDynamic->Size = System::Drawing::Size(330, 24);
			this->ClearPanelDynamic->TabIndex = 29;
			// 
			// ClearPanelStatic
			// 
			this->ClearPanelStatic->BackColor = System::Drawing::Color::Transparent;
			this->ClearPanelStatic->Controls->Add(this->ClearPanelDynamic);
			this->ClearPanelStatic->Controls->Add(this->historyBox);
			this->ClearPanelStatic->Location = System::Drawing::Point(914, 133);
			this->ClearPanelStatic->Name = L"ClearPanelStatic";
			this->ClearPanelStatic->Size = System::Drawing::Size(330, 525);
			this->ClearPanelStatic->TabIndex = 30;
			// 
			// DynamicClearTimer
			// 
			this->DynamicClearTimer->Interval = 1;
			this->DynamicClearTimer->Tick += gcnew System::EventHandler(this, &CalcForm::timerHistoryClear_Tick);
			// 
			// labelX2
			// 
			this->labelX2->AutoSize = true;
			this->labelX2->BackColor = System::Drawing::Color::Transparent;
			this->labelX2->Font = (gcnew System::Drawing::Font(L"Arial Black", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelX2->Location = System::Drawing::Point(222, 91);
			this->labelX2->Name = L"labelX2";
			this->labelX2->Size = System::Drawing::Size(69, 30);
			this->labelX2->TabIndex = 31;
			this->labelX2->Text = L"x   + ";
			// 
			// labelX
			// 
			this->labelX->AutoSize = true;
			this->labelX->BackColor = System::Drawing::Color::Transparent;
			this->labelX->Font = (gcnew System::Drawing::Font(L"Arial Black", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelX->Location = System::Drawing::Point(473, 91);
			this->labelX->Name = L"labelX";
			this->labelX->Size = System::Drawing::Size(48, 30);
			this->labelX->TabIndex = 32;
			this->labelX->Text = L"x +";
			// 
			// label0
			// 
			this->label0->AutoSize = true;
			this->label0->BackColor = System::Drawing::Color::Transparent;
			this->label0->Font = (gcnew System::Drawing::Font(L"Arial Black", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label0->Location = System::Drawing::Point(702, 90);
			this->label0->Name = L"label0";
			this->label0->Size = System::Drawing::Size(48, 30);
			this->label0->TabIndex = 33;
			this->label0->Text = L"= 0";
			// 
			// clearInputButton
			// 
			this->clearInputButton->BackColor = System::Drawing::Color::Transparent;
			this->clearInputButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"clearInputButton.BackgroundImage")));
			this->clearInputButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->clearInputButton->FlatAppearance->BorderSize = 0;
			this->clearInputButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->clearInputButton->Location = System::Drawing::Point(15, 368);
			this->clearInputButton->Name = L"clearInputButton";
			this->clearInputButton->Size = System::Drawing::Size(100, 30);
			this->clearInputButton->TabIndex = 34;
			this->clearInputButton->UseVisualStyleBackColor = false;
			this->clearInputButton->Click += gcnew System::EventHandler(this, &CalcForm::clearInputButton_Click);
			// 
			// sqr
			// 
			this->sqr->AutoSize = true;
			this->sqr->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->sqr->Location = System::Drawing::Point(237, 83);
			this->sqr->Name = L"sqr";
			this->sqr->Size = System::Drawing::Size(15, 16);
			this->sqr->TabIndex = 35;
			this->sqr->Text = L"2";
			// 
			// progressPanel
			// 
			this->progressPanel->Controls->Add(this->progressOpenerPanel);
			this->progressPanel->Controls->Add(this->progressPic);
			this->progressPanel->Location = System::Drawing::Point(462, 154);
			this->progressPanel->Name = L"progressPanel";
			this->progressPanel->Size = System::Drawing::Size(290, 184);
			this->progressPanel->TabIndex = 36;
			// 
			// progressOpenerPanel
			// 
			this->progressOpenerPanel->Controls->Add(this->ProgressPicBlue);
			this->progressOpenerPanel->Controls->Add(this->ProgressPicBlack);
			this->progressOpenerPanel->Dock = System::Windows::Forms::DockStyle::Right;
			this->progressOpenerPanel->Location = System::Drawing::Point(0, 0);
			this->progressOpenerPanel->Name = L"progressOpenerPanel";
			this->progressOpenerPanel->Size = System::Drawing::Size(290, 184);
			this->progressOpenerPanel->TabIndex = 38;
			// 
			// ProgressPicBlue
			// 
			this->ProgressPicBlue->Dock = System::Windows::Forms::DockStyle::Right;
			this->ProgressPicBlue->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ProgressPicBlue.Image")));
			this->ProgressPicBlue->Location = System::Drawing::Point(-290, 0);
			this->ProgressPicBlue->Name = L"ProgressPicBlue";
			this->ProgressPicBlue->Size = System::Drawing::Size(290, 184);
			this->ProgressPicBlue->TabIndex = 45;
			this->ProgressPicBlue->TabStop = false;
			// 
			// ProgressPicBlack
			// 
			this->ProgressPicBlack->Dock = System::Windows::Forms::DockStyle::Right;
			this->ProgressPicBlack->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ProgressPicBlack.Image")));
			this->ProgressPicBlack->Location = System::Drawing::Point(0, 0);
			this->ProgressPicBlack->Name = L"ProgressPicBlack";
			this->ProgressPicBlack->Size = System::Drawing::Size(290, 184);
			this->ProgressPicBlack->TabIndex = 44;
			this->ProgressPicBlack->TabStop = false;
			// 
			// progressPic
			// 
			this->progressPic->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"progressPic.BackgroundImage")));
			this->progressPic->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->progressPic->Dock = System::Windows::Forms::DockStyle::Fill;
			this->progressPic->Location = System::Drawing::Point(0, 0);
			this->progressPic->Name = L"progressPic";
			this->progressPic->Size = System::Drawing::Size(290, 184);
			this->progressPic->TabIndex = 37;
			this->progressPic->TabStop = false;
			// 
			// ProgressTimer
			// 
			this->ProgressTimer->Interval = 2;
			this->ProgressTimer->Tick += gcnew System::EventHandler(this, &CalcForm::ProgressTimer_Tick);
			// 
			// boxDiscr
			// 
			this->boxDiscr->BackColor = System::Drawing::Color::WhiteSmoke;
			this->boxDiscr->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->boxDiscr->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->boxDiscr->Location = System::Drawing::Point(128, 292);
			this->boxDiscr->Name = L"boxDiscr";
			this->boxDiscr->ReadOnly = true;
			this->boxDiscr->Size = System::Drawing::Size(264, 24);
			this->boxDiscr->TabIndex = 38;
			// 
			// RootLabel
			// 
			this->RootLabel->AutoSize = true;
			this->RootLabel->BackColor = System::Drawing::Color::Transparent;
			this->RootLabel->Font = (gcnew System::Drawing::Font(L"Arial Black", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->RootLabel->Location = System::Drawing::Point(64, 168);
			this->RootLabel->Name = L"RootLabel";
			this->RootLabel->Size = System::Drawing::Size(57, 150);
			this->RootLabel->TabIndex = 39;
			this->RootLabel->Text = L"x  =\r\n\r\nx  =\r\n\r\nD  =";
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(83, 187);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(13, 105);
			this->label1->TabIndex = 40;
			this->label1->Text = L"1\r\n\r\n\r\n2\r\n\r\n\r\n";
			// 
			// HeaderTimer
			// 
			this->HeaderTimer->Interval = 10;
			this->HeaderTimer->Tick += gcnew System::EventHandler(this, &CalcForm::HeaderTimer_Tick);
			// 
			// HeaderPanelUp
			// 
			this->HeaderPanelUp->BackColor = System::Drawing::Color::White;
			this->HeaderPanelUp->Controls->Add(this->TipPic);
			this->HeaderPanelUp->Controls->Add(this->TipLabel);
			this->HeaderPanelUp->Controls->Add(this->HeaderDynamicPanel);
			this->HeaderPanelUp->Controls->Add(this->buttonMenu);
			this->HeaderPanelUp->Controls->Add(this->complexSwitcher2);
			this->HeaderPanelUp->Controls->Add(this->complexSwitcher1);
			this->HeaderPanelUp->Location = System::Drawing::Point(60, 0);
			this->HeaderPanelUp->Name = L"HeaderPanelUp";
			this->HeaderPanelUp->Size = System::Drawing::Size(1220, 53);
			this->HeaderPanelUp->TabIndex = 41;
			this->HeaderPanelUp->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &CalcForm::HeaderUp_MouseDown);
			this->HeaderPanelUp->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &CalcForm::HeaderUp_MouseMove);
			this->HeaderPanelUp->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &CalcForm::HeaderUp_MouseUp);
			// 
			// TipPic
			// 
			this->TipPic->BackColor = System::Drawing::Color::Transparent;
			this->TipPic->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"TipPic.BackgroundImage")));
			this->TipPic->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->TipPic->Location = System::Drawing::Point(1177, 12);
			this->TipPic->Name = L"TipPic";
			this->TipPic->Size = System::Drawing::Size(32, 32);
			this->TipPic->TabIndex = 45;
			this->TipPic->TabStop = false;
			this->TipPic->Click += gcnew System::EventHandler(this, &CalcForm::TipPic_Click);
			// 
			// TipLabel
			// 
			this->TipLabel->BackColor = System::Drawing::Color::White;
			this->TipLabel->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->TipLabel->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->TipLabel->ForeColor = System::Drawing::Color::Black;
			this->TipLabel->Location = System::Drawing::Point(873, 6);
			this->TipLabel->Name = L"TipLabel";
			this->TipLabel->Size = System::Drawing::Size(294, 46);
			this->TipLabel->TabIndex = 32;
			this->TipLabel->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->TipLabel->Click += gcnew System::EventHandler(this, &CalcForm::TipLabel_Click);
			// 
			// HeaderDynamicPanel
			// 
			this->HeaderDynamicPanel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->HeaderDynamicPanel->Location = System::Drawing::Point(0, 0);
			this->HeaderDynamicPanel->Name = L"HeaderDynamicPanel";
			this->HeaderDynamicPanel->Size = System::Drawing::Size(1220, 5);
			this->HeaderDynamicPanel->TabIndex = 42;
			// 
			// buttonMenu
			// 
			this->buttonMenu->BackColor = System::Drawing::Color::Transparent;
			this->buttonMenu->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonMenu.BackgroundImage")));
			this->buttonMenu->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->buttonMenu->FlatAppearance->BorderSize = 0;
			this->buttonMenu->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonMenu->Location = System::Drawing::Point(9, 11);
			this->buttonMenu->Name = L"buttonMenu";
			this->buttonMenu->Size = System::Drawing::Size(32, 32);
			this->buttonMenu->TabIndex = 45;
			this->buttonMenu->UseVisualStyleBackColor = false;
			this->buttonMenu->Click += gcnew System::EventHandler(this, &CalcForm::buttonMenu_Click);
			// 
			// complexSwitcher2
			// 
			this->complexSwitcher2->AutoSize = true;
			this->complexSwitcher2->BackColor = System::Drawing::Color::Transparent;
			this->complexSwitcher2->FlatAppearance->BorderColor = System::Drawing::Color::Aqua;
			this->complexSwitcher2->FlatAppearance->CheckedBackColor = System::Drawing::Color::Aqua;
			this->complexSwitcher2->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Aqua;
			this->complexSwitcher2->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Aqua;
			this->complexSwitcher2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->complexSwitcher2->Font = (gcnew System::Drawing::Font(L"Arial", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->complexSwitcher2->Location = System::Drawing::Point(454, 7);
			this->complexSwitcher2->Name = L"complexSwitcher2";
			this->complexSwitcher2->Size = System::Drawing::Size(133, 40);
			this->complexSwitcher2->TabIndex = 53;
			this->complexSwitcher2->Text = L"Комплексные \r\nкоэф\r\n";
			this->complexSwitcher2->UseVisualStyleBackColor = false;
			// 
			// complexSwitcher1
			// 
			this->complexSwitcher1->AutoSize = true;
			this->complexSwitcher1->BackColor = System::Drawing::Color::Transparent;
			this->complexSwitcher1->Checked = true;
			this->complexSwitcher1->FlatAppearance->BorderColor = System::Drawing::Color::Aqua;
			this->complexSwitcher1->FlatAppearance->CheckedBackColor = System::Drawing::Color::Aqua;
			this->complexSwitcher1->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Aqua;
			this->complexSwitcher1->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Aqua;
			this->complexSwitcher1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->complexSwitcher1->Font = (gcnew System::Drawing::Font(L"Arial", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->complexSwitcher1->Location = System::Drawing::Point(240, 7);
			this->complexSwitcher1->Name = L"complexSwitcher1";
			this->complexSwitcher1->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->complexSwitcher1->Size = System::Drawing::Size(155, 40);
			this->complexSwitcher1->TabIndex = 52;
			this->complexSwitcher1->TabStop = true;
			this->complexSwitcher1->Text = L"Действительные \r\nкоэф\r\n";
			this->complexSwitcher1->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->complexSwitcher1->UseVisualStyleBackColor = false;
			this->complexSwitcher1->CheckedChanged += gcnew System::EventHandler(this, &CalcForm::complexSwitcher1_CheckedChanged);
			// 
			// LeftPanel
			// 
			this->LeftPanel->BackColor = System::Drawing::Color::Fuchsia;
			this->LeftPanel->Controls->Add(this->HeaderPanel);
			this->LeftPanel->ForeColor = System::Drawing::Color::Black;
			this->LeftPanel->Location = System::Drawing::Point(0, 0);
			this->LeftPanel->Name = L"LeftPanel";
			this->LeftPanel->Size = System::Drawing::Size(60, 720);
			this->LeftPanel->TabIndex = 43;
			// 
			// panelQuadric
			// 
			this->panelQuadric->BackColor = System::Drawing::Color::White;
			this->panelQuadric->Controls->Add(this->label1);
			this->panelQuadric->Controls->Add(this->checkPic);
			this->panelQuadric->Controls->Add(this->label2);
			this->panelQuadric->Controls->Add(this->splitter1);
			this->panelQuadric->Controls->Add(this->RootLabel);
			this->panelQuadric->Controls->Add(this->BoxX2);
			this->panelQuadric->Controls->Add(this->BoxX1);
			this->panelQuadric->Controls->Add(this->clearInputButton);
			this->panelQuadric->Controls->Add(this->boxDiscr);
			this->panelQuadric->Controls->Add(this->SolveButton);
			this->panelQuadric->Controls->Add(this->progressPanel);
			this->panelQuadric->Controls->Add(this->sqr);
			this->panelQuadric->Controls->Add(this->BoxA);
			this->panelQuadric->Controls->Add(this->BoxC);
			this->panelQuadric->Controls->Add(this->label0);
			this->panelQuadric->Controls->Add(this->BoxB);
			this->panelQuadric->Controls->Add(this->labelX2);
			this->panelQuadric->Controls->Add(this->labelX);
			this->panelQuadric->Location = System::Drawing::Point(91, 82);
			this->panelQuadric->Name = L"panelQuadric";
			this->panelQuadric->Size = System::Drawing::Size(800, 416);
			this->panelQuadric->TabIndex = 54;
			this->panelQuadric->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &CalcForm::Box_Paint);
			// 
			// checkPic
			// 
			this->checkPic->BackColor = System::Drawing::Color::Transparent;
			this->checkPic->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"checkPic.BackgroundImage")));
			this->checkPic->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->checkPic->Location = System::Drawing::Point(333, 361);
			this->checkPic->Name = L"checkPic";
			this->checkPic->Size = System::Drawing::Size(33, 32);
			this->checkPic->TabIndex = 45;
			this->checkPic->TabStop = false;
			this->checkPic->Visible = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial Black", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(14, 11);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(285, 30);
			this->label2->TabIndex = 42;
			this->label2->Text = L"Квадратное уравнение";
			// 
			// splitter1
			// 
			this->splitter1->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->splitter1->Dock = System::Windows::Forms::DockStyle::Top;
			this->splitter1->Location = System::Drawing::Point(0, 0);
			this->splitter1->Name = L"splitter1";
			this->splitter1->Size = System::Drawing::Size(800, 53);
			this->splitter1->TabIndex = 41;
			this->splitter1->TabStop = false;
			// 
			// histLabel
			// 
			this->histLabel->BackColor = System::Drawing::Color::White;
			this->histLabel->Font = (gcnew System::Drawing::Font(L"Arial Black", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->histLabel->Location = System::Drawing::Point(914, 82);
			this->histLabel->Name = L"histLabel";
			this->histLabel->Size = System::Drawing::Size(328, 53);
			this->histLabel->TabIndex = 46;
			this->histLabel->Text = L"  История";
			this->histLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// ActiveModePanel
			// 
			this->ActiveModePanel->Location = System::Drawing::Point(300, 50);
			this->ActiveModePanel->Name = L"ActiveModePanel";
			this->ActiveModePanel->Size = System::Drawing::Size(155, 5);
			this->ActiveModePanel->TabIndex = 55;
			// 
			// SolvedLabel
			// 
			this->SolvedLabel->AutoSize = true;
			this->SolvedLabel->BackColor = System::Drawing::Color::Transparent;
			this->SolvedLabel->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->SolvedLabel->Location = System::Drawing::Point(1108, 682);
			this->SolvedLabel->Name = L"SolvedLabel";
			this->SolvedLabel->Size = System::Drawing::Size(95, 22);
			this->SolvedLabel->TabIndex = 47;
			this->SolvedLabel->Text = L"Решено: ";
			// 
			// SolvedNumLabel
			// 
			this->SolvedNumLabel->AutoSize = true;
			this->SolvedNumLabel->BackColor = System::Drawing::Color::Transparent;
			this->SolvedNumLabel->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->SolvedNumLabel->Location = System::Drawing::Point(1195, 683);
			this->SolvedNumLabel->Name = L"SolvedNumLabel";
			this->SolvedNumLabel->Size = System::Drawing::Size(21, 22);
			this->SolvedNumLabel->TabIndex = 56;
			this->SolvedNumLabel->Text = L"0";
			// 
			// CalcForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->AutoSize = true;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)), static_cast<System::Int32>(static_cast<System::Byte>(248)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->ClientSize = System::Drawing::Size(1280, 720);
			this->Controls->Add(this->butClear);
			this->Controls->Add(this->SolvedNumLabel);
			this->Controls->Add(this->SolvedLabel);
			this->Controls->Add(this->ActiveModePanel);
			this->Controls->Add(this->histLabel);
			this->Controls->Add(this->panelQuadric);
			this->Controls->Add(this->HeaderPanelUp);
			this->Controls->Add(this->LeftPanel);
			this->Controls->Add(this->staticPanel);
			this->Controls->Add(this->ClearPanelStatic);
			this->Controls->Add(this->clearPanel);
			this->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(2);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(1280, 720);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(1280, 720);
			this->Name = L"CalcForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"CalcForm";
			this->TransparencyKey = System::Drawing::Color::Fuchsia;
			this->Load += gcnew System::EventHandler(this, &CalcForm::CalcForm_Load);
			this->HeaderPanel->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dayModePic))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nightModePic))->EndInit();
			this->staticPanel->ResumeLayout(false);
			this->staticPanel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->boxRed))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->boxBlue))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->boxGreen))->EndInit();
			this->ClearPanelStatic->ResumeLayout(false);
			this->ClearPanelStatic->PerformLayout();
			this->progressPanel->ResumeLayout(false);
			this->progressOpenerPanel->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ProgressPicBlue))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ProgressPicBlack))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->progressPic))->EndInit();
			this->HeaderPanelUp->ResumeLayout(false);
			this->HeaderPanelUp->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TipPic))->EndInit();
			this->LeftPanel->ResumeLayout(false);
			this->panelQuadric->ResumeLayout(false);
			this->panelQuadric->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->checkPic))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion

	private:
		//цветы тема и окрашиваний
		Color SecondaryDark = Color::FromArgb(53, 60, 71);	
		Color PrimaryDark = Color::FromArgb(62, 69, 83);	
		Color SecondaryLight = Color::FromArgb(255, 255, 255);	
		Color PrimaryLight = Color::FromArgb(246, 250, 253); 
		Color ThemeColor = Color::FromArgb(126, 20, 255);

		Color LightRed = Color::FromArgb(232, 51, 73);
		Color LightPurple = Color::FromArgb(133, 64, 245);
		Color LightGreen = Color::SpringGreen;

		bool mouseDown;		//если нажата кнопка мыши
		Point lastLocation;	

		bool nightmode = false;	//смена темы
		char nightsettings;		//запись темы в файл

		int historyCount = 0;	//кол-во записей в истории

		bool busyNow = false;	//занятость программы

		bool isOpen = false;	//состояние элементов окна
		bool isCleared = false;
		bool isProgress = false;
		bool headerIsOpen = true;
		
		Pen^ pA; Pen^ pC; Pen^ pB;	//цветы окрашивания текстбоксов

		bool complex = false;	//режим калькулятора

		//функция смены темы
	void nightTheme()
		{
			CalcForm::ForeColor = Color::White;
			this->BackColor = PrimaryDark;
			HeaderPanel->BackColor = Color::White;
			dayModePic->Visible = false;
			nightModePic->Visible = true;
			HeaderPanelUp->BackColor = SecondaryDark;
			HeaderPanel->BackColor = ThemeColor;
			panelQuadric->BackColor = SecondaryDark;

			ProgressPicBlack->Visible = true;
			ProgressPicBlue->Visible = false;

			BoxA->BackColor = SecondaryDark; BoxA->ForeColor = Color::WhiteSmoke;
			BoxB->BackColor = SecondaryDark; BoxB->ForeColor = Color::WhiteSmoke;
			BoxC->BackColor = SecondaryDark; BoxC->ForeColor = Color::WhiteSmoke;

			BoxX1->BackColor = PrimaryDark; BoxX1->ForeColor = Color::WhiteSmoke;
			BoxX2->BackColor = PrimaryDark; BoxX2->ForeColor = Color::WhiteSmoke;
			boxDiscr->BackColor = PrimaryDark; boxDiscr->ForeColor = Color::WhiteSmoke;
			historyBox->BackColor = SecondaryDark; historyBox->ForeColor = Color::WhiteSmoke;

			SolveButton->BackColor = PrimaryDark;
			SolveButton->FlatAppearance->MouseOverBackColor = SecondaryDark;

			openerPanel->BackColor = PrimaryDark;
			HelpLabel->BackColor = SecondaryDark;
			HelpLabel2->ForeColor = Color::WhiteSmoke; HelpLabel2->BackColor = SecondaryDark;
			staticPanel->BackColor = SecondaryDark;
			colorsLabel->ForeColor = Color::WhiteSmoke; colorsLabel->BackColor = SecondaryDark;
			TipLabel->ForeColor = Color::WhiteSmoke; TipLabel->BackColor = SecondaryDark;
			histLabel->ForeColor = Color::WhiteSmoke; histLabel->BackColor = SecondaryDark;

			if (complex)
				complexSwitcher1->ForeColor = Color::WhiteSmoke;
			else
				complexSwitcher2->ForeColor = Color::WhiteSmoke;
		}
	void dayTheme()
		{
			CalcForm::ForeColor = Color::Black;
			this->BackColor = PrimaryLight;
			HeaderPanel->BackColor = SecondaryLight;
			dayModePic->Visible = true;
			nightModePic->Visible = false;
			HeaderPanelUp->BackColor = SecondaryLight;
			HeaderPanel->BackColor = SecondaryDark;
			panelQuadric->BackColor = SecondaryLight;

			ProgressPicBlack->Visible = false;
			ProgressPicBlue->Visible = true;

			BoxA->BackColor = SecondaryLight; BoxA->ForeColor = Color::Black;
			BoxB->BackColor = SecondaryLight; BoxB->ForeColor = Color::Black;
			BoxC->BackColor = SecondaryLight; BoxC->ForeColor = Color::Black;

			BoxX1->BackColor = PrimaryLight; BoxX1->ForeColor = Color::Black;
			BoxX2->BackColor = PrimaryLight; BoxX2->ForeColor = Color::Black;
			boxDiscr->BackColor = PrimaryLight; boxDiscr->ForeColor = Color::Black;
			historyBox->BackColor = SecondaryLight; historyBox->ForeColor = Color::Black;

			SolveButton->BackColor = PrimaryLight;
			SolveButton->FlatAppearance->MouseOverBackColor = SecondaryLight;

			openerPanel->BackColor = PrimaryLight;
			HelpLabel->BackColor = SecondaryLight;
			HelpLabel2->ForeColor = Color::Black; HelpLabel2->BackColor = SecondaryLight;
			staticPanel->BackColor = SecondaryLight;
			colorsLabel->ForeColor = Color::Black; colorsLabel->BackColor = SecondaryLight;
			TipLabel->ForeColor = Color::Black; TipLabel->BackColor = SecondaryLight;
			histLabel->ForeColor = Color::Black; histLabel->BackColor = SecondaryLight;

			if (complex)
				complexSwitcher1->ForeColor = Color::Black;
			else
				complexSwitcher2->ForeColor = Color::Black;

		}
		//замена картинки из ресурсов
	private: Void setImageFromResPic(System::String^ resource_ID, PictureBox^ pic) 
	{
		Reflection::Assembly^ pxAssembly = Reflection::Assembly::GetExecutingAssembly();
		String^ pxResName = pxAssembly->GetName()->Name + ".Resources"; 
		Resources::ResourceManager^ s_pxResourceManager = (gcnew Resources::ResourceManager(pxResName, pxAssembly));

		pic->BackgroundImage = (cli::safe_cast<Drawing::Bitmap^>(s_pxResourceManager->GetObject(resource_ID)));
	}
		//Загрузка
	private: System::Void CalcForm_Load(System::Object^ sender, System::EventArgs^ e)
	{
		//скрыть основное окно
		this->Hide();
		//экран загрузки
		Calc::SplashScreen LoadScreen;
		LoadScreen.ShowDialog();

		//чтение из файла на рабочем столе
		wchar_t szBuf[MAX_PATH]{ 0 };
		GetEnvironmentVariableW(L"USERPROFILE", szBuf, MAX_PATH);
		wcscat_s(szBuf, L"\\Desktop\\settings.txt");
		ifstream fin(szBuf);
		if (fin.is_open())
		{
			string temp; 
			fin >> temp; 
			nightsettings = temp[0];	//тема
			fin >> solvedNum;		//кол-во решенных ур.
		}
		else //если не удалось считать
		{	//ставим по ум.
			nightsettings = 'n';
			solvedNum = "0";
		}
		solvedNumber = stol(solvedNum);	//число решений в long
		fin.close();

		//вывод числа решений на окно
		SolvedNumLabel->Text = msclr::interop::marshal_as<System::String^>(solvedNum);

		//устанавливаем цвета для границ ТекстБоксом по ум.
		pA = gcnew Pen(LightPurple, 2.0f);
		pB = gcnew Pen(LightPurple, 2.0f);
		pC = gcnew Pen(LightPurple, 2.0f);

		//установки некоторых параметров объектов
		clearPanel->Width = 330;
		ClearPanelDynamic->Height = 0;
		HeaderPanel->Width = 60;
		openerPanel->Width = 800;
		HeaderDynamicPanel->Width = 0;
		complexSwitcher1->ForeColor = ThemeColor;
		HelpLabel->ForeColor = ThemeColor;
		SolvedNumLabel->ForeColor = ThemeColor;

		ClearPanelDynamic->BackColor = ThemeColor;
		clearPanel->BackColor = ThemeColor;
		greenPanel->BackColor = ThemeColor;
		HeaderDynamicPanel->BackColor = ThemeColor;
		ActiveModePanel->BackColor = ThemeColor;

		//установка считанной темы
		if (nightsettings == 'y') 
		{
			nightmode = true;
			nightTheme();
		}
		else 
		{
			nightmode = false;
			dayTheme();
		}

		//выбор цвета переключателя режимов
		if (nightmode)
			complexSwitcher2->ForeColor = Color::WhiteSmoke;
		else
			complexSwitcher2->ForeColor = Color::Black;

		this->Show();	//показать основное окно
	}
		//Передвижение окна
	private: System::Void HeaderUp_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

		mouseDown = true;
		lastLocation = e->Location;

	}
	private: System::Void HeaderUp_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

		if (mouseDown)
		{
			//установка нового положения окна в зависимости от старого
			this->Location = Point((this->Location.X - lastLocation.X) + e->X, (this->Location.Y - lastLocation.Y) + e->Y);
			this->Update();
		}

	}
	private: System::Void HeaderUp_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
	{
		mouseDown = false;
	}
		   //Закрытие и сворачивание окна
	private: System::Void buttonCloseWindow_Click(System::Object^ sender, System::EventArgs^ e)
	{
		//получаем путь в файлу на рабочем столе польз.
		wchar_t szBuf[MAX_PATH]{ 0 };
		GetEnvironmentVariableW(L"USERPROFILE", szBuf, MAX_PATH);
		wcscat_s(szBuf, L"\\Desktop\\settings.txt");

		ofstream g(szBuf);	//запись
		if (g.is_open())
		{
			if (nightmode)	//записываем тему
				g << "y\n";
			else
				g << "n\n";
			solvedNum = to_string(solvedNumber);	//кол-во решений
			g << solvedNum;
		}
		g.close();
		//анимция закрытия
		timer2->Interval = 5;
		timer2->Start();
	}
	private: System::Void timerClose_Tick(System::Object^ sender, System::EventArgs^ e)
	{
		this->Opacity -= 0.04;
		if (this->Opacity == 0)
		{
			timer1->Stop();
			this->Close();
		}
	}
	private: System::Void buttonMinimizeWindow_Click(System::Object^ sender, System::EventArgs^ e)
	{
		//анимация скрытия
		timer1->Interval = 5;
		timer1->Start();
	}
	private: System::Void timerMinimize_Tick(System::Object^ sender, System::EventArgs^ e)
	{
		this->Opacity -= 0.04;
		if (this->Opacity == 0)
		{
			timer1->Stop();
			this->WindowState = FormWindowState::Minimized;
			this->Opacity = 1.0;
		}
	}
		   //Смена темы
	private: System::Void timerThemeChange_Tick(System::Object^ sender, System::EventArgs^ e)
	{
		if (nightmode == false)
		{
			this->Opacity -= 0.10;
			if (this->Opacity == 0)
			{
				timer3->Stop();
				nightmode = true;	//применяем тему
				nightTheme();
				timer4->Interval = 2;	//возвращение окна
				timer4->Start();
				clearPanel->Width = 0; //анимация
				ClearTimer->Start();
			}
		}
		else
		{
			this->Opacity -= 0.10;
			if (this->Opacity == 0)
			{
				timer3->Stop();
				nightmode = false;
				dayTheme();
				timer4->Interval = 2;
				timer4->Start();
				clearPanel->Width = 0;
				ClearTimer->Start();
			}
		}
	}
	private: System::Void timerThemeChange2_Tick(System::Object^ sender, System::EventArgs^ e)
	{
		this->Opacity += 0.10;
		if (this->Opacity == 1)
		{
			timer4->Stop();
			busyNow = false;
		}
	}
	private: System::Void nightModePic_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (!busyNow)
		{
			busyNow = true;	//ничего нельзя делать
			timer3->Interval = 2;
			timer3->Start();
		}
	}
	private: System::Void dayModePic_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (!busyNow)
		{
			busyNow = true;
			timer3->Interval = 2;
			timer3->Start();
		}
	}
		   //Очищение истории
	private: System::Void buttonHistoryClear_Click(System::Object^ sender, System::EventArgs^ e)
	{
		DynamicClearTimer->Start();
	}
    private: System::Void timerHistoryClear_Tick(System::Object^ sender, System::EventArgs^ e)
{
	if (!isCleared)
	{
		ClearPanelDynamic->Height += 105;
		if (ClearPanelDynamic->Height == 525)
		{
			historyBox->Clear();	//очищаем бокс
			historyCount = 0;		//кол-во записей = 0
			historyNotes.clear();	//очищаем вектор записей
			isCleared = true;		//очищено - да
			ClearPanelDynamic->Dock = System::Windows::Forms::DockStyle::Top;
		}
	}
	else
	{
		ClearPanelDynamic->Height -= 105;
		if (ClearPanelDynamic->Height == 0)
		{
			DynamicClearTimer->Stop();
			isCleared = false;
			ClearPanelDynamic->Dock = System::Windows::Forms::DockStyle::Bottom;

		}
	}
}
	private: System::Void timerHistoryBeauty_Tick(System::Object^ sender, System::EventArgs^ e)
	{
		//анимация при смене темы
		clearPanel->Width += 15;
		if (clearPanel->Width == 330)
			ClearTimer->Stop();
	}
		   //Панель помощи
	private: System::Void buttonHelp_Click(System::Object^ sender, System::EventArgs^ e)
		{
			HelpTimer->Start();
		}
	private: System::Void timerHelpOpener_Tick(System::Object^ sender, System::EventArgs^ e)
	{	
		//открывает/закрывает панель помощи
		if (!isOpen)
		{
			openerPanel->Width -= 40;
			if (openerPanel->Width == 0)
			{
				HelpTimer->Stop();
				isOpen = true;
				openerPanel->Dock = System::Windows::Forms::DockStyle::Left;
			}
		}
		else
		{
			openerPanel->Width += 40;
			if (openerPanel->Width == 800)
			{
				HelpTimer->Stop();
				isOpen = false;
				openerPanel->Dock = System::Windows::Forms::DockStyle::Right;
			}
		}
	}
		   //очищение ввода
	private: System::Void clearInputButton_Click(System::Object^ sender, System::EventArgs^ e)
		{
			BoxA->Clear(); BoxB->Clear(); BoxC->Clear(); BoxX1->Clear(); BoxX2->Clear(); boxDiscr->Clear();
		}
		   //Окрашивание текст боксов
	private: System::Void Box_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
	{
		//рисование границ текст боксов по их координатам
		e->Graphics->DrawRectangle(pA, BoxA->Location.X - 1, BoxA->Location.Y - 1, BoxA->Width + 2, BoxA->Height + 2);
		e->Graphics->DrawRectangle(pB, BoxB->Location.X - 1, BoxB->Location.Y - 1, BoxB->Width + 2, BoxB->Height + 2);
		e->Graphics->DrawRectangle(pC, BoxC->Location.X - 1, BoxC->Location.Y - 1, BoxC->Width + 2, BoxC->Height + 2);
		//если все цвета - зеленые, то все верно
		if (pA->Color == LightGreen && pB->Color == LightGreen && pC->Color == LightGreen)
			checkPic->Visible = true;
		else
			checkPic->Visible = false;
	}
	private: System::Void BoxA_TextChanged(System::Object^ sender, System::EventArgs^ e)
	{
		if (BoxA->Text == "")	//если текст бокс пустой
			pA = gcnew Pen(LightPurple, 2.0f);

		else if (!complex)	//если режим действ. чисел
		{
			if(!check(BoxA->Text))	//проверяем на верность
				pA = gcnew Pen(LightRed, 2.0f);
			else //иначе
				pA = gcnew Pen(LightGreen, 2.0f);
		}
		else //если комплексный режим
		{
			if (!checkCompl(BoxA->Text)) //проверяем на верность
				pA = gcnew Pen(LightRed, 2.0f);
			else //иначе
				pA = gcnew Pen(LightGreen, 2.0f);
		}
		panelQuadric->Refresh();	//обновляем/перерисовываем
	}
	private: System::Void BoxB_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		if (BoxB->Text == "")
			pB = gcnew Pen(LightPurple, 2.0f);

		else if (!complex)
		{
			if (!check(BoxB->Text))
				pB = gcnew Pen(LightRed, 2.0f);
			else
				pB = gcnew Pen(LightGreen, 2.0f);
		}
		else
		{
			if (!checkCompl(BoxB->Text))
				pB = gcnew Pen(LightRed, 2.0f);
			else
				pB = gcnew Pen(LightGreen, 2.0f);
		}
		panelQuadric->Refresh();
	}
	private: System::Void BoxC_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		if (BoxC->Text == "")
			pC = gcnew Pen(LightPurple, 2.0f);

		else if (!complex)
		{
			if (!check(BoxC->Text))
				pC = gcnew Pen(LightRed, 2.0f);
			else
				pC = gcnew Pen(LightGreen, 2.0f);
		}
		else
		{
			if (!checkCompl(BoxC->Text))
				pC = gcnew Pen(LightRed, 2.0f);
			else
				pC = gcnew Pen(LightGreen, 2.0f);
		}
		panelQuadric->Refresh();
	}
		   //история
	private: System::Void HistoryPrint()
	{
		//вывод истории

		solvedNumber++;	//кол-во решенных +1
		solvedNum = to_string(solvedNumber);	//конверт в string
		SolvedNumLabel->Text = msclr::interop::marshal_as<System::String^>(solvedNum);	//в String^

		//конвертация всех данных в string
		string A = msclr::interop::marshal_as<std::string>(BoxA->Text);
		string B = msclr::interop::marshal_as<std::string>(BoxB->Text);
		string C = msclr::interop::marshal_as<std::string>(BoxC->Text);
		string X1 = msclr::interop::marshal_as<std::string>(BoxX1->Text);
		string X2 = msclr::interop::marshal_as<std::string>(BoxX2->Text);

		//запись в вектор истории
		historyNote note;
		note.eq = "(" + A + ")x^2 + " + "(" + B + ")x + " + "(" + C + ") = 0";
		note.x1 = X1;
		note.x2 = X2;
		if (!complex)
			note.type = "REAL";
		else
			note.type = "COMPLEX";
		historyNotes.push_back(note);

		//если записей еще не 6, то просто добавляем
		if (historyCount != 6)
			historyCount++;
		else //иначе удаляем первую запись
			historyNotes.erase(historyNotes.begin());
		//очищаем бокс
		historyBox->Clear();
		for (int i = 0; i < historyCount; i++)
		{
			//запись истории в текст бокс
			System::String^ eqString = msclr::interop::marshal_as<System::String^>(historyNotes[i].eq);
			System::String^ x1String = msclr::interop::marshal_as<System::String^>(historyNotes[i].x1);
			System::String^ x2String = msclr::interop::marshal_as<System::String^>(historyNotes[i].x2);
			if (historyNotes[i].type == "REAL")
				historyBox->AppendText("---REAL---------------------|" + Convert::ToString(i + 1) + "|-----------------------------" + Environment::NewLine);
			else
				historyBox->AppendText("---COMPLEX--------------|" + Convert::ToString(i + 1) + "|-----------------------------" + Environment::NewLine);
			historyBox->AppendText(eqString + Environment::NewLine);
			if (x2String != x1String) 
			{
				historyBox->AppendText("x1 = " + x1String + Environment::NewLine);
				historyBox->AppendText("x2 = " + x2String + Environment::NewLine);
			}
			else
			{
				historyBox->AppendText("x = " + x1String + Environment::NewLine);
			}
			
		}
	}
	private: System::Void ProgressTimer_Tick(System::Object^ sender, System::EventArgs^ e)
	{
		//анимация прогресса записи
		if (!isProgress)	
		{
			progressOpenerPanel->Width -= 10;
			if (progressOpenerPanel->Width == 0)
			{
				//печать
				HistoryPrint();
				isProgress = true;
				progressOpenerPanel->Dock = System::Windows::Forms::DockStyle::Left;
				ProgressPicBlack->Dock = System::Windows::Forms::DockStyle::Left;
				ProgressPicBlue->Dock = System::Windows::Forms::DockStyle::Left;
			}
		}
		else
		{
			progressOpenerPanel->Width += 10;
			if (progressOpenerPanel->Width == 290)
			{
				ProgressTimer->Stop();
				isProgress = false;
				progressOpenerPanel->Dock = System::Windows::Forms::DockStyle::Right;
				ProgressPicBlack->Dock = System::Windows::Forms::DockStyle::Right;
				ProgressPicBlue->Dock = System::Windows::Forms::DockStyle::Right;

			}
		}
		
	}
		   //хедер
	private: System::Void buttonMenu_Click(System::Object^ sender, System::EventArgs^ e)
		{
			HeaderTimer->Start();
		}
	private: System::Void HeaderTimer_Tick(System::Object^ sender, System::EventArgs^ e)
	{
		//открытие/закрытие левой панели
		if (!headerIsOpen)
		{
			HeaderPanel->Width += 3;
			HeaderDynamicPanel->Width -= 61;
			if (HeaderPanel->Width == 60)
			{
				HeaderTimer->Stop();
				headerIsOpen = true;
			}
		}
		else
		{
			HeaderPanel->Width -= 3;
			HeaderDynamicPanel->Width += 61;
			if (HeaderPanel->Width == 0)
			{
				HeaderTimer->Stop();
				headerIsOpen = false;
			}
		}
	}
			//советы
	private: System::Void TipPic_Click(System::Object^ sender, System::EventArgs^ e)
	{
		//рандомный совет
		string tip = randomTip();
		TipLabel->Text = msclr::interop::marshal_as<System::String^>(tip);
	}
	private: System::Void TipLabel_Click(System::Object^ sender, System::EventArgs^ e) {
		TipLabel->Text = "";	//удаление совета при нажатии на него
	}
		   //смена режима
	private: System::Void complexSwitcher1_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
	{
		//смена режима

		//если ДЕЙСТВ.
		if (!complex)
		{
			complex = true;
			complexSwitcher2->ForeColor = ThemeColor;
			if (nightmode)
				complexSwitcher1->ForeColor = Color::WhiteSmoke;
			else
				complexSwitcher1->ForeColor = Color::Black;
			ActiveModePanel->Location = System::Drawing::Point(518, 50);
		}
		//если КОМПЛ.
		else
		{
			complex = false;
			complexSwitcher1->ForeColor = ThemeColor;
			if (nightmode)
				complexSwitcher2->ForeColor = Color::WhiteSmoke;
			else
				complexSwitcher2->ForeColor = Color::Black;
			ActiveModePanel->Location = System::Drawing::Point(300, 50);
		}
		//очищаем все боксы и обновляем панель
		BoxX1->Clear(); BoxX2->Clear(); boxDiscr->Clear();
		BoxA->Text = ""; BoxB->Text = ""; BoxC->Text = "";
		HeaderPanelUp->Refresh();
	}
		   //.............................Решение................................//
	private: System::Void Solve_Click(System::Object^ sender, System::EventArgs^ e)
	{
		//
		// Основа программы - кнопка решения
		//
		
		//если ДЕЙСТВ. режим
		if (!complex)
		{
			if (BoxA->Text != "" && BoxB->Text != "" && BoxC->Text != "")	//проверяем на пустой ввод
			{
				if (check(BoxA->Text) && check(BoxB->Text) && check(BoxC->Text))	//проверяем на ошибки ввода
				{
					//конвершируем введенные данный в string
					std::string As = msclr::interop::marshal_as<std::string>(BoxA->Text);
					std::string Bs = msclr::interop::marshal_as<std::string>(BoxB->Text);
					std::string Cs = msclr::interop::marshal_as<std::string>(BoxC->Text);
					//и передаем их в решение brackets.h
					double A = eval(As);
					double B = eval(Bs);
					double C = eval(Cs);
					//полученный результат передаем в функцию решения
					int result = solver(A, B, C);
					//если 1 коэф. = 0, то ур. не квадратное
					if (result == -1)
					{
						Calc::Error ErrorScreen(nightmode, "Не квадратное уравнение");
						ErrorScreen.ShowDialog();
						return;
					}

					//запись результатов
					BoxX1->Text = msclr::interop::marshal_as<System::String^>(sx1);
					BoxX2->Text = msclr::interop::marshal_as<System::String^>(sx2);
					boxDiscr->Text = msclr::interop::marshal_as<System::String^>(disc);

					ProgressTimer->Start(); //прогресс бар и запись ответа в историю
				}
				else
				{
					//тип ошибки при check
					Calc::Error ErrorScreen(nightmode, msclr::interop::marshal_as<String^>(ErrorCheck));
					ErrorScreen.ShowDialog();
				}
			}
			else
			{
				Calc::Error ErrorScreen(nightmode, "Введите все значения");
				ErrorScreen.ShowDialog();
			}
		}
		//если КОМПЛ. режим
		else
		{
			if (BoxA->Text != "" && BoxB->Text != "" && BoxC->Text != "") //проверяем на пустой ввод
			{
				if (checkCompl(BoxA->Text) && checkCompl(BoxB->Text) && checkCompl(BoxC->Text)) //проверяем на ошибки ввода
				{
					//преобразование введенных строк в комплексные числа
					TransformCompl(BoxA->Text, 'a');	
					TransformCompl(BoxB->Text, 'b');
					TransformCompl(BoxC->Text, 'c');
					//и передаем их в решение brackets.h
					int result = solverCompl(ACompl, BCompl, CCompl);
					//если 1 коэф. = 0, то ур. не квадратное
					if (result == -1)
					{
						Calc::Error ErrorScreen(nightmode, "Не квадратное уравнение");
						ErrorScreen.ShowDialog();
						return;
					}
					//запись результатов
					BoxX1->Text = msclr::interop::marshal_as<System::String^>(sx1RCompl) + msclr::interop::marshal_as<System::String^>(sx1ICompl);
					BoxX2->Text = msclr::interop::marshal_as<System::String^>(sx2RCompl) + msclr::interop::marshal_as<System::String^>(sx2ICompl);
					boxDiscr->Text = msclr::interop::marshal_as<System::String^>(discrim1) + msclr::interop::marshal_as<System::String^>(discrim2);

					ProgressTimer->Start(); //прогресс бар и запись ответа в историю
				}
				else
				{
					//тип ошибки при checkCompl
					Calc::Error ErrorScreen(nightmode, msclr::interop::marshal_as<String^>(ErrorCheckCompl));
					ErrorScreen.ShowDialog();
				}
			}
			else
			{
				Calc::Error ErrorScreen(nightmode, "Введите все значения");
				ErrorScreen.ShowDialog();
			}
		}
	}	
};
}



