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

using namespace std;


enum state { start, digit, double_digit, word, symbol, error };

string z;
stack <string> number_stack;
stack <string> operation_stack;
stack <string> num;

int const ss = 8; // система сисления
string file_name = "detailed_answer_kr.txt";
int count_point = 0; // счетчик точек
bool toch_flag = false; // флаг для ораничения колиества точек в диапозоне одного числа

char s[100] = ""; // строка, содержащая вводимое выражение
int t = 5;

//перевод из 10-ой в 8-ую систему счисления
double translation(double  digit, int ss, int accuracy) {
	accuracy = pow(10, accuracy);
	int str = 0;
	long long answer = 0;
	int whole_part = int(digit); // целая часть
	double fraction = digit - whole_part; // дробная часть
	int n;



	// перевод целой части
	while (whole_part > 0) {

		str++;
		n = whole_part % ss;
		answer = answer * 10 + n;
		whole_part = (whole_part - n) / ss;


	}
	while (answer > 0) {
		n = answer % 10;
		whole_part = whole_part * 10 + n;
		answer = answer / 10;
		str--;
	}
	whole_part = whole_part * pow(10, str);
	double g;
	// перевод дробной части
	if (fraction*accuracy != 0) {

		answer = 0;

		int count_accuracy = 0;
		while (fraction*accuracy != 0) {

			count_accuracy++;

			answer = answer * 10 + (int)(fraction*ss);
			fraction = (fraction*ss) - (int)(fraction*ss);
		}


		g = answer / pow(10, count_accuracy);
	}
	else { g = 0; }


	double ans = whole_part + g;
	return ans;

}
//перевод из 10-ой в 8-ую систему счисления
double translation_file(double  digit, int ss, string file_name, int accuracy) {
	accuracy = pow(10, accuracy);
	int str = 0;
	long long answer = 0;
	int whole_part = int(digit); // целая часть
	double fraction = digit - whole_part; // дробная часть
	int n;

	ofstream f;
	f.open(file_name.c_str(), ios::app);

	f << setw(t) << " Перевод числа " << digit << " в 8-ую систему счисления : " << endl;

	f << setw(t) << " Перевод целой части числа: " << endl;
	f.close();



	// перевод целой части
	while (whole_part > 0) {
		ofstream f;
		f.open(file_name.c_str(), ios::app);
		f.close();
		// перевод целой части
		while (whole_part > 0) {
			f.open(file_name.c_str(), ios::app);
			str++;
			n = whole_part % ss;
			f << whole_part << " % " << ss << " = " << n << endl;
			answer = answer * 10 + n;

			f << " ( " << whole_part << " - " << n << " ) " << " / " << ss;
			whole_part = (whole_part - n) / ss;
			f << " = " << whole_part << endl;

		}

		f.close();
	}
	while (answer > 0) {
		n = answer % 10;
		whole_part = whole_part * 10 + n;
		answer = answer / 10;
		str--;
	}
	whole_part = whole_part * pow(10, str);
	double g;
	// перевод дробной части
	if (fraction*accuracy != 0) {
		f.open(file_name.c_str(), ios::app);
		f << " Перевод дробной части числа : " << endl;

		f.close();

		answer = 0;

		int count_accuracy = 0;
		while (fraction*accuracy != 0) {
			ofstream f;
			f.open(file_name.c_str(), ios::app);
			f << "* " << ss << endl;
			f << "--------" << endl;
			f << " " << fraction * ss << endl;
			f.close();
			count_accuracy++;

			answer = answer * 10 + (int)(fraction*ss);
			fraction = (fraction*ss) - (int)(fraction*ss);
		}

		g = answer / pow(10, count_accuracy);
	}
	else { g = 0; }


	double ans = whole_part + g;
	return ans;

}

// перевод из 8-ой в 10-ую
double translation_10(double digit, int ss, int accuracy, string file_name) {

	ofstream f;

	f.open(file_name.c_str(), ios::app);
	f << endl;
	f << setw(t) << " Перевод числа " << digit << " в 10-ую систему счисления : " << endl;


	long long answer = 0;
	int whole_part = int(digit);
	// целая часть

	int fraction = (digit - whole_part)*pow(10, accuracy); // дробная часть

	int str = 0;
	int rez_whole_part = 0;
	while (whole_part > 0)
	{

		int d = whole_part % 10;
		if (d > 7) { f << "ERROR" << endl; return 0; }
		rez_whole_part = rez_whole_part + d * pow(ss, str);

		f << d << " * " << ss << '^' << str;
		str++;
		whole_part = whole_part / 10;
		if (whole_part > 0) f << " + ";
	}
	double rez_fraction = 0;
	str = 1;
	while (fraction > 0) {
		f << " + ";
		int d = fraction % 10;

		if (d > ss - 1) { f << "ERROR" << endl; }
		if (d == 0) { fraction = fraction / 10; }
		else {
			rez_fraction = rez_fraction + d / (pow(ss, str));
			f << d << " * " << ss << '^' << "(-" << str << ')';
			str++;
			fraction = fraction / 10;
			if (fraction > 0) f << " + ";
		}
	}


	double rez = rez_whole_part + rez_fraction;

	f << "= " << rez << endl;

	f.close();
	return rez;
}

int k, k_op;
//коэффициент для выбора состояния
int index(char c) {
	if (((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z'))) { k = 1; }
	else if (((c >= '0') && (c <= '9'))) { k = 2; }
	else if ((c == '%') || (c == '+') || (c == '-') || (c == '*') || (c == '/') || (c == '(') || (c == ')')) { k = 3; }
	else if (c == ' ') { k = 4; }
	return k;
}

//коэффиент опперации
int indexk_op(string z) {

	if ((z == "/") || (z == "*") || (z == "%") || (z == "div")) { k_op = 3; }
	else if ((z == "+") || (z == "-")) { k_op = 2; }
	else if (z == "(") { k_op = 1; }
	else if (z == ")") { k_op = 0; }
	else if (isdigit(z[0]) || z[0] == ' ') { k_op = 4; }
	return k_op;
}

int i = 0;
char tochnost[5] = "";
int t_ind = 0; // индекс строки для точности числа
string p = ""; // для преобразования char to string

class counter {
public:
	double element;


	void Addition(double el_1, double el_2) { element = el_1 + el_2; } //сложение
	void Subtraction(double el_1, double el_2) { element = el_1 - el_2; } //вычитание
	void Multiplication(double el_1, double el_2) { element = el_1 * el_2; } //умножение
	void Division(double el_1, double el_2) { element = el_1 / el_2; } // деление с остатком
	void DivisionWithoutRemainder(double el_1, double el_2) { element = (int)el_1 / (int)el_2; } // деление без остатка

};

class calculator {
protected:
	string line;
	counter obj;

public:

	//преобразование выражения в опз
	void opz(string operation) {
		if (indexk_op(operation) == 4) { number_stack.push(operation); }
		else if (indexk_op(operation) == 3 || indexk_op(operation) == 2) {
			if (operation_stack.empty() || indexk_op(operation_stack.top()) < 2) {
				operation_stack.push(operation);
			}
			else {

				while (indexk_op(operation_stack.top()) >= indexk_op(operation)) {
					number_stack.push(operation_stack.top());
					operation_stack.pop();
				}
				operation_stack.push(operation);
			}
		}
		else if (indexk_op(operation) == 1) {
			operation_stack.push(operation);
		}
		else if (indexk_op(operation) == 0) {
			while (indexk_op(operation_stack.top()) != 1) {
				number_stack.push(operation_stack.top());
				operation_stack.pop();
			}
			operation_stack.pop();
		}

	}

	//вычисление выражения, записанного в ОПЗ
	void answer(int ss, string file_name, int accuracy) {
		counter obj;
		string s;
		double n1, n2;
		int count_action = 1; //  номер действия
		while (!num.empty()) {
			if (indexk_op(num.top()) == 4) {
				operation_stack.push(num.top());
				num.pop();
			}
			else {

			AnsiString doub1 = operation_stack.top().c_str();
			double ch1 = doub1.ToDouble();
				n2 = translation_10(ch1,ss, accuracy, file_name);
				operation_stack.pop();
				 AnsiString doub2 = operation_stack.top().c_str();
				 double ch2 = doub2.ToDouble();

				n1 = translation_10(ch2, ss, accuracy, file_name);
				operation_stack.pop();


				switch (indexk_op(num.top())) {
				case 2:
					if (num.top() == "+") {
						obj.Addition(n1, n2);

						AnsiString	pr = FloatToStr(translation_file(obj.element, ss, file_name, accuracy)) ;



						ofstream f;
						f.open(file_name.c_str(), ios::app);
						f << '\t' << count_action << ") " << translation_file(n1, ss, file_name, accuracy) << " + " << translation_file(n2, ss, file_name, accuracy) << " = " <<  pr.c_str() << endl;
						f.close();


						count_action++;
					}
					else {
						obj.Subtraction(n1, n2);
						AnsiString	pr = FloatToStr(translation(obj.element, ss, accuracy));

						ofstream f;
						f.open(file_name.c_str(), ios::app);
						f << '\t' << count_action << ") " << translation_file(n1, ss, file_name, accuracy) << " - " << translation_file(n2, ss, file_name, accuracy) << " = " << pr.c_str() << endl;
						f.close();


						//cout << count_action << ' ' << translation(n1, ss,  file_name,  accuracy) << " - " << translation(n2, ss, file_name,  accuracy) << " = " << s << endl;
						count_action++;
					}
					break;
				case 3:

					if (num.top() == "*") {
						obj.Multiplication(n1, n2);
						AnsiString	pr = FloatToStr(translation(obj.element, ss, accuracy));

						ofstream f;
						f.open(file_name.c_str(), ios::app);
						f << '\t' << count_action << ") " << translation_file(n1, ss, file_name, accuracy) << " * " << translation_file(n2, ss, file_name, accuracy) << " = " << pr.c_str() << endl;
						f.close();


						//cout << count_action << ' ' << translation(n1, ss, file_name, accuracy) << " * " << translation(n2, ss, file_name, accuracy) << " = " << s << endl;
						count_action++;
					}
					else if (num.top() == "/") {
						if (n2 == 0) {
							/*MessageBox
							(
								hWnd,		// дескриптор окна владельца
								"\t\t\tОшибка.\n\t\t\tДеление на 0.\n \t\tНажмите \"OK\" и введите корректное выражение заново.",	// адрес текста в окне сообщений
								"Ошибка",	// адрес заголовка в окне сообщений
								MB_OK 		// стиль окна сообщений
							);
							*/

						}
						else {

							obj.Division(n1, n2);
								AnsiString	pr = FloatToStr(translation(obj.element, ss, accuracy));


							ofstream f;
							f.open(file_name.c_str(), ios::app);
							f << '\t' << count_action << ") " << translation_file(n1, ss, file_name, accuracy) << " / " << translation_file(n2, ss, file_name, accuracy) << " = " << pr.c_str() << endl;
							f.close();


							//	cout << count_action << ' ' << translation(n1, ss, file_name, accuracy) << " / " << translation(n2, ss, file_name, accuracy) << " = " << s << endl;
							count_action++;
						}
					}
					else if (num.top() == "div") {
						if (n2 == 0) {
						/*	MessageBox
							(
								hWnd,		// дескриптор окна владельца
								"\t\t\tОшибка.\n\t\t\tДеление на 0.\n \t\tНажмите \"OK\" и введите корректное выражение заново.",	// адрес текста в окне сообщений
								"Ошибка",	// адрес заголовка в окне сообщений
								MB_OK 		// стиль окна сообщений
							);*/

						}
						else {
							obj.DivisionWithoutRemainder(n1, n2);
								AnsiString	pr = FloatToStr(translation(obj.element, ss, accuracy));

							ofstream f;
							f.open(file_name.c_str(), ios::app);
							f << '\t' << count_action << ") " << translation_file(n1, ss, file_name, accuracy) << " div " << translation_file(n2, ss, file_name, accuracy) << " = " << pr.c_str()<< endl;
							f.close();

						}
						//	cout << count_action << ' ' << translation(n1, ss, file_name, accuracy) << " div " << translation(n2, ss, file_name, accuracy) << " = " << s << endl;
						count_action++;
					} //целочисленное деление
					break;
				}
				num.pop();
				operation_stack.push(s);
			}


		}

	}




};


string parser(string s, int ss, string file_name, int  accuracy) {
	string  sl = "", data = ""; // sl для формаривания слова , data для формирования числа
	state state = start;
	calculator  cl;
	int i = 0; // счетчик в входной строке
			   //int j = 0, l = 0, m = 0;
	char c, next_c; // c текущий символ строки , next_c cледующий
	bool flag = false; // флаг для перехода в состояние "double_digit"

	s = "( " + s + ") ";
	while (i < s.length() - 1) {
		c = s[i];
		next_c = s[i + 1];
		string z = "";
		z = z + c;
		switch (state)
		{
		case start:
			switch (index(c))
			{
			case 1: state = word;
				break;
			case 2: state = digit;
				if (flag) state = double_digit;
				break;
			case 3: state = symbol;
				break;
			case 4: state = start; i++;
				count_point = 0;
				break;
			default: state = error;
				break;

			}
			break;
		case word:
			switch (index(c))
			{
			case 1:
				i++;
				sl = sl + c;
				if (index(next_c) == 4) {
					state = start;
					cl.opz(sl);
					sl = "";
				}
				break;
			default: state = error;
				break;
			}
			break;
		case digit:
			switch (index(c))
			{
			case 2:
				i++;
				data = data + c;
				if (next_c == '.') {
					state = double_digit;
					flag = true;
				}
				if (index(next_c) == 4) {
					state = start;
					cl.opz(data);
					data = "";
					flag = false;
					count_point = 0;
				}

				break;
			default: state = error;
				break;
			}
			break;
		case double_digit:
			i++;
			data = data + c;
			if (index(next_c) == 4) {
				state = start;
				cl.opz(data);
				data = "";
				count_point = 0;
				flag = true;
			}
			break;
		case symbol:
			switch (index(c)) {
			case 3:
				if (index(next_c) == 4) { state = start; }
				cl.opz(z);
				i++;

				break;
			default: state = error;
				break;
			}
			break;
		case error:
			/*MessageBox
			(
				hWnd,		// дескриптор окна владельца
				"\t\t\tОшибка.\n \t\tНажмите \"OK\" и введите корректное выражение заново.",	// адрес текста в окне сообщений
				"Ошибка",	// адрес заголовка в окне сообщений
				MB_OK 		// стиль окна сообщений
			);
			*/
			state = start;
			i = s.length();
			break;
		}
	}

	// проверка стека при создании опз (когда строка разобрана)
	if (!operation_stack.empty()) {
		while (operation_stack.empty()) {
			number_stack.push(operation_stack.top());
			operation_stack.pop();
		}
	}
	string print_opz = "";
	//переворачиваем стек
	while (!number_stack.empty()) {
		print_opz = number_stack.top() + ' ' + print_opz;
		num.push(number_stack.top());
		number_stack.pop();
	}
	ofstream f;
	f.open(file_name.c_str(), ios::app);
	f << ' ' + print_opz << endl << " 2.Подсчет выражения : \n";

	f.close();

	cl.answer(ss, file_name, accuracy);

	string ans = operation_stack.top();
	return  ans;

}



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
	case 13:
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
	  flag_ans = true;
	  s+=' ';
	  f.open(file_name.c_str());

			if (f.is_open()) {
				f << " Введенное вырадение: ";

				f << s.c_str() <<  endl;
				f << "\n 1.Преобразование выражения из инфиксной записи в постфиксную для определения последовательности действий : ";
			}

			f << endl;
			f.close();

						if (TB_accuracy->Text =="") {
								t+='1';
						}
			 flag_ans = true;
			 AnsiString ans_s = s;
			 AnsiString ans_par = parser(ans_s.c_str(), 8, file_name, StrToInt(t)).c_str();
			 TB_accuracy->Text = t;

			 AnsiString ans_s1 =  parser(ans_s.c_str(), 8, file_name.c_str(), StrToInt(t)).c_str();
			TB_field->Text=ans_s1;
		break;

	}
	if (!flag_ans) {
	TB_field->Text = s;
	TB_accuracy->Text = t;
	}

}
//---------------------------------------------------------------------------
void __fastcall TForm1::BT_showResultClick(TObject *Sender)
{
	Form2->ShowModal();

}
//---------------------------------------------------------------------------




