#pragma once

namespace OurLab {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� Graph
	/// </summary>
	public ref class Graph : public System::Windows::Forms::Form
	{
	public:
		Graph(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}
	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~Graph()
		{
			if (components)
			{
				delete components;
			}
		}





	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;

	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		/// <summary>
		/// ��������� ���������� ������������.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// ������������ ����� ��� ��������� ������������ - �� ���������
		/// ���������� ������� ������ ��� ������ ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->SuspendLayout();
			// 
			// Graph
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(868, 489);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Graph";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"������";
			this->Load += gcnew System::EventHandler(this, &Graph::Graph_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void notifyIcon1_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	}
	private: System::Void trackBar1_Scroll(System::Object^  sender, System::EventArgs^  e) 
	{
				 label2->Text = trackBar1->Value.ToString();
	}

private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
{
			 
}

private: System::Void chart1_Click(System::Object^  sender, System::EventArgs^  e) {
}

private: System::Void Graph_Load(System::Object^  sender, System::EventArgs^  e) {
}
		 
};
}
