#pragma once
#include "Roulette.h"

namespace Ruletka {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o StartForm
	/// </summary>
	public ref class StartForm : public System::Windows::Forms::Form
	{
	public:
		StartForm(void)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
			roulette = new Roulette();
		}

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~StartForm()
		{
			if (components)
			{
				delete components;
			}
			
		}

		Roulette* roulette;

	private: System::Windows::Forms::Button^ StartButton;
	private: System::Windows::Forms::TextBox^ playerAmountTextBox;
	private: System::Windows::Forms::TextBox^ moneyTextBox;
	protected:

	protected:



	private: System::Windows::Forms::TextBox^ playerNameTextBox;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ PlayerNameLabel;

	protected:

	private:
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
			this->StartButton = (gcnew System::Windows::Forms::Button());
			this->playerAmountTextBox = (gcnew System::Windows::Forms::TextBox());
			this->moneyTextBox = (gcnew System::Windows::Forms::TextBox());
			this->playerNameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->PlayerNameLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// StartButton
			// 
			this->StartButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->StartButton->Location = System::Drawing::Point(83, 147);
			this->StartButton->Name = L"StartButton";
			this->StartButton->Size = System::Drawing::Size(117, 33);
			this->StartButton->TabIndex = 0;
			this->StartButton->Text = L"Start";
			this->StartButton->UseVisualStyleBackColor = true;
			this->StartButton->Click += gcnew System::EventHandler(this, &StartForm::StartButton_Click);
			// 
			// playerAmountTextBox
			// 
			this->playerAmountTextBox->Location = System::Drawing::Point(142, 53);
			this->playerAmountTextBox->Name = L"playerAmountTextBox";
			this->playerAmountTextBox->Size = System::Drawing::Size(75, 20);
			this->playerAmountTextBox->TabIndex = 1;
			this->playerAmountTextBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &StartForm::playerAmountTextBox_KeyDown);
			// 
			// moneyTextBox
			// 
			this->moneyTextBox->Location = System::Drawing::Point(141, 79);
			this->moneyTextBox->Name = L"moneyTextBox";
			this->moneyTextBox->Size = System::Drawing::Size(76, 20);
			this->moneyTextBox->TabIndex = 2;
			this->moneyTextBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &StartForm::moneyTextBox_KeyDown);
			// 
			// playerNameTextBox
			// 
			this->playerNameTextBox->Location = System::Drawing::Point(142, 105);
			this->playerNameTextBox->Name = L"playerNameTextBox";
			this->playerNameTextBox->Size = System::Drawing::Size(104, 20);
			this->playerNameTextBox->TabIndex = 3;
			this->playerNameTextBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &StartForm::playerNameTextBox_KeyDown);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(26, 53);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(110, 20);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Player amount";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label2->Location = System::Drawing::Point(41, 79);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(95, 20);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Start money";
			// 
			// PlayerNameLabel
			// 
			this->PlayerNameLabel->AutoSize = true;
			this->PlayerNameLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->PlayerNameLabel->Location = System::Drawing::Point(26, 105);
			this->PlayerNameLabel->Name = L"PlayerNameLabel";
			this->PlayerNameLabel->Size = System::Drawing::Size(109, 20);
			this->PlayerNameLabel->TabIndex = 6;
			this->PlayerNameLabel->Text = L"Player 1 name";
			// 
			// StartForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::DarkOliveGreen;
			this->ClientSize = System::Drawing::Size(284, 192);
			this->Controls->Add(this->PlayerNameLabel);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->playerNameTextBox);
			this->Controls->Add(this->moneyTextBox);
			this->Controls->Add(this->playerAmountTextBox);
			this->Controls->Add(this->StartButton);
			this->Name = L"StartForm";
			this->Text = L"StartForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void playerAmountTextBox_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) 
	{
	}
	private: System::Void moneyTextBox_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) 
	{
	}
	private: System::Void playerNameTextBox_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
	{
	}
	private: System::Void StartButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
	}
};
}