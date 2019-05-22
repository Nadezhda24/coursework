//---------------------------------------------------------------------------

#include <vcl.h>

#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
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
#include <cmath>
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
ofstream f;
double answer_parser;
bool f_accuary= false;
bool flag_ans = false;
int  flag_rez = 0;
 int c_b=0;
 bool f_hex= false, f_dec = true, f_oct = false, f_bin = false;
int  number_system = 10 ;
 String d ="";

 String s_sin = "";
 bool sin_f= false;
 long double ans_sin;
void __fastcall TForm1::Button1Click(TObject *Sender)
{
   double num_hex, num_dec, num_oct, num_bin;

	  String s ="",t ="";

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
				}else {s+='0';d+='0'; s_sin+='0';}
			}else {s+='0';d+='0'; s_sin+='0';}
		}
	break;

	case 1:

	if(f_accuary){t+='1';}
	else{
		if (s.Length()>1) {
			if ((s[s.Length()-1])==')' ) {
				ShowMessage( "������ �����.\n������� \"OK\", ��������� ������ � ���������� ����.");
			}else {s+='1';d+='1';s_sin+='1';}
		} else {s+='1';d+='1';s_sin+='1';}
	}
	break;

	case 2:

	if(f_accuary){t+='2';}
	else{
		if (s.Length()>1) {
			if ((s[s.Length()-1])==')' ) {
				ShowMessage( "������ �����.\n������� \"OK\", ��������� ������ � ���������� ����.");
			}else {s+='2';d+='2';s_sin+='2';}
		} else {s+='2';d+='2';s_sin+='2';}
	}
	break;

	case 3:
	if(f_accuary){t+='3';}
	else{
		if (s.Length()>1) {
			if ((s[s.Length()-1])==')' ) {
				ShowMessage( "������ �����.\n������� \"OK\", ��������� ������ � ���������� ����.");
			}else {s+='3';d+='3';s_sin+='3';}
		} else {s+='3';d+='3';s_sin+='3';}
	}
	break;

	case 4:

	if (f_accuary) { t+= '4';}
	else{
		if (s.Length()>1) {
			if ((s[s.Length()-1])==')' ) {
				ShowMessage( "������ �����.\n������� \"OK\", ��������� ������ � ���������� ����.");
			} else {s+='4';d+='4';s_sin+='4';}
		} else {s+='4';d+='4';s_sin+='4';}
	}
		break;

	case 5:

	if (f_accuary) { t+='5';}
	else{
		  if (s.Length()>1) {
			if (s[s.Length()-1]==')') {
				ShowMessage( "������ �����.\n������� \"OK\", ��������� ������ � ���������� ����.");
			}else {s+='5';d+='5';s_sin+='5';}
		}else {s+='5';d+='5';s_sin+='5';}
	}
		break;

	case 6:

	if(f_accuary){t+='6';}
	else{
		if (s.Length()>1) {
			if ((s[s.Length()-1])==')' ) {
				ShowMessage( "������ �����.\n������� \"OK\", ��������� ������ � ���������� ����.");
			}else {s+='6';d+='6';s_sin+='6';}
		} else {s+='6';d+='6';s_sin+='6';}
	}
		break;

	case 7:
	if (f_accuary) { t+='7';}
	else{
		if (s.Length()>1) {
			if ((s[s.Length()-1])==')' ) {
				ShowMessage( "������ �����.\n������� \"OK\", ��������� ������ � ���������� ����.");
			}  else {s+='7';d+='7';s_sin+='7';}
		} else {s+='7';d+='7';s_sin+='7';}
	}
	break;

	case 8:
	if (f_accuary) { t+='8';}
	else{
		if (s.Length()>1) {
			if ((s[s.Length()-1])==')' ) {
				ShowMessage( "������ �����.\n������� \"OK\", ��������� ������ � ���������� ����.");
			}  else {s+='8';d+='8';s_sin+='8';}
		} else {s+='8';d+='8';s_sin+='8';}
	}
	 break;
	case 9:
	if (f_accuary) { t+='9';}
	else{
		if (s.Length()>1) {
			if ((s[s.Length()-1])==')' ) {
				ShowMessage( "������ �����.\n������� \"OK\", ��������� ������ � ���������� ����.");
			}  else {s+='9';d+='9';s_sin+='9';}
		} else {s+='9';d+='9';s_sin+='9';}
	}
	break;
   case 36:
	if(f_accuary){
		ShowMessage( "������ �����.\n����������� ������ ����� ��� ������� ��������.\n������� \"OK\" � ���������� ����.");	// ����� ������ � ���� ���������
	}else{

		if (s.Length()>1) {
			if ((s[s.Length()-1])==')' ) {
				ShowMessage( "������ �����.\n������� \"OK\", ��������� ������ � ���������� ����.");
			}  else {s+='A';d+='A';}
		} else {s+='A';d+='A';}
	}
	break;
   case 37:
   	if(f_accuary){
		ShowMessage( "������ �����.\n����������� ������ ����� ��� ������� ��������.\n������� \"OK\" � ���������� ����.");	// ����� ������ � ���� ���������
	}else{

		if (s.Length()>1) {
			if ((s[s.Length()-1])==')' ) {
				ShowMessage( "������ �����.\n������� \"OK\", ��������� ������ � ���������� ����.");
			}  else {s+='B';d+='B';}
		} else {s+='B';d+='B';}
	}
	break;
   case 38:
   	if(f_accuary){
		ShowMessage( "������ �����.\n����������� ������ ����� ��� ������� ��������.\n������� \"OK\" � ���������� ����.");	// ����� ������ � ���� ���������
	}else{

		if (s.Length()>1) {
			if ((s[s.Length()-1])==')' ) {
				ShowMessage( "������ �����.\n������� \"OK\", ��������� ������ � ���������� ����.");
			}  else {s+='C';d+='C';}
		} else {s+='C';d+='C';}
	}
	break;
   case 39:
   	if(f_accuary){
		ShowMessage( "������ �����.\n����������� ������ ����� ��� ������� ��������.\n������� \"OK\" � ���������� ����.");	// ����� ������ � ���� ���������
	}else{

		if (s.Length()>1) {
			if ((s[s.Length()-1])==')' ) {
				ShowMessage( "������ �����.\n������� \"OK\", ��������� ������ � ���������� ����.");
			}  else {s+='D';d+='D';}
		} else {s+='D';d+='D';}
	}
	break;
   case 40:
   	if(f_accuary){
		ShowMessage( "������ �����.\n����������� ������ ����� ��� ������� ��������.\n������� \"OK\" � ���������� ����.");	// ����� ������ � ���� ���������
	}else{

		if (s.Length()>1) {
			if ((s[s.Length()-1])==')' ) {
				ShowMessage( "������ �����.\n������� \"OK\", ��������� ������ � ���������� ����.");
			}  else {s+='E';d+='E';}
		} else {s+='E';d+='E';}
	}
	break;
   case 41:
	if(f_accuary){
		ShowMessage( "������ �����.\n����������� ������ ����� ��� ������� ��������.\n������� \"OK\" � ���������� ����.");	// ����� ������ � ���� ���������
	}else{

		if (s.Length()>1) {
			if ((s[s.Length()-1])==')' ) {
				ShowMessage( "������ �����.\n������� \"OK\", ��������� ������ � ���������� ����.");
			}  else {s+='F';d+='F';}
		} else {s+='F';d+='F';}
	}
	break;
    case 42:
     	if(f_accuary){
		ShowMessage( "������ �����.\n����������� ������ ����� ��� ������� ��������.\n������� \"OK\" � ���������� ����.");	// ����� ������ � ���� ���������
	}else{
    if (s.Length()==1) {
      if ( isdigit(s[s.Length()]) || s[s.Length()]=='x' ) {
				ShowMessage( "������ �����.\n�������� ���� ��������.\n������� \"OK\", ��������� ������ � ���������� ����.");
			}   
    }
	 else  if (s.Length()>1) {
			if ((s[s.Length()-1])==')' || isdigit(s[s.Length()]) || s[s.Length()]=='x' ) {
				ShowMessage( "������ �����.\n�������� ���� ��������.\n������� \"OK\", ��������� ������ � ���������� ����.");
			}  else {s+='x';d+="";}
		} else {s+='x';d+="";}
	}
	break;
    
	case 10:

	if(f_accuary){
		ShowMessage( "������ �����.\n����������� ������ ����� ��� ������� ��������.\n������� \"OK\" � ���������� ����.");	// ����� ������ � ���� ���������
	}else{
		if (s.Length() < 1) {s+=" ( ";}
		else if (s.Length() == 1) {
			  if (isdigit(s[s.Length()])||s[s.Length()]=='A'||s[s.Length()]=='B'||s[s.Length()]=='C'||s[s.Length()]=='D'||s[s.Length()]=='E'||s[s.Length()]=='F'||s[s.Length()-1] ==')' ){
				ShowMessage( "������ �����.\n�������� ���� ��������.\n������� \"OK\", ��������� ������ � ���������� ����.");
			  }
			 }
			else {
				if (isdigit(s[s.Length()])||s[s.Length()]=='A'||s[s.Length()]=='B'||s[s.Length()]=='C'||s[s.Length()]=='D'||s[s.Length()]=='E'||s[s.Length()]=='F'||s[s.Length()]=='.'||s[s.Length()-1] ==')' ) {
						ShowMessage( "������ �����.\n�������� ���� ��������.\n������� \"OK\", ��������� ������ � ���������� ����.");
				}else {s+=" ( ";}
			}
			c_b++;
			d ="";

		}
		if (sin_f) {
				ans_sin = sin ( StrToInt(s_sin));
				s +=   FloatToStr(ans_sin);
				TB_field_hex->Text = FloatToStr(ans_sin);
				 sin_f= false;
			}
		break;

	case 11:

	if(f_accuary){
		ShowMessage( "������ �����.\n����������� ������ ����� ��� ������� ��������.\n������� \"OK\" � ���������� ����.");
	}else {
	s+=" ) ";
	c_b--;
	d ="";
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
			if (s[s.Length()-1] == '+' ||s[s.Length()-1] == '^'|| s[s.Length()-1] == '%' || s[s.Length()-1] == '-' || s[s.Length()-1] == '*' ||s[s.Length()-1] == '/' || s[s.Length()-1] == 'v') {
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
		d ="";
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
			 else if  (s[s.Length()-1] == '+' || s[s.Length()-1] == '^'||    s[s.Length()-1] == '%' || s[s.Length()-1] == '-' || s[s.Length()-1] == '*' ||s[s.Length()-1] == '/' || s[s.Length()-1] == 'v'){
					if (s[s.Length()-1] == 'v'){ s.Delete(s.Length()-4,5);}
					else {s.Delete(s.Length()-2,3);}
			}

			else {s.Delete(s.Length(),1);}
				 }

		  else if (s.Length() == 1 || s[s.Length()] == '-' ) {
		   s.Delete(s.Length(),1);
		  }


			else {
				if  (s[s.Length()-1] == '+' || s[s.Length()-1] == '^'||   s[s.Length()-1] == '%' || s[s.Length()-1] == '-' || s[s.Length()-1] == '*' ||s[s.Length()-1] == '/' || s[s.Length()-1] == 'v'){
					if (s[s.Length()-1] == 'v'){ s.Delete(s.Length()-4,5);}
					else {s.Delete(s.Length()-2,3);}
			}
		else {s.Delete(s.Length(),1);}
		}
	}
d.Delete(d.Length(),1);
if (s=="") {
		TB_field_hex->Text= 0;
			TB_field_dec->Text= 0;
				TB_field_oct->Text= 0;
					TB_field_bin->Text= 0;
}
	}
	break;

	case 31:
f_accuary= false;
 flag_ans = false;
  flag_rez = 0;
  c_b=0;
  f_hex= false, f_dec = true, f_oct = false, f_bin = false;
  number_system = 10 ;
 d ="";
 s ="";
 t ="";
 TB_field_hex->Text= 0;
 TB_field_dec->Text= 0;
 TB_field_oct->Text= 0;
 TB_field_bin->Text= 0;
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

		   if (s[s.Length()-1] == '+' || s[s.Length()-1] == '^'||   s[s.Length()-1] == '%' || s[s.Length()-1] == '*' || s[s.Length()-1] == '-' || s[s.Length()-1] == '*' ||s[s.Length()-1] == '/' || s[s.Length()-1] == 'v') {
			   if (s[s.Length()-1]!='v') {s[s.Length()-1] = '/'; }
				else {
					s.Delete(s.Length()-4,5);
					s+=" / ";
				}
		   }
		   else {s+=" / ";} }
		}else {s+=" / ";}
		d ="";
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

	if (s[s.Length()-1] == '+' || s[s.Length()-1] == '^'||    s[s.Length()-1] == '%' ||s[s.Length()-1] == '-' || s[s.Length()-1] == '*' ||s[s.Length()-1] == '/' || s[s.Length()-1] == 'v') {
			  if (s[s.Length()-1]!='v') {	  s[s.Length()-1] = '*'; }
				else {
				s.Delete(s.Length()-4,5);
				s+=" * ";   }
		   }else {s+=" * "; } }
		   }else {s+=" * ";}
		   d ="";
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
			if (s[s.Length()-1] == '+' || s[s.Length()-1] == '^'||   s[s.Length()-1] == '%' || s[s.Length()-1] == '-' || s[s.Length()-1] == '*' ||s[s.Length()-1] == '/' || s[s.Length()-1] == 'v') {
				if (s[s.Length()-1]!='v') {s[s.Length()-1] = '-'; }
				else {
					s.Delete(s.Length()-4,5);
					s+=" - ";}
			}
		   else {s+=" - ";}}
		 } else {s+=" - ";}
		 d ="";
	}
	break;

	case 22 :
	if (f_accuary) {
		ShowMessage( "������ �����.\n����������� ������ ����� ��� ������� ��������.\n������� \"OK\" � ���������� ����.");
	}else {
		if (s.Length()==0) {
			ShowMessage( "������ �����.\n������ � �������� ���������� ���������.\n������� \"OK\" � ���������� ����.");}
		else if (s.Length() > 1) {
			if (s[s.Length()-1]=='(') {
					ShowMessage("������ �����.\n������ � �������� ���������� ���������.\n������� \"OK\" � ���������� ����.");}
		else  {

		   if (s[s.Length()-1] == '+' ||s[s.Length()-1] == '^'|| s[s.Length()-1] == '%' ||s[s.Length()-1] == '-' ||  s[s.Length()-1] == '*' ||s[s.Length()-1] == '/' || s[s.Length()-1] == 'v') {
			   if (s[s.Length()-1]!='v') {s[s.Length()-1] = '%'; }
				else {
					s.Delete(s.Length()-4,5);
					s+=" % ";
				}
		   }
		   else {s+=" % ";} }
		}else {s+=" % ";}
		d ="";
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
				if (s[s.Length()-1] == '+' ||s[s.Length()-1] == '^'|| s[s.Length()-1] == '%' || s[s.Length()-1] == '-' || s[s.Length()-1] == '*' ||s[s.Length()-1] == '/' || s[s.Length()-1] == 'v') {
					if (s[s.Length()-1]!='v') { s[s.Length()-1] = '+'; }
						else {
							s.Delete(s.Length()-4,5);
							s+=" + ";}
				}else {s+=" + ";} }
		   }else {s+=" + ";}
		   d ="";
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
		d ="";
	}
	break;
	
	case 18:

	  if( TB_field->Text==""){
		 ShowMessage("������� ���������.\n������� \"OK\", ����� ����������.");}
	  else{
	  d ="";
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
				std::string s =  parser(ans_s.c_str(),number_system , file_name.c_str(), StrToInt(t));
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
			double Digit;
			if (flag_ans) {

			 s =  FloatToStr(answer_parser) ;
						  d ="" ;
		double SecondDigitStringToDouble = StrToFloat(s.c_str());
		if (number_system==10) {

		Digit = translation_10(SecondDigitStringToDouble, 10,StrToInt(t),file_name);

		// num_hex =  translation(Digit, 16, file_name,StrToInt(t) );
		 num_dec =translation_file(Digit, 10, file_name,StrToInt(t) );
		  num_oct=translation_file(Digit, 8, file_name,StrToInt(t) );
		   num_bin=translation_file(Digit, 2, file_name,StrToInt(t) );




			TB_field_dec->Text= FloatToStr(num_dec);
				TB_field_oct->Text= FloatToStr(num_oct);
					TB_field_bin->Text= FloatToStr(num_bin);
		TB_field_hex->Text= translation( Digit  , 16, file_name,StrToInt(t) ).c_str();
				 }

		   else if (number_system==8) {
		Digit = translation_10(SecondDigitStringToDouble, 8,StrToInt(t),file_name);

		 //num_hex =  translation(Digit, 16, file_name,StrToInt(t) );
		 num_dec =translation_file(Digit, 10, file_name,StrToInt(t) );
		  num_oct=translation_file(Digit, 8, file_name,StrToInt(t) );
		   num_bin=translation_file(Digit, 2, file_name,StrToInt(t) );



		TB_field_hex->Text= translation(Digit, 16, file_name,StrToInt(t) ).c_str();
			TB_field_dec->Text= FloatToStr(num_dec);
				TB_field_oct->Text= FloatToStr(num_oct);
					TB_field_bin->Text= FloatToStr(num_bin);


				}
				else if (number_system==2) {
					Digit = translation_10(SecondDigitStringToDouble, 2,StrToInt(t),file_name);

		// num_hex =  translation(Digit, 16, file_name,StrToInt(t) );
		 num_dec =translation_file(Digit, 10, file_name,StrToInt(t) );
		  num_oct=translation_file(Digit, 8, file_name,StrToInt(t) );
		   num_bin=translation_file(Digit, 2, file_name,StrToInt(t) );



		TB_field_hex->Text=translation(Digit, 16, file_name,StrToInt(t) ).c_str();
			TB_field_dec->Text= FloatToStr(num_dec);
				TB_field_oct->Text= FloatToStr(num_oct);
					TB_field_bin->Text= FloatToStr(num_bin);



					 }          else if (number_system==16) {
		Digit = translation_10(SecondDigitStringToDouble, 16,StrToInt(t),file_name);

		 //num_hex =  translation(Digit, 16, file_name,StrToInt(t) );
		 num_dec =translation_file(Digit, 10, file_name,StrToInt(t) );
		  num_oct=translation_file(Digit, 8, file_name,StrToInt(t) );
		   num_bin=translation_file(Digit, 2, file_name,StrToInt(t) );



		TB_field_hex->Text= translation(Digit, 16, file_name,StrToInt(t) ).c_str();
			TB_field_dec->Text= FloatToStr(num_dec);
				TB_field_oct->Text= FloatToStr(num_oct);
					TB_field_bin->Text= FloatToStr(num_bin);



									 }
			}


	  }

	}

	break;
		case 23:
	 sin_f = true;
	if (f_accuary) {
	ShowMessage( "������ �����.\n");
	}else{
	if (s.Length()==1) {
	  if ( isdigit(s[s.Length()]) ) {
				ShowMessage( "������ �����.\n�������� ���� ��������.\n������� \"OK\", ��������� ������ � ���������� ����.");
			}
	}
	 else  if (s.Length()>1) {
			if ((s[s.Length()-1])==')' || isdigit(s[s.Length()]) ) {
				ShowMessage( "������ �����.\n�������� ���� ��������.\n������� \"OK\", ��������� ������ � ���������� ����.");
			} else { s += " sin ( "; d ="";}
		} else { s += " sin ( "; d ="";}}

		c_b ++;
		break;

	case 24:
	  sin_f = true;
	if (f_accuary) {
	ShowMessage( "������ �����.\n");
	}else{
	if (s.Length()==1) {
	  if ( isdigit(s[s.Length()]) ) {
				ShowMessage( "������ �����.\n�������� ���� ��������.\n������� \"OK\", ��������� ������ � ���������� ����.");
			}
	}
	 else  if (s.Length()>1) {
			if ((s[s.Length()-1])==')' || isdigit(s[s.Length()]) ) {
				ShowMessage( "������ �����.\n�������� ���� ��������.\n������� \"OK\", ��������� ������ � ���������� ����.");
			} else { s += " cos ( "; d ="";}
		} else { s += " cos ( "; d ="";}}

		c_b ++;
		break;
	case 25:
	 sin_f = true;
	if (f_accuary) {
	ShowMessage( "������ �����.\n");
	}else{
	if (s.Length()==1) {
	  if ( isdigit(s[s.Length()]) ) {
				ShowMessage( "������ �����.\n�������� ���� ��������.\n������� \"OK\", ��������� ������ � ���������� ����.");
			}
	}
	 else  if (s.Length()>1) {
			if ((s[s.Length()-1])==')' || isdigit(s[s.Length()]) ) {
				ShowMessage( "������ �����.\n�������� ���� ��������.\n������� \"OK\", ��������� ������ � ���������� ����.");
			} else { s += " tg ( "; d ="";}
		} else { s += " tg ( "; d ="";}}

		c_b ++;
		break;
	break;
	case 26:
	 sin_f = true;
	if (f_accuary) {
	ShowMessage( "������ �����.\n");
	}else{
	if (s.Length()==1) {
	  if ( isdigit(s[s.Length()]) ) {
				ShowMessage( "������ �����.\n�������� ���� ��������.\n������� \"OK\", ��������� ������ � ���������� ����.");
			}
	}
	 else  if (s.Length()>1) {
			if ((s[s.Length()-1])==')' || isdigit(s[s.Length()]) ) {
				ShowMessage( "������ �����.\n�������� ���� ��������.\n������� \"OK\", ��������� ������ � ���������� ����.");
			} else { s += " ctg ( "; d ="";}
		} else { s += " ctg ( "; d ="";}}

		c_b ++;
		break;
	break;

			case 44:
	 sin_f = true;
	if (f_accuary) {
	ShowMessage( "������ �����.\n");
	}else{
	if (s.Length()==1) {
	  if ( isdigit(s[s.Length()]) ) {
				ShowMessage( "������ �����.\n�������� ���� ��������.\n������� \"OK\", ��������� ������ � ���������� ����.");
			}
	}
	 else  if (s.Length()>1) {
			if ((s[s.Length()-1])==')' || isdigit(s[s.Length()]) ) {
				ShowMessage( "������ �����.\n�������� ���� ��������.\n������� \"OK\", ��������� ������ � ���������� ����.");
			} else { s += " arcsin ( "; d ="";}
		} else { s += " arcsin ( "; d ="";}}

		c_b ++;
		break;

	case 45:
	  sin_f = true;
	if (f_accuary) {
	ShowMessage( "������ �����.\n");
	}else{
	if (s.Length()==1) {
	  if ( isdigit(s[s.Length()]) ) {
				ShowMessage( "������ �����.\n�������� ���� ��������.\n������� \"OK\", ��������� ������ � ���������� ����.");
			}
	}
	 else  if (s.Length()>1) {
			if ((s[s.Length()-1])==')' || isdigit(s[s.Length()]) ) {
				ShowMessage( "������ �����.\n�������� ���� ��������.\n������� \"OK\", ��������� ������ � ���������� ����.");
			} else { s += " arccos ( "; d ="";}
		} else { s += " arccos ( "; d ="";}}

		c_b ++;
		break;
	case 46:
	 sin_f = true;
	if (f_accuary) {
	ShowMessage( "������ �����.\n");
	}else{
	if (s.Length()==1) {
	  if ( isdigit(s[s.Length()]) ) {
				ShowMessage( "������ �����.\n�������� ���� ��������.\n������� \"OK\", ��������� ������ � ���������� ����.");
			}
	}
	 else  if (s.Length()>1) {
			if ((s[s.Length()-1])==')' || isdigit(s[s.Length()]) ) {
				ShowMessage( "������ �����.\n�������� ���� ��������.\n������� \"OK\", ��������� ������ � ���������� ����.");
			} else { s += " arctg ( "; d ="";}
		} else { s += " arctg ( "; d ="";}}

		c_b ++;
		break;

	case 47:
	 sin_f = true;
	if (f_accuary) {
	ShowMessage( "������ �����.\n");
	}else{
	if (s.Length()==1) {
	  if ( isdigit(s[s.Length()]) ) {
				ShowMessage( "������ �����.\n�������� ���� ��������.\n������� \"OK\", ��������� ������ � ���������� ����.");
			}
	}
	 else  if (s.Length()>1) {
			if ((s[s.Length()-1])==')' || isdigit(s[s.Length()]) ) {
				ShowMessage( "������ �����.\n�������� ���� ��������.\n������� \"OK\", ��������� ������ � ���������� ����.");
			} else { s += " arcctg ( "; d ="";}
		} else { s += " arcctg ( "; d ="";}}

		c_b ++;
		break;
	break;




	case 27:

	if (f_accuary) { ShowMessage( "������ �����.\n������� \"OK\", ��������� ������ � ���������� ����.");}
	else{
		   if (s.Length()==1&& (isdigit(s[s.Length()])||s[s.Length()-1]=='e'||s[s.Length()-1]=='�'  )) {
			  ShowMessage( "������ �����.\n������� \"OK\", ��������� ������ � ���������� ����.");
		   }
		  else if (s.Length()>1) {
			if (s[s.Length()-1]==')' ||isdigit(s[s.Length()])||s[s.Length()-1]=='e'||s[s.Length()-1]=='�'  ) {
				ShowMessage( "������ �����.\n������� \"OK\", ��������� ������ � ���������� ����.");
			}else {s+=" e ";d+=" e ";}
		}else {s+=" e ";d+=" e ";}
	}
	break;
	case 28:

	if (f_accuary) { ShowMessage( "������ �����.\n������� \"OK\", ��������� ������ � ���������� ����.");}
	else{
		   if (s.Length()==1&& (isdigit(s[s.Length()])||s[s.Length()-1]=='e'||s[s.Length()-1]=='�'  )) {
			  ShowMessage( "������ �����.\n������� \"OK\", ��������� ������ � ���������� ����.");
		   }
		  else if (s.Length()>1) {
			if (s[s.Length()-1]==')' ||isdigit(s[s.Length()])||s[s.Length()-1]=='e'||s[s.Length()-1]=='�'  ) {
				ShowMessage( "������ �����.\n������� \"OK\", ��������� ������ � ���������� ����.");
			}else {s+=" � ";d+=" � ";}
		}else {s+=" � ";d+=" � ";}
	}
	break;
	case 29:
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

	if (s[s.Length()-1] == '+' ||  s[s.Length()-1] == '^'||  s[s.Length()-1] == '%' ||s[s.Length()-1] == '-' || s[s.Length()-1] == '*' ||s[s.Length()-1] == '/' || s[s.Length()-1] == 'v') {
			  if (s[s.Length()-1]!='v') {	  s[s.Length()-1] = '^'; }
				else {
				s.Delete(s.Length()-4,5);
				s+=" ^ ";   }
		   }else {s+=" ^ "; } }
		   }else {s+=" ^ ";}
		   d ="";
	}
		break;
	case 30:

	if (f_accuary) {	ShowMessage( "������ �����.\n����������� ������ ����� ��� ������� ��������.\n������� \"OK\" � ���������� ����.");}
	else{
	   if (s.Length()==1 &&(isdigit(s[s.Length()]) || s[s.Length()]=='!')  ) {
		 ShowMessage( "������ �����.\n������� \"OK\", ��������� ������ � ���������� ����.");
	   }
	   else	if (s.Length()>1) {
			if ((s[s.Length()-1])==')' || isdigit(s[s.Length()]) || s[s.Length()-1]=='!') {
				ShowMessage( "������ �����.\n������� \"OK\", ��������� ������ � ���������� ����.");
			}  else {s+='!';}
		} else {s+='!';}
		   d ="";
	}

	break;
	case 32:
	f_hex = true;
	f_dec = false;
	f_oct = false;
	f_bin = false;
	TB_field_hex->Color=clGradientInactiveCaption;
	TB_field_dec->Color=clBtnHighlight;
	TB_field_oct->Color=clBtnHighlight;
	TB_field_bin->Color=clBtnHighlight;
	Button36->Enabled = true;
	Button37->Enabled = true;
	Button38->Enabled = true;
	Button39->Enabled = true;
	Button40->Enabled = true;
	Button41->Enabled = true;

	Button2->Enabled = true;
	Button14->Enabled = true;

	Button6->Enabled = true;
	Button7->Enabled = true;
	Button9->Enabled = true;
	Button13->Enabled = true;
	Button11->Enabled = true;
	Button10->Enabled = true;
	number_system = 16;
	Label3->Caption = "HEX : ";
	break;
	case 33:
	f_hex = false;
	f_dec = true;
	f_oct = false;
	f_bin = false;
	TB_field_hex->Color=clBtnHighlight;
	TB_field_dec->Color=clGradientInactiveCaption;
	TB_field_oct->Color=clBtnHighlight;
	TB_field_bin->Color=clBtnHighlight;
	Button36->Enabled = false;
	Button37->Enabled = false;
	Button38->Enabled = false;
	Button39->Enabled = false;
	Button40->Enabled = false;
	Button41->Enabled = false;

	Button2->Enabled = true;
	Button14->Enabled = true;

	Button6->Enabled = true;
	Button7->Enabled = true;
	Button9->Enabled = true;
	Button13->Enabled = true;
	Button11->Enabled = true;
	Button10->Enabled = true;
		number_system = 10;
		Label3->Caption = "DEC : ";
	break;
	case 34:
	f_hex = false;
	f_dec = false;
	f_oct = true;
	f_bin = false;
	TB_field_hex->Color=clBtnHighlight;
	TB_field_dec->Color=clBtnHighlight;
	TB_field_oct->Color=clGradientInactiveCaption;
	TB_field_bin->Color=clBtnHighlight;
	Button36->Enabled = false;
	Button37->Enabled = false;
	Button38->Enabled = false;
	Button39->Enabled = false;
	Button40->Enabled = false;
	Button41->Enabled = false;
	Button2->Enabled = false;
	Button14->Enabled = false;

	Button6->Enabled = true;
	Button7->Enabled = true;
	Button9->Enabled = true;
	Button13->Enabled = true;
	Button11->Enabled = true;
	Button10->Enabled = true;
		number_system = 8;
		Label3->Caption = "OCT : ";
	break;
	case 35:
	f_hex = false;
	f_dec = false;
	f_oct = false;
	f_bin = true;
	TB_field_hex->Color=clBtnHighlight;
	TB_field_dec->Color=clBtnHighlight;
	TB_field_oct->Color=clBtnHighlight;
	TB_field_bin->Color=clGradientInactiveCaption;
	Button36->Enabled = false;
	Button37->Enabled = false;
	Button38->Enabled = false;
	Button39->Enabled = false;
	Button40->Enabled = false;
	Button41->Enabled = false;
	Button2->Enabled = false;
	Button14->Enabled = false;
	Button6->Enabled = false;
	Button7->Enabled = false;
	Button9->Enabled = false;
	Button13->Enabled = false;
	Button11->Enabled = false;
	Button10->Enabled = false;
	number_system = 2;
	Label3->Caption = "BIN : ";
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
		 TB_field_hex->Color=clBtnHighlight;
		 TB_field_dec->Color=clBtnHighlight;
		 TB_field_oct->Color=clBtnHighlight;
		 TB_field_bin->Color=clBtnHighlight;
	}else {
		if (f_hex){ TB_field_hex->Color= clGradientInactiveCaption;}
		else if (f_oct) { TB_field_oct->Color= clGradientInactiveCaption;}
		else if (f_bin) {TB_field_bin->Color= clGradientInactiveCaption;}
		else {TB_field_dec->Color= clGradientInactiveCaption;}
		TB_accuracy->Color=clBtnHighlight;
	 }

	if (TB_accuracy->Text =="") {t='1';}

	if (d!="") {

	if (d==" e "){
		 d = "2,71";



	}
	if (d==" � ") {
			 d = "3,14" ;
	}
 if (number_system!=16) {



		double SecondDigitStringToDouble = StrToFloat(d.c_str());
		double	Digit = translation_10(SecondDigitStringToDouble, 10,StrToInt(t),file_name);

		// num_hex = translation(Digit, 16, file_name,StrToInt(t) );
		 num_dec =translation_file(Digit, 10, file_name,StrToInt(t) );
		  num_oct=translation_file(Digit, 8, file_name,StrToInt(t) );
		   num_bin=translation_file(Digit, 2, file_name,StrToInt(t) );



			TB_field_hex->Text =  translation(Digit, 16, file_name,StrToInt(t)).c_str();
			TB_field_dec->Text= FloatToStr(num_dec);
				TB_field_oct->Text= FloatToStr(num_oct);
					TB_field_bin->Text= FloatToStr(num_bin);}
					else{
					AnsiString q = d.c_str();
						double	Digit = translation_16(	q.c_str(), 16, StrToInt(t), file_name)   ;
						 num_dec =translation_file(Digit, 10, file_name,StrToInt(t) );
		  num_oct=translation_file(Digit, 8, file_name,StrToInt(t) );
		   num_bin=translation_file(Digit, 2, file_name,StrToInt(t) );



			TB_field_hex->Text=  translation(Digit, 16, file_name,StrToInt(t) ).c_str();
			TB_field_dec->Text= FloatToStr(num_dec);
				TB_field_oct->Text= FloatToStr(num_oct);
					TB_field_bin->Text= FloatToStr(num_bin);}
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
		TB_field_hex->Color=clBtnHighlight;
		 TB_field_dec->Color=clBtnHighlight;
		 TB_field_oct->Color=clBtnHighlight;
		 TB_field_bin->Color=clBtnHighlight;
	Button36->Enabled = false;
	Button37->Enabled = false;
	Button38->Enabled = false;
	Button39->Enabled = false;
	Button40->Enabled = false;
	Button41->Enabled = false;
	Button12->Enabled = false;
	Button17->Enabled = false;
	Button18->Enabled = false;
	Button19->Enabled = false;
	Button22->Enabled = false;
	Button23->Enabled = false;
	Button24->Enabled = false;
	Button25->Enabled = false;
	Button26->Enabled = false;
	Button31->Enabled = false;
	Button28->Enabled = false;
	Button29->Enabled = false;
	Button30->Enabled = false;
	Button16->Enabled = false;
	Button8->Enabled = false;
	Button4->Enabled = false;
	Button15->Enabled = false;

	Button2->Enabled = true;
	Button14->Enabled = true;
	Button6->Enabled = true;
	Button7->Enabled = true;
	Button9->Enabled = true;
	Button13->Enabled = true;
	Button11->Enabled = true;
	Button10->Enabled = true;



	}else {
		if (f_hex){
		TB_field_hex->Color= clGradientInactiveCaption;


	Button12->Enabled = true;
	Button17->Enabled = true;
	Button18->Enabled = true;
	Button19->Enabled = true;
	Button22->Enabled = true;
	Button23->Enabled = true;
	Button24->Enabled = true;
	Button25->Enabled = true;
	Button26->Enabled = true;
	Button31->Enabled = true;
	Button28->Enabled = true;
	Button29->Enabled = true;
	Button30->Enabled = true;
	Button16->Enabled = true;
	Button8->Enabled = true;
	Button4->Enabled = true;
	Button15->Enabled = true;

	Button36->Enabled = true;
	Button37->Enabled = true;
	Button38->Enabled = true;
	Button39->Enabled = true;
	Button40->Enabled = true;
	Button41->Enabled = true;

	Button2->Enabled = true;
	Button14->Enabled = true;

	Button6->Enabled = true;
	Button7->Enabled = true;
	Button9->Enabled = true;
	Button13->Enabled = true;
	Button11->Enabled = true;
	Button10->Enabled = true;

		}
		else if (f_oct) {
		TB_field_oct->Color= clGradientInactiveCaption;
        Button12->Enabled = true;
	Button17->Enabled = true;
	Button18->Enabled = true;
	Button19->Enabled = true;
	Button22->Enabled = true;
	Button23->Enabled = true;
	Button24->Enabled = true;
	Button25->Enabled = true;
	Button26->Enabled = true;
	Button31->Enabled = true;
	Button28->Enabled = true;
	Button29->Enabled = true;
	Button30->Enabled = true;
	Button16->Enabled = true;
	Button8->Enabled = true;
	Button4->Enabled = true;
	Button15->Enabled = true;

	Button36->Enabled = false;
	Button37->Enabled = false;
	Button38->Enabled = false;
	Button39->Enabled = false;
	Button40->Enabled = false;
	Button41->Enabled = false;
	Button2->Enabled = false;
	Button14->Enabled = false;

	Button6->Enabled = true;
	Button7->Enabled = true;
	Button9->Enabled = true;
	Button13->Enabled = true;
	Button11->Enabled = true;
	Button10->Enabled = true;
		}
		else if (f_bin) {TB_field_bin->Color= clGradientInactiveCaption;
        Button12->Enabled = true;
	Button17->Enabled = true;
	Button18->Enabled = true;
	Button19->Enabled = true;
	Button22->Enabled = true;
	Button23->Enabled = true;
	Button24->Enabled = true;
	Button25->Enabled = true;
	Button26->Enabled = true;
	Button31->Enabled = true;
	Button28->Enabled = true;
	Button29->Enabled = true;
	Button30->Enabled = true;
	Button16->Enabled = true;
	Button8->Enabled = true;
	Button4->Enabled = true;
	Button15->Enabled = true;
	Button36->Enabled = false;
	Button37->Enabled = false;
	Button38->Enabled = false;
	Button39->Enabled = false;
	Button40->Enabled = false;
	Button41->Enabled = false;
	Button2->Enabled = false;
	Button14->Enabled = false;
	Button6->Enabled = false;
	Button7->Enabled = false;
	Button9->Enabled = false;
	Button13->Enabled = false;
	Button11->Enabled = false;
	Button10->Enabled = false;
		}
		else {TB_field_dec->Color= clGradientInactiveCaption;
		Button12->Enabled = true;
	Button17->Enabled = true;
	Button18->Enabled = true;
	Button19->Enabled = true;
	Button22->Enabled = true;
	Button23->Enabled = true;
	Button24->Enabled = true;
	Button25->Enabled = true;
	Button26->Enabled = true;
	Button31->Enabled = true;
	Button28->Enabled = true;
	Button29->Enabled = true;
	Button30->Enabled = true;
	Button16->Enabled = true;
	Button8->Enabled = true;
	Button4->Enabled = true;
	Button15->Enabled = true;
	Button36->Enabled = false;
	Button37->Enabled = false;
	Button38->Enabled = false;
	Button39->Enabled = false;
	Button40->Enabled = false;
	Button41->Enabled = false;

	Button2->Enabled = true;
	Button14->Enabled = true;

	Button6->Enabled = true;
	Button7->Enabled = true;
	Button9->Enabled = true;
	Button13->Enabled = true;
	Button11->Enabled = true;
	Button10->Enabled = true;

	}
		TB_accuracy->Color=clBtnHighlight;
	 }

}
//---------------------------------------------------------------------------





void __fastcall TForm1::TB_field_hexKeyPress(TObject *Sender, System::WideChar &Key)
{

	if (kbhit) {
				TB_field->ReadOnly = true;
				TB_field_hex->ReadOnly = true;
				TB_field_dec->ReadOnly = true;
				TB_field_oct->ReadOnly = true;
				TB_field_bin->ReadOnly = true;
			   ShowMessage("���� � ���������� ��������.\n������� \"OK\", ����� ����������.");

			}


}
//---------------------------------------------------------------------------












void __fastcall TForm1::Button43Click(TObject *Sender)
{

  Form3->Image1->Center = true;
  Form3->Image1->Canvas->Pen->Color = clBlack; // ������������� ���� ����� ������


 int k = 1;
 const r = 2;
 int answer_parser;
  int x;
  String s="";
	s = TB_field->Text;
	if (s=="") {
			ShowMessage( "������� ���������.\n������� \"OK\", � ���������� ����.");
	}   else {
// String s = TB_field->Text;
 s += ' ' ;
 Form3->Label1->Caption = s;

  AnsiString h;
	string str;
  int last_x=300, last_y=300;
   std::stringstream ss;


 for (int x = -50; x < 50; x=x+1) {
	   ProgressBar1->Position += 1;
 if (x < 0) {
	//std::stringstream ss;
	int a = x*(-1);

		ss<<a;
   //	string str;
	ss>>str;

	str = " ( ( 0 - 1 ) * " + str + " ) ";
	}
   else {
	//std::stringstream ss;
	int a = x;
	ss<<a;

	ss>>str;
	}

  int p =0;
  int k = s.Length();
  for (int p = 1; p <= k; p++ ) {



		 if (s[p] == 'x') {

		   AnsiString q = str.c_str();
		  h = h + q;

		 }else {h = h + s[p];}

		 }




				 str =  parser(h.c_str(),number_system , file_name.c_str(), StrToInt(t));

		  double y = (-1)* string_to_double( str );

 if (x == -50) {
	  Form3->Image1->Canvas->Pen->Color = clInactiveBorder;

 }    else {
			  Form3->Image1->Canvas->Pen->Color = clBlack;
 }

  Form3->Image1->Canvas->MoveTo(last_x,last_y);

	// Form3->Image1->Canvas->Ellipse(k *(x)-r+300,k * (y)-r+300, k *(x)+r+300,k * (y)+r+300 );
	h ="";
   str="";
   ss.clear();


 // Form3->Image1->Canvas->MoveTo(k *last_x,k *last_y);
 Form3->Image1->Canvas->LineTo(k *(x)+300,k *(y)+300);

 last_x =k *(x)+300;
  last_y =k *(y)+300;


 }
 Form3->Image1->Canvas->MoveTo(300,0);
  Form3->Image1->Canvas->LineTo(300,500);
  Form3->Image1->Canvas->MoveTo(0,300);
  Form3->Image1->Canvas->LineTo(700,300);

  Form3 ->ShowModal();
  Form3->Image1->Canvas->FillRect(Rect(0,0, Form3->Image1->Width, Form3->Image1->Height));
  ProgressBar1->Position = 0;
  }
}
//---------------------------------------------------------------------------

