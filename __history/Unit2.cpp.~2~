//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "Unit2.h"
#include <iostream>
#include <cstdlib>
#include <stack>
#include <fstream>
#include <string>
#include <math.h>
#include <iomanip>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;

using namespace std;
  string file_name = "detailed_answer_kr.txt";
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
	string line;
			ifstream in(file_name.c_str()); // окрываем файл для чтения
			if (in.is_open())
			{
				while (getline(in, line))
				{
					 Label1->Caption= Label1->Caption + line.c_str() + '\n';
				}
			}
			in.close();     // закрываем файл

}
//---------------------------------------------------------------------------
