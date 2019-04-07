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
#include <exception>
#include <stdexcept>

#include "parser.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

using namespace std;






TForm1 *Form1;




//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
bool f_accuary= false;
bool flag_ans = false;
	ofstream f;
  double answer_parser  ;
void __fastcall TForm1::Button1Click(TObject *Sender)
{
		String s="",t="";


	TButton *button = dynamic_cast<TButton *>(Sender);
	t = TB_accuracy->Text;
	s = TB_field->Text;
	switch (button->Tag) {
	case 0:
		if (f_accuary) {
			ShowMessage("\t\t\tОшибка ввода.\n\t Вы не можите использовать \'0\' для задания точности.\n \t\tНажмите \"OK\" и продолжите ввод.");
		}else{
		s+='0'; }
		break;
	case 1:
	if(f_accuary){t+='1';}  else {
		s += '1';         }
		break;
	case 2:
		   if(f_accuary){t+='2';}else{
		s += '2';             }
		break;
	case 3:
	if(f_accuary){t+='3';}
	else {
		s +='3';}
		break;
	case 4:
	if (f_accuary) { t+= '4';

	} else{
		s +='4';}
		break;
	case 5:
	if (f_accuary) { t+='5';

	}else{
		s +='5';}
		break;
	case 6:
	if(f_accuary){t+='6';}else {
		s +='6';       }
		break;
	case 7:
	if (f_accuary) { t+='7';

	}else {
		s +='7'; }
		break;
	case 8:  if (f_accuary) {
					t+='8';
			 }else{
		ShowMessage("\t\t\tОшибка ввода.\n\t Используйте числа только из восьмиричной системы \t\t\t\t счисления.\n \t\tНажмите \"OK\" и продолжите ввод.");
	   }
		break;
	case 9:
	if (f_accuary) {
		   t+='9';
	}else{
		ShowMessage("\t\t\tОшибка ввода.\n\t Используйте числа только из восьмиричной системы \t\t\t\t счисления.\n \t\tНажмите \"OK\" и продолжите ввод.");
		  }
		break;
	case 10:
	if(f_accuary){
	ShowMessage(	"\t\t\tОшибка ввода.\n\t Используйте числа только числа для задания точности.\n \t\tНажмите \"OK\" и продолжите ввод.");	// адрес текста в окне сообщений
	}     else{
		s+=" ( ";}
		break;
	case 11:
	if(f_accuary){
		ShowMessage(	"\t\t\tОшибка ввода.\n\t Используйте числа только числа для задания точности.\n \t\tНажмите \"OK\" и продолжите ввод.");
	}  else {
		s+=" ) ";}
		break;
	case 12:
	if (f_accuary) {
			ShowMessage(	"\t\t\tОшибка ввода.\n\t Используйте числа только числа для задания точности.\n \t\tНажмите \"OK\" и продолжите ввод.");
	}else {
		s+=" div ";}
		break;
	case 13:   	if (f_accuary) {
		 t.Delete(t.Length(),1);
	}    else {
		s.Delete(s.Length(),1);}

	   //	s.erase(s.end());
		break;
	 case 14:
	if (f_accuary) {
	 ShowMessage( "\t\t\tОшибка ввода.\n\t Используйте числа только числа для задания точности.\n \t\tНажмите \"OK\" и продолжите ввод.");
	}    else {
		s+=" / ";}
		break;
	 case 15:
	if (f_accuary) {
			ShowMessage(	"\t\t\tОшибка ввода.\n\t Используйте числа только числа для задания точности.\n \t\tНажмите \"OK\" и продолжите ввод.");
	}else {
		s+=" * ";}
		break;
	 case 16:
	if(f_accuary){
		ShowMessage(	"\t\t\tОшибка ввода.\n\t Используйте числа только числа для задания точности.\n \t\tНажмите \"OK\" и продолжите ввод.");
		}else {
		s+=" - ";}
		break;
	  case 17:
		 if(f_accuary){
			ShowMessage(	"\t\t\tОшибка ввода.\n\t Используйте числа только числа для задания точности.\n \t\tНажмите \"OK\" и продолжите ввод.");
		 }else {
		s+=" + ";}
		break;
	   case 19:

		 if (f_accuary) {
		 ShowMessage(	"\t\t\tОшибка ввода.\n\t Используйте числа только числа для задания точности.\n \t\tНажмите \"OK\" и продолжите ввод.");

		 }   else {
		s+='.';
		}
		break;
	   case 20:
		if (f_accuary){f_accuary=false;}
		else{f_accuary=true;}
		break;


	  case 18:
	  if( TB_field->Text==""){
		 ShowMessage(	"\t\t\tВведите выражение.\n \t\tНажмите \"OK\", чтобы продолжить.");
	  }
	  else{
	  flag_ans = true;
	  s+=' ';
	  f.open(file_name.c_str());

			if (f.is_open()) {
				f << " Введенное выражение: ";
				  AnsiString r= s;
				f << r.c_str() <<  endl;
				f << "\n 1.Преобразование выражения из инфиксной записи в постфиксную\n для определения последовательности действий : ";
			}

			f << endl;
			f.close();

			if (TB_accuracy->Text =="") {t+='1';}

			 AnsiString ans_s = s;

			 TB_accuracy->Text = t;

			 try {

			answer_parser = string_to_double( parser(ans_s.c_str(), 8, file_name.c_str(), StrToInt(t)).c_str());

		  } catch (const Exception &e){

			  ShowMessage(	"\t\t\tВведите  корректное выражение.\n \t\tНажмите \"OK\", чтобы продолжить.");
			 s="";     flag_ans=false;
		  }

	   }

	  if (flag_ans)	s =  FloatToStr(answer_parser) ;


		break;


	}


	TB_field->Text = s;
	TB_accuracy->Text = t;
	/*if (!flag_ans) {
	TB_field->Text = s;
	TB_accuracy->Text = t;

	}   else {
	s =  FloatToStr(answer_parser) ;
	TB_field->Text = s;
	TB_accuracy->Text = t;

	}                      */

}
//---------------------------------------------------------------------------
void __fastcall TForm1::BT_showResultClick(TObject *Sender)
{
         	string label_text="";
	string line;
	ifstream in(file_name.c_str()); // окрываем файл для чтения
	if (in.is_open())
	{
	while (getline(in, line))
	{
	label_text = label_text + line.c_str() + '\n';
	}
	}
	in.close();
	Form2->Label1->Caption = label_text.c_str();
	Form2->ShowModal();

}
//---------------------------------------------------------------------------




