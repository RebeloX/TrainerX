#pragma once
#include "trainer.hpp"

namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	Trainer trainer;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected:
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::HScrollBar^  hScrollBar1;
	private: System::Windows::Forms::HScrollBar^  hScrollBar2;
	private: System::Windows::Forms::HScrollBar^  hScrollBar3;
	private: System::Windows::Forms::Panel^  panel1;
	private: int r, g, b, index;
	private: System::Windows::Forms::Button^  button2;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->hScrollBar1 = (gcnew System::Windows::Forms::HScrollBar());
			this->hScrollBar2 = (gcnew System::Windows::Forms::HScrollBar());
			this->hScrollBar3 = (gcnew System::Windows::Forms::HScrollBar());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(197, 76);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Set";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 81);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(38, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Health";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Health", L"Money", L"Armour", L"Bar Color" });
			this->comboBox1->Location = System::Drawing::Point(16, 38);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(259, 21);
			this->comboBox1->TabIndex = 2;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedIndexChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(107, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(47, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"TrainerX";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(54, 78);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(137, 20);
			this->textBox1->TabIndex = 4;
			// 
			// hScrollBar1
			// 
			this->hScrollBar1->Location = System::Drawing::Point(15, 123);
			this->hScrollBar1->Maximum = 255;
			this->hScrollBar1->Name = L"hScrollBar1";
			this->hScrollBar1->Size = System::Drawing::Size(260, 20);
			this->hScrollBar1->TabIndex = 5;
			this->hScrollBar1->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &MyForm::hScrollBar1_Scroll);
			// 
			// hScrollBar2
			// 
			this->hScrollBar2->Location = System::Drawing::Point(15, 157);
			this->hScrollBar2->Name = L"hScrollBar2";
			this->hScrollBar2->Size = System::Drawing::Size(260, 20);
			this->hScrollBar2->TabIndex = 6;
			this->hScrollBar2->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &MyForm::hScrollBar2_Scroll);
			// 
			// hScrollBar3
			// 
			this->hScrollBar3->Location = System::Drawing::Point(15, 192);
			this->hScrollBar3->Name = L"hScrollBar3";
			this->hScrollBar3->Size = System::Drawing::Size(260, 20);
			this->hScrollBar3->TabIndex = 7;
			this->hScrollBar3->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &MyForm::hScrollBar3_Scroll);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Maroon;
			this->panel1->Location = System::Drawing::Point(53, 83);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(137, 16);
			this->panel1->TabIndex = 8;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(12, 38);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(263, 23);
			this->button2->TabIndex = 9;
			this->button2->Text = L"start";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(300, 110);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->hScrollBar3);
			this->Controls->Add(this->hScrollBar2);
			this->Controls->Add(this->hScrollBar1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		
		hScrollBar1->Maximum = 255;
		hScrollBar1->Minimum = 0;

		hScrollBar2->Maximum = 255;
		hScrollBar2->Minimum = 0;

		hScrollBar3->Maximum = 255;
		hScrollBar3->Minimum = 0;

		ClientSize = System::Drawing::Size(300, 110);
		hScrollBar1->Hide();
		hScrollBar2->Hide();
		hScrollBar3->Hide();
		panel1->Hide();
		textBox1->Hide();
		button1->Hide();
		comboBox1->Hide();
		label1->Hide();

	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		if (index == 3)
		{
			trainer.SetHealthBarColor(r, g, b, 255);
		} else if (MessageBox::Show(
			L"Are you using numbers? If you use invalid data your game can crash", L"Warning", MessageBoxButtons::OKCancel, 
			MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::OK)
		{
			
			switch (index)
			{
				case 0:
					trainer.SetLife((float)System::Convert::ToDouble(textBox1->Text));
				break;
				case 1:
					trainer.SetMoney(System::Convert::ToInt32(textBox1->Text));
				break;
				case 2:
					trainer.SetArmor((float)System::Convert::ToDouble(textBox1->Text));
				break;
				default:
					break;
			}
		}
		
	}
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		index = comboBox1->SelectedIndex;
		if (index == 3)
		{
			ClientSize = System::Drawing::Size(300, 277);
			textBox1->Hide();
			hScrollBar1->Show();
			hScrollBar2->Show();
			hScrollBar3->Show();
			panel1->Show();
		}
		else {
			ClientSize = System::Drawing::Size(300, 110);
			hScrollBar1->Hide();
			hScrollBar2->Hide();
			hScrollBar3->Hide();
			panel1->Hide();
			textBox1->Show();
		}
		label1->Text = L"" + comboBox1->SelectedItem;
	}
	private: System::Void hScrollBar1_Scroll(System::Object^  sender, System::Windows::Forms::ScrollEventArgs^  e) {
		label1->Text = L"" + hScrollBar1->Value;
		r = hScrollBar1->Value;
		panel1->BackColor = Color::FromArgb(r, g, b);
	}
	private: System::Void hScrollBar2_Scroll(System::Object^  sender, System::Windows::Forms::ScrollEventArgs^  e) {
		label1->Text = L"" + hScrollBar2->Value;
		b = hScrollBar2->Value;
		panel1->BackColor = Color::FromArgb(r, g, b);
	}
	private: System::Void hScrollBar3_Scroll(System::Object^  sender, System::Windows::Forms::ScrollEventArgs^  e) {
		label1->Text = L"" + hScrollBar3->Value;
		g = hScrollBar3->Value;
		panel1->BackColor = Color::FromArgb(r, g, b);
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		if (!trainer.memory.InitializeMemoryHandler())
		{
			MessageBox::Show(L"We couldn't find the gta_sa.exe process!", L"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			Close();
		}
		button2->Hide();
		comboBox1->Show();
		textBox1->Show();
		button1->Show();
		label1->Show();
		comboBox1->SelectedIndex = 0;
	}
};

	[STAThread]
	int main(array<System::String ^> ^args)
	{
		Application::EnableVisualStyles();
		Application::SetCompatibleTextRenderingDefault(false);
		Application::Run(gcnew MyForm());
		return 0;
	}
}

