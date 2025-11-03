#pragma once
#include "Roulette.h"
#include <string>
#include <msclr/marshal_cppstd.h>

namespace Ruletka {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;

	/// <summary>
	/// Podsumowanie informacji o MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
			roulette = new Roulette();
			coins = gcnew array<String^> { "M1.png", "M2.png", "M3.png", "M4.png", "M5.png" };
		}

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
				delete roulette;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ StartButton;
	private: System::Windows::Forms::TextBox^ StartMoneyBox;
	private: System::Windows::Forms::TextBox^ PlayerAmountBox;
	private: System::Windows::Forms::PictureBox^ Player1Coin;
	private: System::Windows::Forms::PictureBox^ Player2Coin;
	private: System::Windows::Forms::PictureBox^ Player3Coin;
	private: System::Windows::Forms::PictureBox^ Player4Coin;
	private: System::Windows::Forms::PictureBox^ Player5Coin;







	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ Player1MoneyLabel;
	private: System::Windows::Forms::Label^ Player2MoneyLabel;
	private: System::Windows::Forms::Label^ Player3MoneyLabel;
	private: System::Windows::Forms::Label^ Player4MoneyLabel;
	private: System::Windows::Forms::Label^ Player5MoneyLabel;







	protected:

	private:
		Roulette* roulette;
		bool start = false;
		array<System::String^>^ coins;

	private: System::Windows::Forms::TextBox^ BetValueBox;
	private: System::Windows::Forms::Label^ RandomNumberLabel;
	private: System::Windows::Forms::PictureBox^ ActualTurnCoin;

		   /// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>
		   System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
		   /// jej zawartoœci w edytorze kodu.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			   this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			   this->StartButton = (gcnew System::Windows::Forms::Button());
			   this->StartMoneyBox = (gcnew System::Windows::Forms::TextBox());
			   this->PlayerAmountBox = (gcnew System::Windows::Forms::TextBox());
			   this->Player1Coin = (gcnew System::Windows::Forms::PictureBox());
			   this->Player2Coin = (gcnew System::Windows::Forms::PictureBox());
			   this->Player3Coin = (gcnew System::Windows::Forms::PictureBox());
			   this->Player4Coin = (gcnew System::Windows::Forms::PictureBox());
			   this->Player5Coin = (gcnew System::Windows::Forms::PictureBox());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->Player1MoneyLabel = (gcnew System::Windows::Forms::Label());
			   this->Player2MoneyLabel = (gcnew System::Windows::Forms::Label());
			   this->Player3MoneyLabel = (gcnew System::Windows::Forms::Label());
			   this->Player4MoneyLabel = (gcnew System::Windows::Forms::Label());
			   this->Player5MoneyLabel = (gcnew System::Windows::Forms::Label());
			   this->BetValueBox = (gcnew System::Windows::Forms::TextBox());
			   this->RandomNumberLabel = (gcnew System::Windows::Forms::Label());
			   this->ActualTurnCoin = (gcnew System::Windows::Forms::PictureBox());
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Player1Coin))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Player2Coin))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Player3Coin))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Player4Coin))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Player5Coin))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ActualTurnCoin))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // pictureBox1
			   // 
			   this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			   this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->pictureBox1->Location = System::Drawing::Point(0, 0);
			   this->pictureBox1->Name = L"pictureBox1";
			   this->pictureBox1->Size = System::Drawing::Size(960, 480);
			   this->pictureBox1->TabIndex = 0;
			   this->pictureBox1->TabStop = false;
			   this->pictureBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseClick);
			   // 
			   // StartButton
			   // 
			   this->StartButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(238)));
			   this->StartButton->Location = System::Drawing::Point(966, 12);
			   this->StartButton->Name = L"StartButton";
			   this->StartButton->Size = System::Drawing::Size(156, 34);
			   this->StartButton->TabIndex = 1;
			   this->StartButton->Text = L"Start/Rand";
			   this->StartButton->UseVisualStyleBackColor = true;
			   this->StartButton->Click += gcnew System::EventHandler(this, &MyForm::StartButton_Click);
			   // 
			   // StartMoneyBox
			   // 
			   this->StartMoneyBox->Location = System::Drawing::Point(966, 52);
			   this->StartMoneyBox->Name = L"StartMoneyBox";
			   this->StartMoneyBox->Size = System::Drawing::Size(156, 20);
			   this->StartMoneyBox->TabIndex = 2;
			   this->StartMoneyBox->Text = L"Start money";
			   this->StartMoneyBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			   // 
			   // PlayerAmountBox
			   // 
			   this->PlayerAmountBox->Location = System::Drawing::Point(966, 78);
			   this->PlayerAmountBox->Name = L"PlayerAmountBox";
			   this->PlayerAmountBox->Size = System::Drawing::Size(156, 20);
			   this->PlayerAmountBox->TabIndex = 3;
			   this->PlayerAmountBox->Text = L"Players amout(1-5)";
			   this->PlayerAmountBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			   // 
			   // Player1Coin
			   // 
			   this->Player1Coin->BackColor = System::Drawing::Color::Transparent;
			   this->Player1Coin->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Player1Coin.BackgroundImage")));
			   this->Player1Coin->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			   this->Player1Coin->Location = System::Drawing::Point(966, 449);
			   this->Player1Coin->Name = L"Player1Coin";
			   this->Player1Coin->Size = System::Drawing::Size(20, 20);
			   this->Player1Coin->TabIndex = 4;
			   this->Player1Coin->TabStop = false;
			   // 
			   // Player2Coin
			   // 
			   this->Player2Coin->BackColor = System::Drawing::Color::Transparent;
			   this->Player2Coin->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Player2Coin.BackgroundImage")));
			   this->Player2Coin->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			   this->Player2Coin->Location = System::Drawing::Point(992, 449);
			   this->Player2Coin->Name = L"Player2Coin";
			   this->Player2Coin->Size = System::Drawing::Size(20, 20);
			   this->Player2Coin->TabIndex = 5;
			   this->Player2Coin->TabStop = false;
			   // 
			   // Player3Coin
			   // 
			   this->Player3Coin->BackColor = System::Drawing::Color::Transparent;
			   this->Player3Coin->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Player3Coin.BackgroundImage")));
			   this->Player3Coin->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			   this->Player3Coin->Location = System::Drawing::Point(1018, 449);
			   this->Player3Coin->Name = L"Player3Coin";
			   this->Player3Coin->Size = System::Drawing::Size(20, 20);
			   this->Player3Coin->TabIndex = 6;
			   this->Player3Coin->TabStop = false;
			   // 
			   // Player4Coin
			   // 
			   this->Player4Coin->BackColor = System::Drawing::Color::Transparent;
			   this->Player4Coin->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Player4Coin.BackgroundImage")));
			   this->Player4Coin->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			   this->Player4Coin->Location = System::Drawing::Point(1044, 449);
			   this->Player4Coin->Name = L"Player4Coin";
			   this->Player4Coin->Size = System::Drawing::Size(20, 20);
			   this->Player4Coin->TabIndex = 7;
			   this->Player4Coin->TabStop = false;
			   // 
			   // Player5Coin
			   // 
			   this->Player5Coin->BackColor = System::Drawing::Color::Transparent;
			   this->Player5Coin->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Player5Coin.BackgroundImage")));
			   this->Player5Coin->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			   this->Player5Coin->Location = System::Drawing::Point(1070, 449);
			   this->Player5Coin->Name = L"Player5Coin";
			   this->Player5Coin->Size = System::Drawing::Size(20, 20);
			   this->Player5Coin->TabIndex = 8;
			   this->Player5Coin->TabStop = false;
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(238)));
			   this->label1->Location = System::Drawing::Point(988, 121);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(103, 20);
			   this->label1->TabIndex = 9;
			   this->label1->Text = L"Player money";
			   // 
			   // Player1MoneyLabel
			   // 
			   this->Player1MoneyLabel->AutoSize = true;
			   this->Player1MoneyLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(238)));
			   this->Player1MoneyLabel->Location = System::Drawing::Point(988, 154);
			   this->Player1MoneyLabel->Name = L"Player1MoneyLabel";
			   this->Player1MoneyLabel->Size = System::Drawing::Size(44, 20);
			   this->Player1MoneyLabel->TabIndex = 10;
			   this->Player1MoneyLabel->Text = L"1. 0$";
			   // 
			   // Player2MoneyLabel
			   // 
			   this->Player2MoneyLabel->AutoSize = true;
			   this->Player2MoneyLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(238)));
			   this->Player2MoneyLabel->Location = System::Drawing::Point(988, 174);
			   this->Player2MoneyLabel->Name = L"Player2MoneyLabel";
			   this->Player2MoneyLabel->Size = System::Drawing::Size(44, 20);
			   this->Player2MoneyLabel->TabIndex = 11;
			   this->Player2MoneyLabel->Text = L"2. 0$";
			   // 
			   // Player3MoneyLabel
			   // 
			   this->Player3MoneyLabel->AutoSize = true;
			   this->Player3MoneyLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(238)));
			   this->Player3MoneyLabel->Location = System::Drawing::Point(988, 193);
			   this->Player3MoneyLabel->Name = L"Player3MoneyLabel";
			   this->Player3MoneyLabel->Size = System::Drawing::Size(44, 20);
			   this->Player3MoneyLabel->TabIndex = 12;
			   this->Player3MoneyLabel->Text = L"3. 0$";
			   // 
			   // Player4MoneyLabel
			   // 
			   this->Player4MoneyLabel->AutoSize = true;
			   this->Player4MoneyLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(238)));
			   this->Player4MoneyLabel->Location = System::Drawing::Point(988, 213);
			   this->Player4MoneyLabel->Name = L"Player4MoneyLabel";
			   this->Player4MoneyLabel->Size = System::Drawing::Size(44, 20);
			   this->Player4MoneyLabel->TabIndex = 13;
			   this->Player4MoneyLabel->Text = L"4. 0$";
			   // 
			   // Player5MoneyLabel
			   // 
			   this->Player5MoneyLabel->AutoSize = true;
			   this->Player5MoneyLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(238)));
			   this->Player5MoneyLabel->Location = System::Drawing::Point(988, 233);
			   this->Player5MoneyLabel->Name = L"Player5MoneyLabel";
			   this->Player5MoneyLabel->Size = System::Drawing::Size(44, 20);
			   this->Player5MoneyLabel->TabIndex = 14;
			   this->Player5MoneyLabel->Text = L"5. 0$";
			   // 
			   // BetValueBox
			   // 
			   this->BetValueBox->Location = System::Drawing::Point(966, 423);
			   this->BetValueBox->Name = L"BetValueBox";
			   this->BetValueBox->Size = System::Drawing::Size(156, 20);
			   this->BetValueBox->TabIndex = 15;
			   this->BetValueBox->Text = L"Bet value";
			   this->BetValueBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			   // 
			   // RandomNumberLabel
			   // 
			   this->RandomNumberLabel->AutoSize = true;
			   this->RandomNumberLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(238)));
			   this->RandomNumberLabel->Location = System::Drawing::Point(1022, 332);
			   this->RandomNumberLabel->Name = L"RandomNumberLabel";
			   this->RandomNumberLabel->Size = System::Drawing::Size(42, 46);
			   this->RandomNumberLabel->TabIndex = 16;
			   this->RandomNumberLabel->Text = L"0";
			   // 
			   // ActualTurnCoin
			   // 
			   this->ActualTurnCoin->BackColor = System::Drawing::Color::Transparent;
			   this->ActualTurnCoin->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ActualTurnCoin.BackgroundImage")));
			   this->ActualTurnCoin->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			   this->ActualTurnCoin->Location = System::Drawing::Point(980, 256);
			   this->ActualTurnCoin->Name = L"ActualTurnCoin";
			   this->ActualTurnCoin->Size = System::Drawing::Size(52, 52);
			   this->ActualTurnCoin->TabIndex = 17;
			   this->ActualTurnCoin->TabStop = false;
			   // 
			   // MyForm
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->BackColor = System::Drawing::Color::DarkOliveGreen;
			   this->ClientSize = System::Drawing::Size(1134, 481);
			   this->Controls->Add(this->ActualTurnCoin);
			   this->Controls->Add(this->RandomNumberLabel);
			   this->Controls->Add(this->BetValueBox);
			   this->Controls->Add(this->Player5MoneyLabel);
			   this->Controls->Add(this->Player4MoneyLabel);
			   this->Controls->Add(this->Player3MoneyLabel);
			   this->Controls->Add(this->Player2MoneyLabel);
			   this->Controls->Add(this->Player1MoneyLabel);
			   this->Controls->Add(this->label1);
			   this->Controls->Add(this->Player5Coin);
			   this->Controls->Add(this->Player4Coin);
			   this->Controls->Add(this->Player3Coin);
			   this->Controls->Add(this->Player2Coin);
			   this->Controls->Add(this->Player1Coin);
			   this->Controls->Add(this->PlayerAmountBox);
			   this->Controls->Add(this->StartMoneyBox);
			   this->Controls->Add(this->StartButton);
			   this->Controls->Add(this->pictureBox1);
			   this->Name = L"MyForm";
			   this->Text = L"MyForm";
			   this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Player1Coin))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Player2Coin))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Player3Coin))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Player4Coin))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Player5Coin))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ActualTurnCoin))->EndInit();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void StartButton_Click(System::Object^ sender, System::EventArgs^ e) {
		if (!start)
		{
			int pa = 0, sm = 0;
			pa = System::Int32::Parse(this->PlayerAmountBox->Text);
			sm = System::Int32::Parse(this->StartMoneyBox->Text);
			if (System::Int32::TryParse(this->PlayerAmountBox->Text, pa) && System::Int32::TryParse(this->StartMoneyBox->Text, sm))
			{
				roulette->SetStartMoney(sm);
				roulette->SetPlayerAmount(pa);
				if (pa >= 1)
				{
					this->Player1MoneyLabel->Text = marshal_as<String^>("1." + std::to_string(sm) + "$");
				}
				if (pa >= 2)
				{
					this->Player2MoneyLabel->Text = marshal_as<String^>("2." + std::to_string(sm) + "$");
				}
				if (pa >= 3)
				{
					this->Player3MoneyLabel->Text = marshal_as<String^>("3." + std::to_string(sm) + "$");
				}
				if (pa >= 4)
				{
					this->Player4MoneyLabel->Text = marshal_as<String^>("4." + std::to_string(sm) + "$");
				}
				if (pa >= 5)
				{
					this->Player5MoneyLabel->Text = marshal_as<String^>("5." + std::to_string(sm) + "$");
				}
				start = true;

				roulette->StartTurn();
				ActualTurnCoin->BackgroundImage = Image::FromFile(coins[roulette->GetPlayerTurn() - 1]);
			}
			else
			{
				MessageBox::Show("Niepoprawne dane wejœciowe!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		else
		{
			int n = roulette->Random();
			this->RandomNumberLabel->Text = marshal_as<String^>(std::to_string(n));
			int pa = roulette->GetPlayerAmount();

			if (pa >= 1)
			{
				this->Player1MoneyLabel->Text = marshal_as<String^>("1." + std::to_string(roulette->GetPlayerMoney(1)) + "$");
			}
			if (pa >= 2)
			{
				this->Player2MoneyLabel->Text = marshal_as<String^>("2." + std::to_string(roulette->GetPlayerMoney(2)) + "$");
			}
			if (pa >= 3)
			{
				this->Player3MoneyLabel->Text = marshal_as<String^>("3." + std::to_string(roulette->GetPlayerMoney(3)) + "$");
			}
			if (pa >= 4)
			{
				this->Player4MoneyLabel->Text = marshal_as<String^>("4." + std::to_string(roulette->GetPlayerMoney(4)) + "$");
			}
			if (pa >= 5)
			{
				this->Player5MoneyLabel->Text = marshal_as<String^>("5." + std::to_string(roulette->GetPlayerMoney(5)) + "$");
			}

			if (roulette->StartTurn() == 0)
			{
				MessageBox::Show("Bankruci", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				start = false;
			}
			else
			{
				ActualTurnCoin->BackgroundImage = Image::FromFile(coins[roulette->GetPlayerTurn() - 1]);
			}

			this->Player1Coin->Location = System::Drawing::Point(966, 449);
			this->Player2Coin->Location = System::Drawing::Point(992, 449);
			this->Player3Coin->Location = System::Drawing::Point(1018, 449);
			this->Player4Coin->Location = System::Drawing::Point(1044, 449);
			this->Player5Coin->Location = System::Drawing::Point(1070, 449);
			roulette->NullBit();

			
		}
	}
	private: System::Void pictureBox1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (start)
		{
			int bet;
			if (System::Int32::TryParse(this->BetValueBox->Text, bet))
			{
				sVector s = roulette->SetPlayerBet(bet, sVector(e->X, e->Y));
				
				if (s.x == 0)
				{
					return;
				}
				else if (s.x == -1)
				{
					MessageBox::Show("B³¹d zak³adu", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
				else
				{
					int t = roulette->GetPlayerTurn();
					switch (t)
					{
					case 1:
						this->Player1Coin->Location = System::Drawing::Point(s.x - this->Player1Coin->Size.Width / 2, s.y - this->Player1Coin->Size.Height / 2);
						break;
					case 2:
						this->Player2Coin->Location = System::Drawing::Point(s.x - this->Player2Coin->Size.Width / 2, s.y - this->Player2Coin->Size.Height / 2);
						break;
					case 3:
						this->Player3Coin->Location = System::Drawing::Point(s.x - this->Player3Coin->Size.Width / 2, s.y - this->Player3Coin->Size.Height / 2);
						break;
					case 4:
						this->Player4Coin->Location = System::Drawing::Point(s.x - this->Player4Coin->Size.Width / 2, s.y - this->Player4Coin->Size.Height / 2);
						break;
					case 5:
						this->Player5Coin->Location = System::Drawing::Point(s.x - this->Player5Coin->Size.Width / 2, s.y - this->Player5Coin->Size.Height / 2);
						break;
					default:
						MessageBox::Show("Switch in PictureBox1", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
						break;
					}
					
					if (roulette->NextTurn())
					{
						ActualTurnCoin->BackgroundImage = Image::FromFile(coins[roulette->GetPlayerTurn()-1]);
					}
				}
			}
			else
			{
				MessageBox::Show("Niepoprawne dane wejœciowe(zak³ad)!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
	}
};
}
