#pragma once

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Xml;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void);

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1();

	private: System::Windows::Forms::Button^ Search;
	private: System::Windows::Forms::TextBox^ out_textBox;
	private: System::Windows::Forms::ComboBox^ listLocation;
	private: System::Windows::Forms::Label^ Location;
	private: System::Windows::Forms::TextBox^ startDate;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ searchTime;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ searchAzi;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ searchObject;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ clearResult;



	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->Search = (gcnew System::Windows::Forms::Button());
			this->out_textBox = (gcnew System::Windows::Forms::TextBox());
			this->listLocation = (gcnew System::Windows::Forms::ComboBox());
			this->Location = (gcnew System::Windows::Forms::Label());
			this->startDate = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->searchTime = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->searchAzi = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->searchObject = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->clearResult = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// Search
			// 
			this->Search->Location = System::Drawing::Point(12, 220);
			this->Search->Name = L"Search";
			this->Search->Size = System::Drawing::Size(75, 23);
			this->Search->TabIndex = 0;
			this->Search->Text = L"Search";
			this->Search->UseVisualStyleBackColor = true;
			this->Search->Click += gcnew System::EventHandler(this, &Form1::Search_Click);
			// 
			// out_textBox
			// 
			this->out_textBox->Location = System::Drawing::Point(13, 282);
			this->out_textBox->Multiline = true;
			this->out_textBox->Name = L"out_textBox";
			this->out_textBox->Size = System::Drawing::Size(607, 276);
			this->out_textBox->TabIndex = 1;
			// 
			// listLocation
			// 
			this->listLocation->FormattingEnabled = true;
			this->listLocation->Location = System::Drawing::Point(13, 34);
			this->listLocation->Name = L"listLocation";
			this->listLocation->Size = System::Drawing::Size(330, 24);
			this->listLocation->TabIndex = 2;
			// 
			// Location
			// 
			this->Location->AutoSize = true;
			this->Location->Location = System::Drawing::Point(12, 12);
			this->Location->Name = L"Location";
			this->Location->Size = System::Drawing::Size(58, 16);
			this->Location->TabIndex = 3;
			this->Location->Text = L"Location";
			// 
			// startDate
			// 
			this->startDate->Location = System::Drawing::Point(15, 93);
			this->startDate->Name = L"startDate";
			this->startDate->Size = System::Drawing::Size(120, 22);
			this->startDate->TabIndex = 4;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(15, 71);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(152, 16);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Start-Date (yyyy-mm-dd)";
			// 
			// searchTime
			// 
			this->searchTime->Location = System::Drawing::Point(220, 92);
			this->searchTime->Name = L"searchTime";
			this->searchTime->Size = System::Drawing::Size(100, 22);
			this->searchTime->TabIndex = 6;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(217, 71);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(88, 16);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Time (hh:mm)";
			// 
			// searchAzi
			// 
			this->searchAzi->Location = System::Drawing::Point(409, 93);
			this->searchAzi->Name = L"searchAzi";
			this->searchAzi->Size = System::Drawing::Size(100, 22);
			this->searchAzi->TabIndex = 8;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(406, 71);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(88, 16);
			this->label3->TabIndex = 9;
			this->label3->Text = L"Azimuth (deg)";
			// 
			// searchObject
			// 
			this->searchObject->Location = System::Drawing::Point(13, 174);
			this->searchObject->Name = L"searchObject";
			this->searchObject->Size = System::Drawing::Size(204, 22);
			this->searchObject->TabIndex = 10;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(9, 146);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(254, 16);
			this->label4->TabIndex = 11;
			this->label4->Text = L"Celestical Object Ra/Dec 2000 (hms dms)";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(12, 263);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(45, 16);
			this->label5->TabIndex = 12;
			this->label5->Text = L"Result";
			// 
			// clearResult
			// 
			this->clearResult->Location = System::Drawing::Point(500, 592);
			this->clearResult->Name = L"clearResult";
			this->clearResult->Size = System::Drawing::Size(108, 23);
			this->clearResult->TabIndex = 13;
			this->clearResult->Text = L"Clear Result";
			this->clearResult->UseVisualStyleBackColor = true;
			this->clearResult->Click += gcnew System::EventHandler(this, &Form1::clearResult_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(746, 649);
			this->Controls->Add(this->clearResult);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->searchObject);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->searchAzi);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->searchTime);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->startDate);
			this->Controls->Add(this->Location);
			this->Controls->Add(this->listLocation);
			this->Controls->Add(this->out_textBox);
			this->Controls->Add(this->Search);
			this->Name = L"Form1";
			this->Text = L"Search Azimuth Date";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Search_Click(System::Object^ sender, System::EventArgs^ e);
    private: System::Void clearResult_Click(System::Object^ sender, System::EventArgs^ e);
};
}
