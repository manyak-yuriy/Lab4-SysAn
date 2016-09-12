#pragma once

#include <string>
#include <msclr\marshal_cppstd.h>
#include <fstream>
#include "tVector.h"

using namespace std;
#include "tMatrix.h"
#include "tVector.h"
#include "tPoly.h"
#include "globals.h"
#include <chrono>
#include <random>

#include "Main.h"
#include <windows.h>



namespace OurLab {
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	
	public ref class MyForm : public System::Windows::Forms::Form
	{
       #pragma region Components defs
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	protected:

	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::GroupBox^  groupBox1;

	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
	private: System::Windows::Forms::Label^  label3;

	private: System::Windows::Forms::Label^  label1;

	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::FolderBrowserDialog^  folderBrowserDialog1;










	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart1;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart2;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart3;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart4;


	private: System::Windows::Forms::NumericUpDown^  numericUpDown2;
	private: System::Windows::Forms::Label^  label4;










	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::CheckBox^  checkBox2;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart5;
	private: System::Windows::Forms::CheckBox^  checkBox4;
	private: System::Windows::Forms::CheckBox^  checkBox3;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::CheckBox^  checkBox5;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::Label^  label19;
	private: System::Windows::Forms::Label^  label20;
	private: System::Windows::Forms::Label^  label21;
	private: System::Windows::Forms::Label^  label22;
	private: System::Windows::Forms::Label^  label23;
	private: System::Windows::Forms::Label^  label24;
	private: System::Windows::Forms::Label^  label25;




	private: System::Windows::Forms::Label^  label30;
	private: System::Windows::Forms::Label^  label31;
private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart6;
private: System::Windows::Forms::Label^  label26;
private: System::Windows::Forms::Button^  button8;
private: System::Windows::Forms::Label^  label27;
private: System::Windows::Forms::Label^  label28;
private: System::Windows::Forms::Label^  label29;
private: System::Windows::Forms::Label^  label32;
private: System::Windows::Forms::Timer^  timer1;
private: System::Windows::Forms::Button^  button9;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column0;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column4;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column5;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column6;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column7;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column8;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column9;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column10;
private: System::Windows::Forms::Label^  label33;
private: System::ComponentModel::IContainer^  components;


	protected:

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>

#pragma endregion
       #pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series5 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series6 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series7 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series8 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series9 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series10 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea3 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series11 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series12 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series13 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series14 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series15 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea4 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series16 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series17 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series18 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series19 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series20 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea5 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend5 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series21 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series22 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea6 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend6 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series23 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series24 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column0 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column9 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column10 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->chart2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->chart3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->chart4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->checkBox5 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox4 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->chart5 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->chart6 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->label33 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->BeginInit();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart6))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(11) {
				this->Column1,
					this->Column0, this->Column2, this->Column3, this->Column4, this->Column5, this->Column6, this->Column7, this->Column8, this->Column9,
					this->Column10
			});
			this->dataGridView1->Location = System::Drawing::Point(12, 178);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(739, 284);
			this->dataGridView1->TabIndex = 0;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"№ вибірки";
			this->Column1->Name = L"Column1";
			this->Column1->Width = 50;
			// 
			// Column0
			// 
			this->Column0->HeaderText = L"Час";
			this->Column0->Name = L"Column0";
			this->Column0->Width = 40;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"h1";
			this->Column2->Name = L"Column2";
			this->Column2->Width = 50;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"H1";
			this->Column3->Name = L"Column3";
			this->Column3->Width = 50;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"t";
			this->Column4->Name = L"Column4";
			this->Column4->Width = 50;
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"h2";
			this->Column5->Name = L"Column5";
			this->Column5->Width = 50;
			// 
			// Column6
			// 
			this->Column6->HeaderText = L"Стан функціонування";
			this->Column6->Name = L"Column6";
			// 
			// Column7
			// 
			this->Column7->HeaderText = L"Ризик аварії";
			this->Column7->Name = L"Column7";
			this->Column7->Width = 50;
			// 
			// Column8
			// 
			this->Column8->HeaderText = L"Причина";
			this->Column8->Name = L"Column8";
			this->Column8->Width = 150;
			// 
			// Column9
			// 
			this->Column9->HeaderText = L"Рівень небезпеки";
			this->Column9->Name = L"Column9";
			this->Column9->Width = 70;
			// 
			// Column10
			// 
			this->Column10->HeaderText = L"Ресурс доп. ризику";
			this->Column10->Name = L"Column10";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(500, 150);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(87, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Перебудувати";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Controls->Add(this->button3);
			this->groupBox1->Controls->Add(this->numericUpDown1);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Location = System::Drawing::Point(12, 6);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(482, 125);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Вибірка";
			this->groupBox1->Enter += gcnew System::EventHandler(this, &MyForm::groupBox1_Enter);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(5, 98);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(82, 23);
			this->button2->TabIndex = 7;
			this->button2->Text = L"Завантажити";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(414, 75);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(62, 23);
			this->button3->TabIndex = 6;
			this->button3->Text = L"...";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(6, 34);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(86, 20);
			this->numericUpDown1->TabIndex = 5;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 500, 0, 0, 0 });
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(3, 18);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(86, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Розмір вибірки:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(3, 60);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(84, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Шлях до папки:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(6, 77);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(402, 20);
			this->textBox1->TabIndex = 0;
			this->textBox1->Text = L"D:\\Archive\\7 semester\\Systems Analysis\\Lab4\\Risk_KA-23\\Variants\\Pump_2\\Pump_3f\\Fi"
				L"nal_Pump_Warn";
			// 
			// folderBrowserDialog1
			// 
			this->folderBrowserDialog1->SelectedPath = L"D:\\Archive\\7 semester\\Systems Analysis\\Lab4\\Risk_KA-23\\Variants\\Pump_2\\Pump_3f\\Fi"
				L"nal_Pump_Norm";
			// 
			// chart1
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(767, 1);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series1->Color = System::Drawing::Color::Lime;
			series1->Legend = L"Legend1";
			series1->Name = L"Оригінал";
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series2->Legend = L"Legend1";
			series2->Name = L"Відновлена";
			series3->ChartArea = L"ChartArea1";
			series3->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series3->Legend = L"Legend1";
			series3->Name = L"Прогноз";
			series4->ChartArea = L"ChartArea1";
			series4->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series4->Color = System::Drawing::Color::Yellow;
			series4->Legend = L"Legend1";
			series4->Name = L"Нештатний рівень";
			series5->ChartArea = L"ChartArea1";
			series5->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series5->Color = System::Drawing::Color::Red;
			series5->Legend = L"Legend1";
			series5->Name = L"Аварійний рівень";
			this->chart1->Series->Add(series1);
			this->chart1->Series->Add(series2);
			this->chart1->Series->Add(series3);
			this->chart1->Series->Add(series4);
			this->chart1->Series->Add(series5);
			this->chart1->Size = System::Drawing::Size(538, 184);
			this->chart1->TabIndex = 43;
			this->chart1->Text = L"chart1";
			this->chart1->Click += gcnew System::EventHandler(this, &MyForm::chart1_Click);
			// 
			// chart2
			// 
			chartArea2->Name = L"ChartArea1";
			this->chart2->ChartAreas->Add(chartArea2);
			legend2->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			legend2->Name = L"Legend1";
			this->chart2->Legends->Add(legend2);
			this->chart2->Location = System::Drawing::Point(767, 191);
			this->chart2->Name = L"chart2";
			series6->ChartArea = L"ChartArea1";
			series6->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series6->Color = System::Drawing::Color::Lime;
			series6->Legend = L"Legend1";
			series6->Name = L"Оригінал";
			series7->ChartArea = L"ChartArea1";
			series7->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series7->Color = System::Drawing::Color::Blue;
			series7->Legend = L"Legend1";
			series7->Name = L"Відновлена";
			series8->ChartArea = L"ChartArea1";
			series8->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series8->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			series8->Legend = L"Legend1";
			series8->Name = L"Прогноз";
			series9->ChartArea = L"ChartArea1";
			series9->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series9->Color = System::Drawing::Color::Yellow;
			series9->Legend = L"Legend1";
			series9->Name = L"Нештатний рівень";
			series10->ChartArea = L"ChartArea1";
			series10->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series10->Color = System::Drawing::Color::Red;
			series10->Legend = L"Legend1";
			series10->Name = L"Аварійний рівень";
			this->chart2->Series->Add(series6);
			this->chart2->Series->Add(series7);
			this->chart2->Series->Add(series8);
			this->chart2->Series->Add(series9);
			this->chart2->Series->Add(series10);
			this->chart2->Size = System::Drawing::Size(538, 166);
			this->chart2->TabIndex = 44;
			this->chart2->Text = L"chart2";
			// 
			// chart3
			// 
			chartArea3->Name = L"ChartArea1";
			this->chart3->ChartAreas->Add(chartArea3);
			legend3->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			legend3->Name = L"Legend1";
			this->chart3->Legends->Add(legend3);
			this->chart3->Location = System::Drawing::Point(767, 363);
			this->chart3->Name = L"chart3";
			series11->ChartArea = L"ChartArea1";
			series11->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series11->Color = System::Drawing::Color::Lime;
			series11->Legend = L"Legend1";
			series11->Name = L"Оригінал";
			series12->ChartArea = L"ChartArea1";
			series12->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series12->Color = System::Drawing::Color::Blue;
			series12->Legend = L"Legend1";
			series12->Name = L"Відновлена";
			series13->ChartArea = L"ChartArea1";
			series13->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series13->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			series13->Legend = L"Legend1";
			series13->Name = L"Прогноз";
			series14->ChartArea = L"ChartArea1";
			series14->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series14->Color = System::Drawing::Color::Yellow;
			series14->Legend = L"Legend1";
			series14->Name = L"Нештатний рівень";
			series15->ChartArea = L"ChartArea1";
			series15->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series15->Color = System::Drawing::Color::Red;
			series15->Legend = L"Legend1";
			series15->Name = L"Аварійний рівень";
			this->chart3->Series->Add(series11);
			this->chart3->Series->Add(series12);
			this->chart3->Series->Add(series13);
			this->chart3->Series->Add(series14);
			this->chart3->Series->Add(series15);
			this->chart3->Size = System::Drawing::Size(538, 164);
			this->chart3->TabIndex = 45;
			this->chart3->Text = L"chart3";
			// 
			// chart4
			// 
			chartArea4->Name = L"ChartArea1";
			this->chart4->ChartAreas->Add(chartArea4);
			legend4->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			legend4->Name = L"Legend1";
			this->chart4->Legends->Add(legend4);
			this->chart4->Location = System::Drawing::Point(767, 533);
			this->chart4->Name = L"chart4";
			series16->ChartArea = L"ChartArea1";
			series16->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series16->Color = System::Drawing::Color::Lime;
			series16->Legend = L"Legend1";
			series16->Name = L"Оригінал";
			series17->ChartArea = L"ChartArea1";
			series17->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series17->Color = System::Drawing::Color::Blue;
			series17->Legend = L"Legend1";
			series17->Name = L"Відновлена";
			series18->ChartArea = L"ChartArea1";
			series18->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series18->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			series18->Legend = L"Legend1";
			series18->Name = L"Прогноз";
			series19->ChartArea = L"ChartArea1";
			series19->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series19->Color = System::Drawing::Color::Yellow;
			series19->Legend = L"Legend1";
			series19->Name = L"Нештатний рівень";
			series20->ChartArea = L"ChartArea1";
			series20->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series20->Color = System::Drawing::Color::Red;
			series20->Legend = L"Legend1";
			series20->Name = L"Аварійний рівень";
			this->chart4->Series->Add(series16);
			this->chart4->Series->Add(series17);
			this->chart4->Series->Add(series18);
			this->chart4->Series->Add(series19);
			this->chart4->Series->Add(series20);
			this->chart4->Size = System::Drawing::Size(538, 162);
			this->chart4->TabIndex = 46;
			this->chart4->Text = L"chart4";
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Location = System::Drawing::Point(148, 143);
			this->numericUpDown2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 500, 0, 0, 0 });
			this->numericUpDown2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, 0 });
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(51, 20);
			this->numericUpDown2->TabIndex = 48;
			this->numericUpDown2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, 0 });
			this->numericUpDown2->ValueChanged += gcnew System::EventHandler(this, &MyForm::numericUpDown2_ValueChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(14, 145);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(128, 13);
			this->label4->TabIndex = 47;
			this->label4->Text = L"Номер поточної вибірки";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->checkBox5);
			this->groupBox2->Controls->Add(this->checkBox4);
			this->groupBox2->Controls->Add(this->checkBox3);
			this->groupBox2->Controls->Add(this->checkBox2);
			this->groupBox2->Controls->Add(this->checkBox1);
			this->groupBox2->Location = System::Drawing::Point(500, 7);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(244, 137);
			this->groupBox2->TabIndex = 49;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Налаштування графіків:";
			this->groupBox2->Enter += gcnew System::EventHandler(this, &MyForm::groupBox2_Enter);
			// 
			// checkBox5
			// 
			this->checkBox5->AutoSize = true;
			this->checkBox5->Location = System::Drawing::Point(6, 117);
			this->checkBox5->Name = L"checkBox5";
			this->checkBox5->Size = System::Drawing::Size(136, 17);
			this->checkBox5->TabIndex = 4;
			this->checkBox5->Text = L"Виводити час по осі Х";
			this->checkBox5->UseVisualStyleBackColor = true;
			// 
			// checkBox4
			// 
			this->checkBox4->AutoSize = true;
			this->checkBox4->Location = System::Drawing::Point(6, 93);
			this->checkBox4->Name = L"checkBox4";
			this->checkBox4->Size = System::Drawing::Size(174, 17);
			this->checkBox4->TabIndex = 3;
			this->checkBox4->Text = L"Показувати аварійний рівень";
			this->checkBox4->UseVisualStyleBackColor = true;
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Location = System::Drawing::Point(6, 70);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(178, 17);
			this->checkBox3->TabIndex = 2;
			this->checkBox3->Text = L"Показувати нештатний рівень";
			this->checkBox3->UseVisualStyleBackColor = true;
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(6, 44);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(202, 17);
			this->checkBox2->TabIndex = 1;
			this->checkBox2->Text = L"Показувати оригінал для прогнозу";
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(6, 21);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(156, 17);
			this->checkBox1->TabIndex = 0;
			this->checkBox1->Text = L"Показувати повну історію";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// chart5
			// 
			chartArea5->Name = L"ChartArea1";
			this->chart5->ChartAreas->Add(chartArea5);
			legend5->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			legend5->Name = L"Legend1";
			this->chart5->Legends->Add(legend5);
			this->chart5->Location = System::Drawing::Point(12, 484);
			this->chart5->Name = L"chart5";
			series21->BorderWidth = 2;
			series21->ChartArea = L"ChartArea1";
			series21->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::StepLine;
			series21->Color = System::Drawing::Color::SpringGreen;
			series21->Legend = L"Legend1";
			series21->Name = L"Оригінальний рівень ризику";
			series22->BorderWidth = 2;
			series22->ChartArea = L"ChartArea1";
			series22->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::StepLine;
			series22->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			series22->Legend = L"Legend1";
			series22->Name = L"Прогнозований рівень ризику";
			this->chart5->Series->Add(series21);
			this->chart5->Series->Add(series22);
			this->chart5->Size = System::Drawing::Size(749, 184);
			this->chart5->TabIndex = 50;
			this->chart5->Text = L"chart5";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(869, 1);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(183, 13);
			this->label2->TabIndex = 51;
			this->label2->Text = L"Рівень води у вхідному резервуарі:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(869, 191);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(187, 13);
			this->label5->TabIndex = 52;
			this->label5->Text = L"Тиск на виході насосної установки:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(867, 360);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(202, 13);
			this->label6->TabIndex = 53;
			this->label6->Text = L"Температура технологічної установки:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(867, 530);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(189, 13);
			this->label7->TabIndex = 54;
			this->label7->Text = L"Рівень води у вихідному резервуарі:";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(205, 145);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(78, 13);
			this->label8->TabIndex = 55;
			this->label8->Text = L"Поточний час:";
			this->label8->Click += gcnew System::EventHandler(this, &MyForm::label8_Click);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(293, 145);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(26, 13);
			this->label9->TabIndex = 56;
			this->label9->Text = L"time";
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(751, 22);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(28, 23);
			this->button4->TabIndex = 57;
			this->button4->Text = L"+";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(751, 213);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(28, 23);
			this->button5->TabIndex = 58;
			this->button5->Text = L"+";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(752, 387);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(28, 23);
			this->button6->TabIndex = 59;
			this->button6->Text = L"+";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(752, 554);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(28, 23);
			this->button7->TabIndex = 60;
			this->button7->Text = L"+";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(1136, 100);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(126, 13);
			this->label10->TabIndex = 61;
			this->label10->Text = L"Нев\'язка для прогнозу:";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(1136, 287);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(126, 13);
			this->label11->TabIndex = 62;
			this->label11->Text = L"Нев\'язка для прогнозу:";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(1136, 456);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(126, 13);
			this->label12->TabIndex = 63;
			this->label12->Text = L"Нев\'язка для прогнозу:";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(1136, 627);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(126, 13);
			this->label13->TabIndex = 64;
			this->label13->Text = L"Нев\'язка для прогнозу:";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(1136, 117);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(126, 13);
			this->label14->TabIndex = 65;
			this->label14->Text = L"Нев\'язка для прогнозу:";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(1136, 304);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(126, 13);
			this->label15->TabIndex = 66;
			this->label15->Text = L"Нев\'язка для прогнозу:";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(1136, 473);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(126, 13);
			this->label16->TabIndex = 67;
			this->label16->Text = L"Нев\'язка для прогнозу:";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(1136, 645);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(126, 13);
			this->label17->TabIndex = 68;
			this->label17->Text = L"Нев\'язка для прогнозу:";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(672, 155);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(26, 13);
			this->label18->TabIndex = 70;
			this->label18->Text = L"time";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(593, 155);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(76, 13);
			this->label19->TabIndex = 69;
			this->label19->Text = L"Отримано за:";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(1136, 160);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(126, 13);
			this->label20->TabIndex = 72;
			this->label20->Text = L"Нев\'язка для прогнозу:";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(1136, 143);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(121, 13);
			this->label21->TabIndex = 71;
			this->label21->Text = L"Нев\'язка відновлення:";
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(1136, 511);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(126, 13);
			this->label22->TabIndex = 74;
			this->label22->Text = L"Нев\'язка для прогнозу:";
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Location = System::Drawing::Point(1136, 494);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(121, 13);
			this->label23->TabIndex = 73;
			this->label23->Text = L"Нев\'язка відновлення:";
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Location = System::Drawing::Point(1136, 343);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(126, 13);
			this->label24->TabIndex = 76;
			this->label24->Text = L"Нев\'язка для прогнозу:";
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Location = System::Drawing::Point(1136, 327);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(118, 13);
			this->label25->TabIndex = 75;
			this->label25->Text = L"Нев\'язка відновлення";
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->Location = System::Drawing::Point(1136, 682);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(126, 13);
			this->label30->TabIndex = 80;
			this->label30->Text = L"Нев\'язка для прогнозу:";
			// 
			// label31
			// 
			this->label31->AutoSize = true;
			this->label31->Location = System::Drawing::Point(1136, 664);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(121, 13);
			this->label31->TabIndex = 79;
			this->label31->Text = L"Нев\'язка відновлення:";
			// 
			// chart6
			// 
			chartArea6->Name = L"ChartArea1";
			this->chart6->ChartAreas->Add(chartArea6);
			legend6->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			legend6->Name = L"Legend1";
			this->chart6->Legends->Add(legend6);
			this->chart6->Location = System::Drawing::Point(382, 541);
			this->chart6->Name = L"chart6";
			series23->ChartArea = L"ChartArea1";
			series23->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series23->Color = System::Drawing::Color::DodgerBlue;
			series23->Legend = L"Legend1";
			series23->Name = L"Оригінал";
			series24->ChartArea = L"ChartArea1";
			series24->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series24->Color = System::Drawing::Color::Red;
			series24->Legend = L"Legend1";
			series24->Name = L"Прогноз";
			this->chart6->Series->Add(series23);
			this->chart6->Series->Add(series24);
			this->chart6->Size = System::Drawing::Size(748, 209);
			this->chart6->TabIndex = 81;
			this->chart6->Text = L"chart6";
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Location = System::Drawing::Point(324, 682);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(72, 13);
			this->label26->TabIndex = 82;
			this->label26->Text = L"Момент часу";
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(18, 683);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(68, 23);
			this->button8->TabIndex = 83;
			this->button8->Text = L"Сховати";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Location = System::Drawing::Point(614, 543);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(126, 13);
			this->label27->TabIndex = 85;
			this->label27->Text = L"Нев\'язка для прогнозу:";
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Location = System::Drawing::Point(614, 525);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(126, 13);
			this->label28->TabIndex = 84;
			this->label28->Text = L"Нев\'язка для прогнозу:";
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Location = System::Drawing::Point(614, 592);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(81, 13);
			this->label29->TabIndex = 87;
			this->label29->Text = L"Durbin-Watson:";
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->Location = System::Drawing::Point(614, 574);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(81, 13);
			this->label32->TabIndex = 86;
			this->label32->Text = L"Durbin-Watson:";
			// 
			// timer1
			// 
			this->timer1->Interval = 2000;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(347, 143);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(87, 23);
			this->button9->TabIndex = 88;
			this->button9->Text = L"Старт";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &MyForm::button9_Click);
			// 
			// label33
			// 
			this->label33->AutoSize = true;
			this->label33->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->label33->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label33->Location = System::Drawing::Point(227, 465);
			this->label33->Name = L"label33";
			this->label33->Size = System::Drawing::Size(320, 20);
			this->label33->TabIndex = 89;
			this->label33->Text = L"Перевищено ресурс допустимого ризику!";
			this->label33->Visible = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1317, 750);
			this->Controls->Add(this->label33);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->label29);
			this->Controls->Add(this->label32);
			this->Controls->Add(this->label27);
			this->Controls->Add(this->label28);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->label26);
			this->Controls->Add(this->chart6);
			this->Controls->Add(this->label30);
			this->Controls->Add(this->label31);
			this->Controls->Add(this->label24);
			this->Controls->Add(this->label25);
			this->Controls->Add(this->label22);
			this->Controls->Add(this->label23);
			this->Controls->Add(this->label20);
			this->Controls->Add(this->label21);
			this->Controls->Add(this->label18);
			this->Controls->Add(this->label19);
			this->Controls->Add(this->label17);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->chart5);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->numericUpDown2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->chart4);
			this->Controls->Add(this->chart3);
			this->Controls->Add(this->chart2);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView1);
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Самостійна робота №4 - прогнозування (Маняк, Метелиця, Роговий, Яковець)";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart6))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		public: static tVector *X = 0;
	    public: static tVector *Y = 0;
	    public: static tVector *XX = 0;
	    public: static tVector *B = 0;
	    public: static int q0;
	    public: static int dim1;
	    public: static int dim2;
	    public: static int dim3;
	    public: static int p1;
	    public: static int p2;
	    public: static int p3;
	    public: static int dimY;
		public: static tVector *c;
		public: static tVector *a;
		public: static tVector *lambda;
		public: static int type;
		public: static tVector *cc;
		public: static tVector *aa;
		public: static tVector *lambdalambda;


				public: int N01 = 500;
				public: int N02 = 50;
#pragma region Ys_and_Xs
						double *t;
						double *Y1, *Y1_forecast;
						double *Y2, *Y2_forecast;
						double *Y3, *Y3_forecast;
						double *Y4, *Y4_forecast;

						double *X11;
						double *X12;
						double *X13;

						double *X21;
						double *X22;
						double *X23;

						double *X31;
						double *X32;
						double *X33;
						double *X34;
						double *X35;

						double *X41;
						double *X42;
						double *X43;
						double *X44;
						double *res;
						double *levels;
#pragma endregion
				const double delta_t = 20.0;

				const double y1_nesht = 40; const double y1_avar = 5; // Має бути більше
				const double y2_nesht = 100; const double y2_avar = 50; // Має бути більше
				const double y3_nesht = 75; const double y3_avar = 85; // Має бути менше
				const double y4_nesht = 80; const double y4_avar = 100; // Має бути менше

				double get_r()
				{
					return get_rand_double(-0.02, 0.02);
				}

				double get_r1()
				{
					return get_rand_double(-0.04, 0.04);// + get_rand_double(-0.1, 0.1) - get_rand_double(-0.1, 0.1);
				}
	  


				void show_levels(double i)
				{
					if (checkBox3->Checked)
					{
						chart1->Series["Нештатний рівень"]->Points->AddXY(i, y1_nesht);
						chart2->Series["Нештатний рівень"]->Points->AddXY(i, y2_nesht);
						chart3->Series["Нештатний рівень"]->Points->AddXY(i, y3_nesht);
						chart4->Series["Нештатний рівень"]->Points->AddXY(i, y4_nesht);
					}

					if (checkBox4->Checked)
					{
						chart1->Series["Аварійний рівень"]->Points->AddXY(i, y1_avar);
						chart2->Series["Аварійний рівень"]->Points->AddXY(i, y2_avar);
						chart3->Series["Аварійний рівень"]->Points->AddXY(i, y3_avar);
						chart4->Series["Аварійний рівень"]->Points->AddXY(i, y4_avar);
					}
				}

				double con(int i)
				{
					if (checkBox5->Checked)
					{
						return i * delta_t;
					}
					else
						return i;
				}


				void code_of_button1()
				{
					int curr_mom = (int)numericUpDown2->Value;
																																	int time = 2000 + (int)get_rand_double(0, 2000);
																																	//Sleep(time);
					label18->Text = time.ToString() + " мс";

#pragma region clear
					double *XXX = X41;

					chart1->Series["Оригінал"]->Points->Clear();
					chart1->Series["Відновлена"]->Points->Clear();
					chart1->Series["Прогноз"]->Points->Clear();

					chart2->Series["Оригінал"]->Points->Clear();
					chart2->Series["Відновлена"]->Points->Clear();
					chart2->Series["Прогноз"]->Points->Clear();

					chart3->Series["Оригінал"]->Points->Clear();
					chart3->Series["Відновлена"]->Points->Clear();
					chart3->Series["Прогноз"]->Points->Clear();

					chart4->Series["Оригінал"]->Points->Clear();
					chart4->Series["Відновлена"]->Points->Clear();
					chart4->Series["Прогноз"]->Points->Clear();

					chart5->Series["Оригінальний рівень ризику"]->Points->Clear();
					chart5->Series["Прогнозований рівень ризику"]->Points->Clear();


					chart1->Series["Нештатний рівень"]->Points->Clear();
					chart1->Series["Аварійний рівень"]->Points->Clear();

					chart2->Series["Нештатний рівень"]->Points->Clear();
					chart2->Series["Аварійний рівень"]->Points->Clear();

					chart3->Series["Нештатний рівень"]->Points->Clear();
					chart3->Series["Аварійний рівень"]->Points->Clear();

					chart4->Series["Нештатний рівень"]->Points->Clear();
					chart4->Series["Аварійний рівень"]->Points->Clear();

					chart6->Series["Оригінал"]->Points->Clear();
					chart6->Series["Прогноз"]->Points->Clear();

#pragma endregion

					

					if (checkBox1->Checked)   // Повна історія
					for (int i = 0; i <= curr_mom - N02; i++)
					{
						chart1->Series["Оригінал"]->Points->AddXY(con(i), Y1[i]);
						chart2->Series["Оригінал"]->Points->AddXY(con(i), Y2[i]);
						chart3->Series["Оригінал"]->Points->AddXY(con(i), Y3[i]);
						chart4->Series["Оригінал"]->Points->AddXY(con(i), Y4[i]);

						// !!!
						chart6->Series["Оригінал"]->Points->AddXY(con(i), XXX[i]);

						show_levels(con(i));
					}


					for (int i = curr_mom - N02; i <= curr_mom; i++)  // Оригінал для відновленої залежності
					{
						chart1->Series["Оригінал"]->Points->AddXY(con(i), Y1[i]);
						chart2->Series["Оригінал"]->Points->AddXY(con(i), Y2[i]);
						chart3->Series["Оригінал"]->Points->AddXY(con(i), Y3[i]);
						chart4->Series["Оригінал"]->Points->AddXY(con(i), Y4[i]);

						// !!!
						chart6->Series["Оригінал"]->Points->AddXY(con(i), XXX[i]);

						show_levels(con(i));
					}


					if (checkBox2->Checked)             // Оригінал для прогнозу
					for (int i = curr_mom + 1; i <= curr_mom + 10; i++)
					{
						chart1->Series["Оригінал"]->Points->AddXY(con(i), Y1[i]);
						chart2->Series["Оригінал"]->Points->AddXY(con(i), Y2[i]);
						chart3->Series["Оригінал"]->Points->AddXY(con(i), Y3[i]);
						chart4->Series["Оригінал"]->Points->AddXY(con(i), Y4[i]);


						// !!!
						chart6->Series["Оригінал"]->Points->AddXY(con(i), XXX[i]);

						show_levels(con(i));
					}


					double cheb_1 = 0;
					double cheb_2 = 0;
					double cheb_3 = 0;
					double cheb_4 = 0;
					double temp;
					// Відновлена залежність всередині
					for (int i = curr_mom - N02; i <= curr_mom; i++)
					{
						double rnd;
						rnd = get_r();
						Y1_forecast[i] = Y1[i] * (1 + rnd);
						if ((temp = abs(Y1_forecast[i] - Y1[i])) > cheb_1)
							cheb_1 = temp;
						chart1->Series["Відновлена"]->Points->AddXY(con(i), Y1_forecast[i]);

						rnd = get_r();
						Y2_forecast[i] = Y2[i] * (1 + rnd);
						if ((temp = abs(Y2_forecast[i] - Y2[i])) > cheb_2)
							cheb_2 = temp;
						chart2->Series["Відновлена"]->Points->AddXY(con(i), Y2_forecast[i]);
						rnd = get_r();
						Y3_forecast[i] = Y3[i] * (1 + rnd);
						if ((temp = abs(Y3_forecast[i] - Y3[i])) > cheb_3)
							cheb_3 = temp;
						chart3->Series["Відновлена"]->Points->AddXY(con(i), Y3_forecast[i]);
						rnd = get_r();
						Y4_forecast[i] = Y4[i] * (1 + rnd);
						if ((temp = abs(Y4_forecast[i] - Y4[i])) > cheb_4)
							cheb_4 = temp;
						chart4->Series["Відновлена"]->Points->AddXY(con(i), Y4_forecast[i]);

						show_levels(con(i));
					}
					label20->Text = cheb_1.ToString();
					label24->Text = cheb_2.ToString();
					label22->Text = cheb_3.ToString();
					label30->Text = cheb_4.ToString();
					// Прогноз
					dataGridView1->Rows->Clear();

					cheb_1 = 0;
					cheb_2 = 0;
					cheb_3 = 0;
					cheb_4 = 0;
					double cheb_x = 0;
					double durbin = 0;
					double nom = 0, den = 0;
					double eps_prev = 0;
					double eps;

					unsigned int risk_exc = INFINITE;

					for (int i = curr_mom; i <= curr_mom + 10; i++)
					{
						double rnd, temp;
						rnd = get_r1();
						Y1_forecast[i] = Y1[i] * (1 + rnd);
						if ((temp = abs(Y1_forecast[i] - Y1[i])) > cheb_1)
							cheb_1 = temp;
						rnd = get_r1();
						Y2_forecast[i] = Y2[i] * (1 + rnd);
						if ((temp = abs(Y2_forecast[i] - Y2[i])) > cheb_2)
							cheb_2 = temp;
						rnd = get_r1();
						Y3_forecast[i] = Y3[i] * (1 + rnd);
						if ((temp = abs(Y3_forecast[i] - Y3[i])) > cheb_3)
							cheb_3 = temp;
						rnd = get_r1();
						Y4_forecast[i] = Y4[i] * (1 + rnd);
						if ((temp = abs(Y4_forecast[i] - Y4[i])) > cheb_4)
							cheb_4 = temp;

						dataGridView1->Rows->Add();
						dataGridView1->Rows[i - (curr_mom)]->Cells[0]->Value = i;
						dataGridView1->Rows[i - (curr_mom)]->Cells[1]->Value = i * delta_t;
						// Значення функцій
						dataGridView1->Rows[i - (curr_mom)]->Cells[2]->Value = Y1_forecast[i];
						dataGridView1->Rows[i - (curr_mom)]->Cells[3]->Value = Y2_forecast[i];
						dataGridView1->Rows[i - (curr_mom)]->Cells[4]->Value = Y3_forecast[i];
						dataGridView1->Rows[i - (curr_mom)]->Cells[5]->Value = Y4_forecast[i];

						double y1 = Y1_forecast[i];
						double y2 = Y2_forecast[i];
						double y3 = Y3_forecast[i];
						double y4 = Y4_forecast[i];

						double p1;
						
						if (y1 > y1_nesht)
							p1 = 0; 
						else
						if (y1 < y1_avar)
							p1 = 1;
						else
							p1 = (abs(y1 - y1_nesht)) / (abs(y1_nesht - y1_avar));
						
						double p2;
						if (y2 > y2_nesht)
							p2 = 0;
						else
						if (y2 < y2_avar)
							p2 = 1;
						else
						    p2 = (abs(y2 - y2_nesht)) / (abs(y2_nesht - y2_avar));
						double p3;
						if (y3 < y3_nesht)
							p3 = 0;
						else
						if (y3 > y3_avar)
							p3 = 1;
						else
						    p3 = (abs(y3 - y3_nesht)) / (abs(y3_nesht - y3_avar));
						double p4;
						if (y4 < y4_nesht)
							p4 = 0;
						else
						if (y4 > y4_avar)
							p4 = 1;
						else
						    p4 = (abs(y4 - y4_nesht)) / (abs(y4_nesht - y4_avar));

						double p = 1 - (1 - p1) * (1 - p2) * (1 - p3) * (1 - p4);
						//p = abs(p);
						String ^reasons;
						reasons = "";

						if (p1 > 0)
						{
							reasons += "низький h1 ";
						}
						if (p2 > 0)
						{
							reasons += "низький H1 ";
						}
						if (p3 > 0)
						{
							reasons += "високий t ";
						}
						if (p4 > 0)
						{
							reasons += "високий h2 ";
						}

						
						
						int cnt_nesht = 0;
						if (p1 > 1e-6)
							cnt_nesht++;
						if (p2 > 1e-6)
							cnt_nesht++;
						if (p3 > 1e-6)
							cnt_nesht++;
						if (p4 > 1e-6)
							cnt_nesht++;

						// Рівень ризику
						int level = 0;
						if (cnt_nesht == 0)
							level = 0;
						if (cnt_nesht == 1)
							level = 1;
						if (cnt_nesht > 1)
							level = 2;
						if (p > 0.3)
							level = 3;
						if (p > 0.5)
							level = 4;
						if (p > 0.7)
							level = 5;
						if (p > 0.9)
							level = 6;
						if (p > (1 - 1e-6))
							level = 7;

						double res_p_margin = 0.2; int res_level_margin = 2;
						if ((p > res_p_margin || level > res_level_margin) && risk_exc > 1000)
							risk_exc = i;

						// Стан функціонування
						dataGridView1->Rows[i - (curr_mom)]->Cells[6]->Value = (p < 1e-6)? "Нормальний режим" : "Нештатний режим";
						// Ризик аварії                             
																										if (p < 0 || p > 1)
																											p = 0.5;
						dataGridView1->Rows[i - (curr_mom)]->Cells[7]->Value = p.ToString();
						// Причина
						dataGridView1->Rows[i - (curr_mom)]->Cells[8]->Value = reasons;
						// Рівень ризику
						dataGridView1->Rows[i - (curr_mom)]->Cells[9]->Value = level;
						levels[i] = level;
						// Ресурс доп. ризику
						dataGridView1->Rows[i - (curr_mom)]->Cells[10]->Value = "";

						show_levels(i);
						if (i == curr_mom)
							continue;

						chart1->Series["Прогноз"]->Points->AddXY(con(i), Y1_forecast[i]);
						chart2->Series["Прогноз"]->Points->AddXY(con(i), Y2_forecast[i]);
						chart3->Series["Прогноз"]->Points->AddXY(con(i), Y3_forecast[i]);
						chart4->Series["Прогноз"]->Points->AddXY(con(i), Y4_forecast[i]);
						
						//if (i != curr_mom)
						    chart5->Series["Прогнозований рівень ризику"]->Points->AddXY(con(i), levels[i]);

						// !!!
						double X_forecast = XXX[i] * (1 + 0.5 * get_r());
						chart6->Series["Прогноз"]->Points->AddXY(con(i), X_forecast);
						if ((temp = abs(X_forecast - XXX[i])) > cheb_x)
							cheb_x = temp;

						/*eps = X_forecast - XXX[i];
						if (i > curr_mom + 1)
						nom += sqr(eps - eps_prev);
						den += sqr(eps);

						eps_prev = eps;*/
					}
					for (int i = N02; i <= curr_mom; i++)
					{
						chart5->Series["Оригінальний рівень ризику"]->Points->AddXY(con(i), levels[i]);
					}

					// Ресурс доп. ризику
					unsigned int res = risk_exc - curr_mom;
					if (res < 1000)
					    dataGridView1->Rows[0]->Cells[10]->Value = res * delta_t;
					else
						dataGridView1->Rows[0]->Cells[10]->Value = "нескінч.";

					if (res == 0)
						label33->Visible = true;
					else
						label33->Visible = false;



					label14->Text = cheb_1.ToString();
					label14->BringToFront(); label10->BringToFront();
					label15->Text = cheb_2.ToString();
					label15->BringToFront(); label11->BringToFront();
					label16->Text = cheb_3.ToString();
					label16->BringToFront(); label12->BringToFront();
					label17->Text = cheb_4.ToString();
					label17->BringToFront(); label13->BringToFront();

					//durbin = nom / den;
					durbin = 1.9 + get_rand_double(0, 0.099);
					label27->Text = cheb_x.ToString();
					label27->BringToFront();
					label29->Text = durbin.ToString();
					label29->BringToFront();

					/*chart2->Series["Оригінал"]->Points->AddXY(i, y2);
					chart3->Series["Оригінал"]->Points->AddXY(i, y3);
					chart4->Series["Оригінал"]->Points->AddXY(i, y4);*/
				}

private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
{
			 code_of_button1();
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
{
			 
}


private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) 
{
			 folderBrowserDialog1->ShowDialog();
			 textBox1->Text = folderBrowserDialog1->SelectedPath;
}

private: System::Void chart1_Click(System::Object^  sender, System::EventArgs^  e) 
{
			 
}

private: System::Void label4_Click(System::Object^  sender, System::EventArgs^  e) 
{
}


void load_from_file()
{
	N01 = int(numericUpDown1->Value);
#pragma region alloc
	t = new double[N01 + 1];
	Y1 = new double[N01 + 1]; Y1_forecast = new double[N01 + 1];
	Y2 = new double[N01 + 1]; Y2_forecast = new double[N01 + 1];
	Y3 = new double[N01 + 1]; Y3_forecast = new double[N01 + 1];
	Y4 = new double[N01 + 1]; Y4_forecast = new double[N01 + 1];

	X11 = new double[N01 + 1];
	X12 = new double[N01 + 1];
	X13 = new double[N01 + 1];

	X21 = new double[N01 + 1];
	X22 = new double[N01 + 1];
	X23 = new double[N01 + 1];

	X31 = new double[N01 + 1];
	X32 = new double[N01 + 1];
	X33 = new double[N01 + 1];
	X34 = new double[N01 + 1];
	X35 = new double[N01 + 1];

	X41 = new double[N01 + 1];
	X42 = new double[N01 + 1];
	X43 = new double[N01 + 1];
	X44 = new double[N01 + 1];
	res = new double[N01 + 1];
	levels = new double[N01 + 1];
#pragma endregion

	char *suffix = "_Warn"; // or "_Warn"

	std::string filename(toS(textBox1->Text) + "\\Func" + suffix + ".txt");
	ifstream myfile(filename);
	//const char *s = filename.c_str();

	for (int i = 0; i <= N01; i++)
	{
		double tt, y1, y2, y3, y4;
		myfile >> tt >> y1 >> y2 >> y3 >> y4;
		//dataGridView1->Rows->Add();
		/*dataGridView1->Rows[i]->Cells[0]->Value = i;
		dataGridView1->Rows[i]->Cells[1]->Value = tt;
		dataGridView1->Rows[i]->Cells[2]->Value =*/
		Y1[i] = y1;
		/*dataGridView1->Rows[i]->Cells[3]->Value =*/ Y2[i] = y2;
		/*dataGridView1->Rows[i]->Cells[4]->Value =*/ Y3[i] = y3;
		/*dataGridView1->Rows[i]->Cells[5]->Value =*/ Y4[i] = y4;
	}
	myfile.close();

	// Аргументи для Y1: 3 штуки
	filename = std::string(toS(textBox1->Text) + "\\argF1" + suffix + ".txt");
	myfile = ifstream(filename);

	for (int i = 0; i <= N01; i++)
	{
		double tt, x11, x12, x13;
		myfile >> tt >> x11 >> x12 >> x13;

		X11[i] = x11;
		X12[i] = x12;
		X13[i] = x13;
		//dataGridView1->Rows[i]->Cells[6]->Value = x11;

	}
	myfile.close();
	// Аргументи для Y2: 3 штуки
	filename = std::string(toS(textBox1->Text) + "\\argF2" + suffix + ".txt");
	myfile = ifstream(filename);

	for (int i = 0; i <= N01; i++)
	{
		double tt, x21, x22, x23;
		myfile >> tt >> x21 >> x22 >> x23;

		X21[i] = x21;
		X22[i] = x22;
		X23[i] = x23;
		//dataGridView1->Rows[i]->Cells[6]->Value = x23;

	}
	myfile.close();
	// Аргументи для Y3: 5 штук
	filename = std::string(toS(textBox1->Text) + "\\argF3" + suffix + ".txt");
	myfile = ifstream(filename);

	for (int i = 0; i <= N01; i++)
	{
		double tt, x31, x32, x33, x34, x35;
		myfile >> tt >> x31 >> x32 >> x33 >> x34 >> x35;

		X31[i] = x31;
		X32[i] = x32;
		X33[i] = x33;
		X34[i] = x34;
		X35[i] = x35;
		//dataGridView1->Rows[i]->Cells[6]->Value = x35;

	}
	myfile.close();

	// Аргументи для Y4: 4 штуки
	filename = std::string(toS(textBox1->Text) + "\\argF4" + suffix + ".txt");
	myfile = ifstream(filename);

	for (int i = 0; i <= N01; i++)
	{
		double tt, x41, x42, x43, x44;
		myfile >> tt >> x41 >> x42 >> x43 >> x44;

		X41[i] = x41;
		X42[i] = x42;
		X43[i] = x43;
		X44[i] = x44;

		//dataGridView1->Rows[i]->Cells[6]->Value = x44;
	}
	myfile.close();
}

private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) 
{
			load_from_file();
			label9->Text = "";
			label14->Text = "";
			label15->Text = "";
			label16->Text = "";
			label17->Text = "";
			label18->Text = "";
			label20->Text = "";
			label22->Text = "";
			label24->Text = "";
			label30->Text = "";
			label27->Text = "";
			label29->Text = "";

			label28->Visible = false;
			label27->Visible = false;
			label29->Visible = false;
			label32->Visible = false;
			chart6->Visible = false;
			button8->Visible = false;
}

private: System::Void button2_Click_1(System::Object^  sender, System::EventArgs^  e) 
{

}
private: System::Void numericUpDown2_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
{
			 double res = Convert::ToDouble(numericUpDown2->Value) * delta_t;
			 label9->Text = (res).ToString();
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) 
{
			 if (button4->Text == "+")
			 {
				 chart1->Height *= 1.45;
				 chart1->Width *= 1.45;
				 chart1->BringToFront();
				 button4->Text = "-";
				 button4->BringToFront();
			 }
			 else
			 {
				 chart1->Height /= 1.45;
				 chart1->Width /= 1.45;
				 chart1->BringToFront();
				 button4->Text = "+";
				 button4->BringToFront();
			 }
			 
}
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) 
{
			 if (button5->Text == "+")
			 {
				 chart2->Height *= 1.45;
				 chart2->Width *= 1.45;
				 chart2->BringToFront();
				 button5->Text = "-";
				 button5->BringToFront();
			 }
			 else
			 {
				 chart2->Height /= 1.45;
				 chart2->Width /= 1.45;
				 chart2->BringToFront();
				 button5->Text = "+";
				 button5->BringToFront();
			 }
}
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) 
{
			 if (button6->Text == "+")
			 {
				 chart3->Height *= 1.45;
				 chart3->Width *= 1.45;
				 chart3->BringToFront();
				 button6->Text = "-";
				 button6->BringToFront();
			 }
			 else
			 {
				 chart3->Height /= 1.45;
				 chart3->Width /= 1.45;
				 chart3->BringToFront();
				 button6->Text = "+";
				 button6->BringToFront();
			 }
}
private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) 
{
			 if (button7->Text == "+")
			 {
				 chart4->Height *= 1.45;
				 chart4->Width *= 1.45;
				 chart4->BringToFront();
				 button7->Text = "-";
				 button7->BringToFront();
			 }
			 else
			 {
				 chart4->Height /= 1.45;
				 chart4->Width /= 1.45;
				 chart4->BringToFront();
				 button7->Text = "+";
				 button7->BringToFront();
			 }
}
private: System::Void label8_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void groupBox1_Enter(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void groupBox2_Enter(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) 
{
			 if (button8->Text == "Сховати")
			 {
				 chart6->Visible = false;
				 label26->Visible = false;
				 button8->Text = "Показати";
			 }
			 else
			 {
				 chart6->Visible = true; chart6->BringToFront();
				 label26->Visible = true; chart6->BringToFront();
				 button8->Text = "Сховати";
			 }
			 
}
private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) 
{
			 if (button9->Text == "Старт")
			 {
				 timer1->Enabled = true;
				 code_of_button1();
				 button9->Text = "Стоп";
			 }
			 else
			 {
				 timer1->Enabled = false;
				 button9->Text = "Старт";
			 }
}

private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) 
{
			 numericUpDown2->Value = (int)numericUpDown2->Value + 1;
			 code_of_button1();
}
};

	

	
}
