#pragma once

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ Search;
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
			this->SuspendLayout();
			// 
			// Search
			// 
			this->Search->Location = System::Drawing::Point(12, 349);
			this->Search->Name = L"Search";
			this->Search->Size = System::Drawing::Size(75, 23);
			this->Search->TabIndex = 0;
			this->Search->Text = L"Search";
			this->Search->UseVisualStyleBackColor = true;
			this->Search->Click += gcnew System::EventHandler(this, &Form1::Search_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(546, 452);
			this->Controls->Add(this->Search);
			this->Name = L"Form1";
			this->Text = L"Search Azimuth Date";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Search_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
