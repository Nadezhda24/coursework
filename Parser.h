#ifndef _PARSER_H
#define _PARSER_H

#include "translation.h"
#include "index.h"
#include <sstream>
# include <math.h>
double string_to_double( const std::string& s )
{
std::istringstream i(s);
double x;
if (!(i >> x))
return 0;
return x;
}

enum state { start, digit, double_digit, word, symbol,error };

string z;
stack <string> number_stack;
stack <string> operation_stack;
stack <string> num;

//int const number_system = 8; // ������� ��������
string file_name = "detailed_answer_kr.txt";
int count_point = 0; // ������� �����
bool toch_flag = false; // ���� ��� ���������� ��������� ����� � ��������� ������ �����
char s[100] = ""; // ������, ���������� �������� ���������
int i = 0;
char tochnost[5] = "";
int t_ind = 0; // ������ ������ ��� �������� �����
string p = ""; // ��� �������������� char to string

long double fact(int N)
{
    if(N < 0) // ���� ������������ ���� ������������� �����
        return 0; // ���������� ����
    if (N == 0) // ���� ������������ ���� ����,
		return 1; // ���������� ��������� �� ���� - �� �����������, �� ��� 1 =)
    else // �� ���� ��������� �������
	   { return N * fact(N - 1);
	   } // ������ ��������.
}

class counter {
private :
	double element;
public:

	void Addition(double FirstElement, double SecondElement) { element =  FirstElement + SecondElement; } //��������
	void Subtraction(double  FirstElement, double SecondElement) { element =  FirstElement - SecondElement; } //���������
	void Multiplication(double  FirstElement, double SecondElement) { element =  FirstElement * SecondElement; } //���������
	void Division(double  FirstElement, double SecondElement) { element =  FirstElement / SecondElement; } // ������� � ��������
	void DivisionWithoutRemainder(double  FirstElement, double SecondElement) { element = (int) FirstElement / (int)SecondElement; } // ������� ��� �������
	void Mod(double  FirstElement, double SecondElement) { element = (int) FirstElement % (int)SecondElement; }
	void Fact(double  FirstElement)  {element = fact ((int)FirstElement);}
	void Power (double  FirstElement, double SecondElement) { element = powl( FirstElement , SecondElement); }
	void Sin (double  FirstElement)  {element = sinl(FirstElement);}
	void Cos   (double  FirstElement)  {element = cosl(FirstElement);}
	void Tg  (double  FirstElement)  {element = tanl(FirstElement);}
	void Ctg  (double  FirstElement)  {element = cosl(FirstElement)/sinl(FirstElement);}
	void ArcSin (double  FirstElement)  {element = asinl(FirstElement);}
	void ArcCos (double  FirstElement)  {element = acosl(FirstElement);}
	void ArcTg  (double  FirstElement)  {element = atanl(FirstElement);}
	void ArcCtg  (double  FirstElement)  {element =  M_PI_2 -atanl(FirstElement);}

	double GetElement() {return element;}
};

class calculator {
	private:
string line;
public:

//�������������� ��������� � ���
void opz(string operation) {
	if (indexk_op(operation) == 7) { number_stack.push(operation); }
	else if (indexk_op(operation) >= 2 ) {

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
	else if (indexk_op(operation) == 1) {operation_stack.push(operation);}
	else if (indexk_op(operation) == 0) {
		while (indexk_op(operation_stack.top()) != 1) {
			number_stack.push(operation_stack.top());
			operation_stack.pop();
		}
	operation_stack.pop();
	}
}

//���������� ���������, ����������� � ���
void answer(int number_system, string file_name, int accuracy) {
counter obj;
string s;
double n1, n2;
int CountAction = 1; // ����� ��������
ofstream f;
while (!num.empty()) {
	if (indexk_op(num.top()) == 7) {
	operation_stack.push(num.top());
	num.pop();
	}
	else {
		string SecondDigit  = operation_stack.top().c_str();
		for (int i=0;i < SecondDigit .length(); i++){
			if (SecondDigit [i]==','){SecondDigit [i]='.'; }
		}
		AnsiString SecondDigitDoubel = SecondDigit.c_str();
		double SecondDigitStringToDouble = string_to_double(SecondDigitDoubel.c_str());
		if (number_system==16) {
		n2=  translation_16(SecondDigit,number_system, accuracy, file_name);
		}else{
		n2 = translation_10(SecondDigitStringToDouble,number_system, accuracy, file_name);
		}
		operation_stack.pop();


		string FirstDigit = operation_stack.top().c_str();
		for (int i=0;i < FirstDigit.length(); i++){
			if (FirstDigit[i]==','){FirstDigit[i]='.'; }
		}
		AnsiString FirstDigitDoubel = FirstDigit.c_str();
		double FirstDigitStringToDouble = string_to_double(FirstDigitDoubel.c_str());
		if (number_system==16) {
		n1=  translation_16(FirstDigit,number_system, accuracy, file_name);
		}else{
		n1 = translation_10(FirstDigitStringToDouble,number_system, accuracy, file_name);
		}
		operation_stack.pop();

		AnsiString CalculationResult;
		switch (indexk_op(num.top())) {
			case 5 :
			obj.Power(n1, n2);
			CalculationResult = FloatToStr(translation_file(obj.GetElement(), number_system, file_name,accuracy));
			break;
			case 4 :
			if (num.top()== "cos") {
			 obj.Cos(n1);
			 CalculationResult = FloatToStr(translation_file(obj.GetElement(), number_system, file_name, accuracy)) ;
			}
			else if (num.top()== "sin") {
			 obj.Sin(n1);
			 CalculationResult = FloatToStr(translation_file(obj.GetElement(), number_system, file_name, accuracy)) ;
			}
				else if (num.top()== "tg") {
			 obj.Tg(n1);
			 CalculationResult = FloatToStr(translation_file(obj.GetElement(), number_system, file_name, accuracy)) ;
			}	else if (num.top()== "ctg") {
			 obj.Ctg(n1);
			 CalculationResult = FloatToStr(translation_file(obj.GetElement(), number_system, file_name, accuracy)) ;
			}
			else 	if (num.top()== "arccos") {
			 obj.ArcCos(n1);
			 CalculationResult = FloatToStr(translation_file(obj.GetElement(), number_system, file_name, accuracy)) ;
			}
			else if (num.top()== "arcsin") {
			 obj.ArcSin(n1);
			 CalculationResult = FloatToStr(translation_file(obj.GetElement(), number_system, file_name, accuracy)) ;
			}
				else if (num.top()== "arctg") {
			 obj.ArcTg(n1);
			 CalculationResult = FloatToStr(translation_file(obj.GetElement(), number_system, file_name, accuracy)) ;
			}	else if (num.top()== "arcctg") {
			 obj.ArcCtg(n1);
			 CalculationResult = FloatToStr(translation_file(obj.GetElement(), number_system, file_name, accuracy)) ;
			}
			break;
			case 6:
			if(num.top()== "!"){
				ShowMessage( "!");
			}
			 obj.Fact(n1);

			 CalculationResult = FloatToStr(translation_file(obj.GetElement(), number_system, file_name, accuracy)) ;
			break;
			case 2:
				if (num.top() == "+") {
					obj.Addition(n1, n2);
					CalculationResult = FloatToStr(translation_file(obj.GetElement(), number_system, file_name, accuracy)) ;
					ofstream f;
					f.open(file_name.c_str(), ios::app);
					f << '\t' << CountAction << ") " << translation_file(n1, number_system, file_name, accuracy) << " + " << translation_file(n2, number_system, file_name, accuracy)  << " = " << CalculationResult.c_str() << endl;
					f.close();
					CountAction++;
				}
				else {
					obj.Subtraction(n1, n2);
					CalculationResult = FloatToStr(translation_file(obj.GetElement(), number_system,file_name ,accuracy));
					ofstream f;
					f.open(file_name.c_str(), ios::app);
					f << '\t' << CountAction << ") " << translation_file(n1, number_system, file_name, accuracy) << " - " << translation_file(n2, number_system, file_name, accuracy) << " = " << CalculationResult.c_str() << endl;
					f.close();
					CountAction++;
				}
			break;
			case 3:
				if (num.top() == "*") {
					obj.Multiplication(n1, n2);
					CalculationResult = FloatToStr(translation_file(obj.GetElement(), number_system, file_name,accuracy));
					ofstream f;
					f.open(file_name.c_str(), ios::app);
					f << '\t' << CountAction << ") " << translation_file(n1, number_system, file_name, accuracy) << " * " << translation_file(n2, number_system, file_name, accuracy) << " = " << CalculationResult.c_str() << endl;
					f.close();
					CountAction++;
				}
				else if (num.top() == "/") {
					if (n2 == 0) {
					ShowMessage( "������.\n������� �� 0.\n������� \"OK\" � ������� ���������� ��������� ������.");
					}
				else {
				obj.Division(n1, n2);
				CalculationResult = FloatToStr(translation_file(obj.GetElement(), number_system, file_name,accuracy));
				ofstream f;
				f.open(file_name.c_str(), ios::app);
				f << '\t' << CountAction << ") " << translation_file(n1, number_system, file_name, accuracy) << " / " << translation_file(n2, number_system, file_name, accuracy) << " = " << CalculationResult.c_str() << endl;
				f.close();
				CountAction++;
				}
			}
				else if (num.top() == "div") {
					if (n2 == 0) {
					ShowMessage( "������.\n������� �� 0.\n������� \"OK\" � ������� ���������� ��������� ������.");
				}
				else {
				obj.DivisionWithoutRemainder(n1, n2);
				CalculationResult =FloatToStr(translation_file(obj.GetElement(), number_system, file_name,accuracy));
				ofstream f;
				f.open(file_name.c_str(), ios::app);
				f << '\t' << CountAction<< ") " << translation_file(n1, number_system, file_name, accuracy) << " div " << translation_file(n2, number_system, file_name, accuracy) << " = " << CalculationResult.c_str()<< endl;
				f.close();
				CountAction++;}
			}  else if (num.top() == "%") {
					if (n2 == 0) {
					ShowMessage( "������.\n������� �� 0.\n������� \"OK\" � ������� ���������� ��������� ������.");
					}
				else {
				obj.Mod(n1, n2);
				CalculationResult = FloatToStr(translation_file(obj.GetElement(), number_system, file_name,accuracy));
				ofstream f;
				f.open(file_name.c_str(), ios::app);
				f << '\t' << CountAction << ") " << translation_file(n1, number_system, file_name, accuracy) << " % " << translation_file(n2, number_system, file_name, accuracy) << " = " << CalculationResult.c_str() << endl;
				f.close();
				CountAction++;
				}
			}
			break;
		}
	num.pop();
	operation_stack.push(CalculationResult.c_str());
	}
}
}

};

string parser(string s, int number_system, string file_name, int accuracy) {
string sl = "", data = ""; // sl ��� ������������ ����� , data ��� ������������ �����
int count_bracket = 0;
state state = start;
calculator cl;
int i = 0; // ������� � ������� ������
char c, next_c; // c ������� ������ ������ , next_c c��������
bool flag = false; // ���� ��� �������� � ��������� "double_digit"

s = "( " + s + ") ";
while (i < s.length() - 1) {
	c = s[i];
	next_c = s[i + 1];
	string z = "";
	z = z + c;
	switch (state){
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
		switch (index(c)){
			case 1:
				i++;
				sl = sl + c;
				if (index(next_c) == 4) {
					state = start;
					if (sl == "e") {
					  sl =(M_E);
					}
				if (sl == "�") {
					  sl = "3,14";
					}
					cl.opz(sl);
					sl = "";
				}
			break;
			default: state = error;
			break;
			}
			break;
	case digit:
		switch (index(c)){
			case 2:
				if (data.size()< 14) {
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
				} else {
					ShowMessage("������.\n������� ������� �����.\n������� \"OK\" � ������� ���������� ��������� ������.");
					return 0;
				 }
			break;
			default: state = error;
			break;
		}
	break;
	case double_digit:
		if(data.size()< 14) {
			i++;
			data = data + c;
			if (index(next_c) == 4) {
				state = start;
				cl.opz(data);
				data = "";
				count_point =0;
				flag = true;
			}
		}else {
			ShowMessage("������.\n������� ������� �����. \n������� \"OK\" � ������� ���������� ��������� ������.");
			return 0;
		}
	break;
	case symbol:
		switch (index(c)) {
			case 3:
				if (c=='(') { count_bracket +=1;}
				if (c==')') {count_bracket -=1;}
				if (index(next_c) == 4) { state = start; }
				cl.opz(z);
				i++;
				if (count_bracket < 0) {
					ShowMessage("������.\n�� ��������� ������������ ������.\n������� \"OK\" � ������� ���������� ��������� ������.");
					return 0;
				}
			break;
			default: state = error;
			break;
		}
	break;
	case error:
		state = start;
		i = s.length();
		ShowMessage("������.\n������� \"OK\" � ������� ���������� ��������� ������.");
		return 0;
	break;
	}
}

if (count_bracket!=0) {
	ShowMessage("������.\n�� ��������� ������������ ������. \n������� \"OK\" � ������� ���������� ��������� ������.");
    return 0;
	}
// �������� ����� ��� �������� ��� (����� ������ ���������)
if (!operation_stack.empty()) {
	while (operation_stack.empty()) {
		number_stack.push(operation_stack.top());
		operation_stack.pop();
		}
}
string print_opz = "";
//�������������� ����
while (!number_stack.empty()) {
	print_opz = number_stack.top() + ' ' + print_opz;
	num.push(number_stack.top());
	number_stack.pop();
}
ofstream f;
f.open(file_name.c_str(), ios::app);
f << ' ' + print_opz << endl << " 2.������� ��������� : \n";
f.close();

cl.answer(number_system, file_name, accuracy);

string ans = operation_stack.top();
return ans;

}

#define _CRT_SECURE_NO_WARNINGS
#endif

