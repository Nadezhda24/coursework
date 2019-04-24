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
 #include <stdlib.h>
 #include <sstream>
#include "parser.h"
#include <conio.h>
#include <windows.h>
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
double answer_parser;
int  flag_rez = 0;
 int c_b=0;
void __fastcall TForm1::Button1Click(TObject *Sender)
{


	String s="",t="";

	t = TB_accuracy->Text;

	TButton *button = dynamic_cast<TButton *>(Sender);

	s = TB_field->Text;

	switch (button->Tag) {
	case 0:

		if (f_accuary){
		if (t.Length()>0) {
					t+='0';
		}else{
			ShowMessage("������ �����.\n�� �� ������ ������������ \'0\' ��� ������� ��������.\n������� \"OK\" � ���������� ����.");
		}
		}else{
			if (s.Length()>1 ) {
				if ((s[s.Length()-1])==')'  ) {
					ShowMessage( "������ �����.\n������� \"OK\", ��������� ������ � ���������� ����.");
				}else {s+='0';}
			}else {s+='0';}
		}
	break;

	case 1:

	if(f_accuary){t+='1';}
	else{
		if (s.Length()>1) {
			if ((s[s.Length()-1])==')' ) {
				ShowMessage( "������ �����.\n������� \"OK\", ��������� ������ � ���������� ����.");
			}else {s+='1';}
		} else {s+='1';}
	}
	break;

	case 2:

	if(f_accuary){t+='2';}
	else{
		if (s.Length()>1) {
			if ((s[s.Length()-1])==')' ) {
				ShowMessage( "������ �����.\n������� \"OK\", ��������� ������ � ���������� ����.");
			}else {s+='2';}
		} else {s+='2';}
	}
	break;

	case 3:
	if(f_accuary){t+='3';}
	else{
		if (s.Length()>1) {
			if ((s[s.Length()-1])==')' ) {
				ShowMessage( "������ �����.\n������� \"OK\", ��������� ������ � ���������� ����.");
			}else {s+='3';}
		} else {s+='3';}
	}
	break;

	case 4:

	if (f_accuary) { t+= '4';}
	else{
		if (s.Length()>1) {
			if ((s[s.Length()-1])==')' ) {
				ShowMessage( "������ �����.\n������� \"OK\", ��������� ������ � ���������� ����.");
			} else {s+='4';}
		} else {s+='4';}
	}
		break;

	case 5:

	if (f_accuary) { t+='5';}
	else{
		  if (s.Length()>1) {
			if (s[s.Length()-1]==')') {
				ShowMessage( "������ �����.\n������� \"OK\", ��������� ������ � ���������� ����.");
			}else {s+='5';}
		}else {s+='5';}
	}
		break;

	case 6:

	if(f_accuary){t+='6';}
	else{
		if (s.Length()>1) {
			if ((s[s.Length()-1])==')' ) {
				ShowMessage( "������ �����.\n������� \"OK\", ��������� ������ � ���������� ����.");
			}else {s+='6';}
		} else {s+='6';}
	}
		break;

	case 7:
	if (f_accuary) { t+='7';}
	else{
		if (s.Length()>1) {
			if ((s[s.Length()-1])==')' ) {
				ShowMessage( "������ �����.\n������� \"OK\", ��������� ������ � ���������� ����.");
			}  else {s+='7';}
		} else {s+='7';}
	}
	break;

	case 8:
	if (f_accuary) {t+='8';}
	else{
			ShowMessage("������ �����.\n�c��������� ������ ����� �� ������������ ������� ���������.\n��������� ������, ������� \"OK\" � ���������� ����.");
	   }
		break;

	case 9:
	if (f_accuary) {t+='9';}
	else{
		ShowMessage("������ �����.\n�c��������� ������ ����� �� ������������ ������� ���������.\n��������� ������, ������� \"OK\" � ���������� ����.");
		}
	break;

	case 10:

	if(f_accuary){
		ShowMessage( "������ �����.\n����������� ������ ����� ��� ������� ��������.\n������� \"OK\" � ���������� ����.");	// ����� ������ � ���� ���������
	}else{
		if (s.Length() < 1) {s+=" ( ";}
		else if (s.Length() == 1) {
			  if (isdigit(s[s.Length()])||s[s.Length()-1] ==')' ){
				ShowMessage( "������ �����.\n�������� ���� ��������.\n������� \"OK\", ��������� ������ � ���������� ����.");
			  }
			 }
			else {
				if (isdigit(s[s.Length()])||s[s.Length()]=='.'||s[s.Length()-1] ==')' ) {
						ShowMessage( "������ �����.\n�������� ���� ��������.\n������� \"OK\", ��������� ������ � ���������� ����.");
				}else {s+=" ( ";}
			}
			c_b++;
		}
		break;

	case 11:

	if(f_accuary){
		ShowMessage( "������ �����.\n����������� ������ ����� ��� ������� ��������.\n������� \"OK\" � ���������� ����.");
	}else {
	s+=" ) ";
	c_b--;
	}
	break;

	case 12:
	if (f_accuary) {
			ShowMessage( "������ �����.\n����������� ������ ����� ��� ������� ��������.\n������� \"OK\" � ���������� ����.");
	}else{
		if (s.Length()==0) {
			ShowMessage( "������ �����.\n������ � �������� ���������� ���������.\n������� \"OK\" � ���������� ����.");}
		else if (s.Length() > 1){
			 if (s[s.Length()-1]=='(') {
					ShowMessage("������ �����.\n������ � �������� ���������� ���������.\n������� \"OK\" � ���������� ����.");}
		else{
			if (s[s.Length()-1] == '+' || s[s.Length()-1] == '-' || s[s.Length()-1] == '*' ||s[s.Length()-1] == '/' || s[s.Length()-1] == 'v') {
				if (s[s.Length()-1]=='v') {
					s.Delete(s.Length()-4,5);
					s+=" div ";}
				else {
					s.Delete(s.Length()-2,3);
					s+=" div ";}
		   }
		   else {s+=" div ";}
		   }
		}
		else {s+=" div ";}
	}
	break;

	case 13:

	if (f_accuary){t.Delete(t.Length(),1);}
	else {
		if (s.Length()== 0){ShowMessage( "������ �������.\n������� \"OK\" � ������� ���������.");}
		else {
		if (s.Length() > 1){
			if (s.Length() == 2) {
				s.Delete(s.Length(),1);}

			 else if (s[s.Length()-1] == '(' || s[s.Length()-1] == ')' ) {
				s.Delete(s.Length()-2,3);
			   }
			 else if  (s[s.Length()-1] == '+' || s[s.Length()-1] == '-' || s[s.Length()-1] == '*' ||s[s.Length()-1] == '/' || s[s.Length()-1] == 'v'){
					if (s[s.Length()-1] == 'v'){ s.Delete(s.Length()-4,5);}
					else {s.Delete(s.Length()-2,3);}
			}

			else {s.Delete(s.Length(),1);}
				 }

		  else if (s.Length() == 1 || s[s.Length()] == '-' ) {
		   s.Delete(s.Length(),1);
		  }


			else {
				if  (s[s.Length()-1] == '+' || s[s.Length()-1] == '-' || s[s.Length()-1] == '*' ||s[s.Length()-1] == '/' || s[s.Length()-1] == 'v'){
					if (s[s.Length()-1] == 'v'){ s.Delete(s.Length()-4,5);}
					else {s.Delete(s.Length()-2,3);}
			}
		else {s.Delete(s.Length(),1);}
		}
	}
	}
	break;

	case 14:

	if (f_accuary) {
		ShowMessage( "������ �����.\n����������� ������ ����� ��� ������� ��������.\n������� \"OK\" � ���������� ����.");
	}else {
		if (s.Length()==0) {
			ShowMessage( "������ �����.\n������ � �������� ���������� ���������.\n������� \"OK\" � ���������� ����.");}
		else if (s.Length() > 1) {
			if (s[s.Length()-1]=='(') {
					ShowMessage("������ �����.\n������ � �������� ���������� ���������.\n������� \"OK\" � ���������� ����.");}
		else  {

		   if (s[s.Length()-1] == '+' || s[s.Length()-1] == '-' || s[s.Length()-1] == '*' ||s[s.Length()-1] == '/' || s[s.Length()-1] == 'v') {
			   if (s[s.Length()-1]!='v') {s[s.Length()-1] = '/'; }
				else {
					s.Delete(s.Length()-4,5);
					s+=" / ";
				}
		   }
		   else {s+=" / ";} }
		}else {s+=" / ";}
	}
	break;

	case 15:

	if (f_accuary) {
			ShowMessage( "������ �����.\n����������� ������ ����� ��� ������� ��������.\n������� \"OK\" � ���������� ����.");
	}else {
		if (s.Length()==0) {
			ShowMessage("������ �����.\n������ � �������� ���������� ���������.\n������� \"OK\" � ���������� ����.");
		}
		 else if (s.Length() > 1) {
		 if (s[s.Length()-1]=='(') {
					ShowMessage("������ �����.\n������ � �������� ���������� ���������.\n������� \"OK\" � ���������� ����.");}
		else{

	if (s[s.Length()-1] == '+' || s[s.Length()-1] == '-' || s[s.Length()-1] == '*' ||s[s.Length()-1] == '/' || s[s.Length()-1] == 'v') {
			  if (s[s.Length()-1]!='v') {	  s[s.Length()-1] = '*'; }
				else {
				s.Delete(s.Length()-4,5);
				s+=" * ";   }
		   }else {s+=" * "; } }
		   }else {s+=" * ";}
	}
		break;
	 case 16:
	if(f_accuary){
			ShowMessage( "������ �����.\n����������� ������ ����� ��� ������� ��������.\n������� \"OK\" � ���������� ����.");
	}else{
		if (s.Length()==0) {
			ShowMessage("������ �����.\n������ � �������� ���������� ���������.\n������� \"OK\" � ���������� ����.");
		}
		 else if (s.Length() > 1 ) {
		  if (s[s.Length()-1]=='(') {
					ShowMessage("������ �����.\n������ � �������� ���������� ���������.\n������� \"OK\" � ���������� ����.");}
		else{
			if (s[s.Length()-1] == '+' || s[s.Length()-1] == '-' || s[s.Length()-1] == '*' ||s[s.Length()-1] == '/' || s[s.Length()-1] == 'v') {
				if (s[s.Length()-1]!='v') {s[s.Length()-1] = '-'; }
				else {
					s.Delete(s.Length()-4,5);
					s+=" - ";}
			}
		   else {s+=" - ";}}
		 } else {s+=" - ";}
	}
	break;

	case 17:

		 if(f_accuary){
				ShowMessage( "������ �����.\n����������� ������ ����� ��� ������� ��������.\n������� \"OK\" � ���������� ����.");
		 }else {
			if (s.Length()== 0) {
				ShowMessage("������ �����.\n������ � �������� ���������� ���������.\n������� \"OK\" � ���������� ����.");}
			else if (s.Length() > 1) {
			 if (s[s.Length()-1]=='(') {
					ShowMessage("������ �����.\n������ � �������� ���������� ���������.\n������� \"OK\" � ���������� ����.");}
		else{
				if (s[s.Length()-1] == '+' || s[s.Length()-1] == '-' || s[s.Length()-1] == '*' ||s[s.Length()-1] == '/' || s[s.Length()-1] == 'v') {
					if (s[s.Length()-1]!='v') { s[s.Length()-1] = '+'; }
						else {
							s.Delete(s.Length()-4,5);
							s+=" + ";}
				}else {s+=" + ";} }
		   }else {s+=" + ";}
		}
	break;

	case 19:

	if (f_accuary) {
			ShowMessage( "������ �����.\n����������� ������ ����� ��� ������� ��������.\n������� \"OK\" � ���������� ����."); }
	else{
		if (s.Length()==0) {
			ShowMessage("������ �����.\n������� \"OK\" � ���������� ����.");}
		else {
			if (!isdigit(s[s.Length()])) {
				ShowMessage("������ �����.\n������� \"OK\" � ���������� ����.");}
			else {s+='.';}
		}
	}
	break;

	case 18:

	  if( TB_field->Text==""){
		 ShowMessage("������� ���������.\n������� \"OK\", ����� ����������.");}
	  else{
		flag_ans = true;
		if (s[s.Length()-1] == '+' || s[s.Length()-1] == '-' || s[s.Length()-1] == '*' ||s[s.Length()-1] == '/' || s[s.Length()-1] == 'v'){
		ShowMessage( "������ �����.\n������ � �������� ���������� ���������.\n��������� ������, ������� \"OK\" � ���������� ����.");

		}else {
		s+=' ';
		f.open(file_name.c_str());

		if (f.is_open()) {
			f << " ��������� ���������: ";
			AnsiString r= s;
			f << r.c_str() <<  endl;
			f << "\n 1.�������������� ��������� �� ��������� ������ � �����������\n ��� ����������� ������������������ �������� : ";
		}

		f << endl;
		f.close();

		if (TB_accuracy->Text =="") {t='1';}
		int toch = StrToInt(t);
		if (toch > 15) {
		   ShowMessage(	"C������ ������� �������� �����.\n������������ �������� 15.\n������� \"OK\", ����� ����������.");
		   t = "15";
	   }
		AnsiString ans_s = s;
		TB_accuracy->Text = t;
		int y=0;

			 try {
				std::stringstream ss;
				std::string s =  parser(ans_s.c_str(), 8, file_name.c_str(), StrToInt(t));
				for (int i=0;i < s.length(); i++){
					if (s[i]==','){
						s[i]='.';
						y=i;
					}
				}

				int i;
				if (y!=0) {
					i=y+1 + StrToInt(t);
					while (i < s.length()){s.erase(i,1);}
				}

				ss << s;
				ss >> answer_parser;

			}catch (const Exception &e){
				ShowMessage("\t\t\t�������  ���������� ���������.\n \t\t������� \"OK\", ����� ����������.");
				s="";
				c_b=0;
				flag_ans=false;
			}

			if (flag_ans) {	s =  FloatToStr(answer_parser) ;

			}


	  }

	}

	break;
	}

	 if (c_b < 0) {
			   ShowMessage("������.\n�� ��������� ������������ ������. \n������� \"OK\" � ������� ���������� ��������� ������.");
				s="";
				c_b=0;
				flag_ans=false;
	 }
	TB_field->Text = s;
	TB_accuracy->Text = t;
	if (f_accuary){
		TB_accuracy->Color= clGradientInactiveCaption;
		TB_field->Color=clBtnHighlight;
	}else {
		TB_field->Color= clGradientInactiveCaption;
		TB_accuracy->Color=clBtnHighlight;
	 }



}
//---------------------------------------------------------------------------
void __fastcall TForm1::BT_showResultClick(TObject *Sender)
{
	string label_text="";
	string line;
	ifstream in(file_name.c_str()); // �������� ���� ��� ������
		if (in.is_open()){
			while (getline(in, line)){
				label_text = label_text + line.c_str() + '\n';
			}
	}
	in.close();
	Form2->Label1->Caption = label_text.c_str();
	Form2->ShowModal();

}
//---------------------------------------------------------------------------




void __fastcall TForm1::Button21Click(TObject *Sender)
{



		if (f_accuary){f_accuary = false;}
		else{f_accuary = true;}

		if (f_accuary){
			TB_accuracy->Color= clGradientInactiveCaption;
			TB_field->Color=clBtnHighlight;
	 }else {
			TB_field->Color= clGradientInactiveCaption;
			TB_accuracy->Color=clBtnHighlight;
	 }

}
//---------------------------------------------------------------------------





void __fastcall TForm1::TB_fieldKeyPress(TObject *Sender, System::WideChar &Key)
{

	if (kbhit) {
				TB_field->ReadOnly = true;
			   ShowMessage("���� � ���������� ��������.\n������� \"OK\", ����� ����������.");

			}


}
//---------------------------------------------------------------------------

