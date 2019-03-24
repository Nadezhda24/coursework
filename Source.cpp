#define _CRT_SECURE_NO_WARNINGS

#pragma comment(linker,"/manifestdependency:\"type='win32' \
                        name='Microsoft.Windows.Common-Controls' \
                        version='6.0.0.0' processorArchitecture='*'\
 publicKeyToken='6595b64144ccf1df' language='*'\"")



#include <iostream>
#include <cstdlib>

#include <stack>
#include <fstream>
#include "Graphics.h"
#include "Index.h"
#include "Translatoin.h"
using namespace std;


enum state { start, digit, double_digit, word, symbol, error };


string z;
stack <string> number_stack;
stack <string> operation_stack;
stack <string> num;

int const ss = 8;
string file_name = "detailed_answer_kr.txt";
int count_point = 0;
bool toch_flag = false;

char s[100] = "";// строка
char ans[100] = "";
int i = 0;
char tochnost[10] = "";
int t_ind = 0;

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
		int count_action = 1;
		while (!num.empty()) {
			if (indexk_op(num.top()) == 4) {
				operation_stack.push(num.top());
				num.pop();
			}
			else {

	
				n2 = translation_10(stod(operation_stack.top()), ss, accuracy, file_name);
				operation_stack.pop();


				n1 = translation_10(stod(operation_stack.top()), ss, accuracy, file_name);
				operation_stack.pop();


				switch (indexk_op(num.top())) {
				case 2:
					if (num.top() == "+") {
						obj.Addition(n1, n2);
						s = to_string(translation_file(obj.element, ss, file_name, accuracy));



						ofstream f;
						f.open(file_name, ios::app);
						f << '\t' << count_action << ") " << translation_file(n1, ss, file_name, accuracy) << " + " << translation_file(n2, ss, file_name, accuracy) << " = " << s << endl;
						f.close();

					
						count_action++;
					}
					else {
						obj.Subtraction(n1, n2);
						s = to_string(translation(obj.element, ss, accuracy));

						ofstream f;
						f.open(file_name, ios::app);
						f << '\t' << count_action << ") " << translation_file(n1, ss, file_name, accuracy) << " - " << translation_file(n2, ss, file_name, accuracy) << " = " << s << endl;
						f.close();


						//cout << count_action << ' ' << translation(n1, ss,  file_name,  accuracy) << " - " << translation(n2, ss, file_name,  accuracy) << " = " << s << endl;
						count_action++;
					}
					break;
				case 3:

					if (num.top() == "*") {
						obj.Multiplication(n1, n2);
						s = to_string(translation(obj.element, ss, accuracy));

						ofstream f;
						f.open(file_name, ios::app);
						f << '\t' << count_action << ") " << translation_file(n1, ss, file_name, accuracy) << " * " << translation_file(n2, ss, file_name, accuracy) << " = " << s << endl;
						f.close();


						//cout << count_action << ' ' << translation(n1, ss, file_name, accuracy) << " * " << translation(n2, ss, file_name, accuracy) << " = " << s << endl;
						count_action++;
					}
					else if (num.top() == "/") {
						if (n2 == 0) {
							MessageBox
							(
								hWnd,		// дескриптор окна владельца
								"\t\t\tОшибка.\n\t\t\tДеление на 0.\n \t\tНажмите \"OK\" и введите корректное выражение заново.",	// адрес текста в окне сообщений
								"Ошибка",	// адрес заголовка в окне сообщений
								MB_OK 		// стиль окна сообщений
							);
						

						}
						else {

							obj.Division(n1, n2);
							s = to_string(translation(obj.element, ss, accuracy));


							ofstream f;
							f.open(file_name, ios::app);
							f << '\t' << count_action << ") " << translation_file(n1, ss, file_name, accuracy) << " / " << translation_file(n2, ss, file_name, accuracy) << " = " << s << endl;
							f.close();


							//	cout << count_action << ' ' << translation(n1, ss, file_name, accuracy) << " / " << translation(n2, ss, file_name, accuracy) << " = " << s << endl;
							count_action++;
						}
					}
					else if (num.top() == "div") {
						if (n2 == 0) {
							MessageBox
							(
								hWnd,		// дескриптор окна владельца
								"\t\t\tОшибка.\n\t\t\tДеление на 0.\n \t\tНажмите \"OK\" и введите корректное выражение заново.",	// адрес текста в окне сообщений
								"Ошибка",	// адрес заголовка в окне сообщений
								MB_OK 		// стиль окна сообщений
							);
							
						}
						else {
							obj.DivisionWithoutRemainder(n1, n2);
							s = to_string(translation(obj.element, ss, accuracy));

							ofstream f;
							f.open(file_name, ios::app);
							f << '\t' << count_action << ") " << translation_file(n1, ss, file_name, accuracy) << " div " << translation_file(n2, ss, file_name, accuracy) << " = " << s << endl;
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
	string  sl = "", data = "";
	state state = start;
	calculator  cl;
	int i = 0;
	int j = 0, l = 0, m = 0;
	char c, next_c;
	bool flag = false;

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
			MessageBox
			(
				hWnd,		// дескриптор окна владельца
				"\t\t\tОшибка.\n \t\tНажмите \"OK\" и введите корректное выражение заново.",	// адрес текста в окне сообщений
				"Ошибка",	// адрес заголовка в окне сообщений
				MB_OK 		// стиль окна сообщений
			);
			
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
	f.open(file_name, ios::app);
	f << ' ' + print_opz << endl << " 2.Подсчет выражения : \n";

	f.close();

	cl.answer(ss, file_name, accuracy);

	string ans = operation_stack.top();
	return  ans;

}

HWND hEdit;
HWND hEdit_t;
string p = "";
ofstream f;
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	string p = "";
	// выборка и обработка сообщений
	switch (message)
	{
	
	case WM_CREATE:

		hStat = CreateWindow("static", "Toчность : ", WS_CHILD | WS_VISIBLE | SS_LEFT,
			start_line + size_of_button, consol + 55, size_of_button * 2, width_input_line, hWnd, 0, hInst, NULL);
		
	 hEdit =	CreateWindowEx(WS_EX_CLIENTEDGE, "edit", "", WS_CHILD | WS_VISIBLE |
		 WS_BORDER | ES_MULTILINE | ES_AUTOHSCROLL | ES_AUTOVSCROLL,
			start_line, consol ,size_of_button*4, width_input_line, hWnd, (HMENU)10000, hInst, NULL);
		
	 hEdit_t = CreateWindowEx(WS_EX_CLIENTEDGE, "edit", "", WS_CHILD | WS_VISIBLE |
		 WS_BORDER | ES_AUTOHSCROLL | ES_AUTOVSCROLL,
			start_line+ size_of_button*2, consol+50, size_of_button * 2, width_input_line, hWnd, (HMENU)10000, hInst, NULL);
		break;
	case WM_COMMAND:
		switch (wParam)
		{

	
		case IDB_Button1:
			if (toch_flag) { 
				tochnost[t_ind] = '1';
				t_ind++;
			SendMessage(hEdit, EM_SETSEL, WPARAM(0), LPARAM(-1));
			SendMessage(hEdit, EM_REPLACESEL, WPARAM(TRUE), LPARAM(tochnost));
			}
			else {
				s[i] = '1';
				i++;
				SendMessage(hEdit, EM_SETSEL | ES_LEFT, WPARAM(0), LPARAM(-1));
				SendMessage(hEdit, EM_REPLACESEL | ES_RIGHT, WPARAM(TRUE), LPARAM(s));
			}
			break;
		case IDB_Button2:
			if (toch_flag) { 	
			tochnost[t_ind] = '2'; 
			t_ind++;
			SendMessage(hEdit, EM_SETSEL, WPARAM(0), LPARAM(-1));
			SendMessage(hEdit, EM_REPLACESEL, WPARAM(TRUE), LPARAM(tochnost));
			}
			else {
				s[i] = '2';
				i++;
				SendMessage(hEdit, EM_SETSEL| ES_LEFT, WPARAM(0), LPARAM(-1));
				SendMessage(hEdit, EM_REPLACESEL| ES_RIGHT, WPARAM(TRUE), LPARAM(s));
			}
			break;
		case IDB_Button3:
			if (toch_flag) { tochnost[t_ind] = '3'; t_ind++; 
			SendMessage(hEdit, EM_SETSEL, WPARAM(0), LPARAM(-1));
			SendMessage(hEdit, EM_REPLACESEL, WPARAM(TRUE), LPARAM(tochnost));
			}
			else {
				s[i] = '3';
				i++;
				SendMessage(hEdit, EM_SETSEL, WPARAM(0), LPARAM(-1));
				SendMessage(hEdit, EM_REPLACESEL, WPARAM(TRUE), LPARAM(s));
			}
			break;
		case IDB_Button4:
			if (toch_flag) {
				tochnost[t_ind] = '4'; 
				t_ind++; 
				SendMessage(hEdit, EM_SETSEL, WPARAM(0), LPARAM(-1));
				SendMessage(hEdit, EM_REPLACESEL, WPARAM(TRUE), LPARAM(tochnost));
			}
			else {
				s[i] = '4';
				i++;
				SendMessage(hEdit, EM_SETSEL, WPARAM(0), LPARAM(-1));
				SendMessage(hEdit, EM_REPLACESEL, WPARAM(TRUE), LPARAM(s));
			}
			break;
		case IDB_Button5:
			if (toch_flag) {
				tochnost[t_ind] = '5'; 
				t_ind++; 
				SendMessage(hEdit, EM_SETSEL, WPARAM(0), LPARAM(-1));
				SendMessage(hEdit, EM_REPLACESEL, WPARAM(TRUE), LPARAM(tochnost));
			}
			else {
				s[i] = '5';
				i++;
				SendMessage(hEdit, EM_SETSEL, WPARAM(0), LPARAM(-1));
				SendMessage(hEdit, EM_REPLACESEL, WPARAM(TRUE), LPARAM(s));
			}
			break;
		case IDB_Button6:
			if (toch_flag) { tochnost[t_ind] = '6';
			t_ind++;
			SendMessage(hEdit, EM_SETSEL, WPARAM(0), LPARAM(-1));
			SendMessage(hEdit, EM_REPLACESEL, WPARAM(TRUE), LPARAM(tochnost));
			}
			else {
				s[i] = '6';
				i++;
				SendMessage(hEdit, EM_SETSEL , WPARAM(0), LPARAM(-1));
				SendMessage(hEdit, EM_REPLACESEL, WPARAM(TRUE), LPARAM(s));
			}
			break;
		case IDB_Button7:
			if (toch_flag) {
			tochnost[t_ind] = '7';
			t_ind++;
			SendMessage(hEdit, EM_SETSEL, WPARAM(0), LPARAM(-1));
			SendMessage(hEdit, EM_REPLACESEL, WPARAM(TRUE), LPARAM(tochnost));
			}
			else {
				s[i] = '7';
				i++;
				SendMessage(hEdit, EM_SETSEL, WPARAM(0), LPARAM(-1));
				SendMessage(hEdit, EM_REPLACESEL, WPARAM(TRUE), LPARAM(s));
			}
			break;
		case IDB_Button8:
			if (toch_flag) { 
				tochnost[t_ind] = '8';
				t_ind++;
				SendMessage(hEdit, EM_SETSEL, WPARAM(0), LPARAM(-1));
				SendMessage(hEdit, EM_REPLACESEL, WPARAM(TRUE), LPARAM(tochnost));
			}
			else {
				MessageBox
				(
					hWnd,		// дескриптор окна владельца
					"\t\t\tОшибка ввода.\n\t Используйте числа только из восьмиричной системы \t\t\t\t счисления.\n \t\tНажмите \"OK\" и продолжите ввод.",	// адрес текста в окне сообщений
					"Ошибка",	// адрес заголовка в окне сообщений
					MB_OK 		// стиль окна сообщений
				);
			}
			SendMessage(hEdit, EM_SETSEL, WPARAM(0), LPARAM(-1));
			SendMessage(hEdit, EM_REPLACESEL, WPARAM(TRUE), LPARAM(s));
			break;
		case IDB_Button9:
			if (toch_flag) {
				tochnost[t_ind] = '9';
				t_ind++; 
				SendMessage(hEdit, EM_SETSEL, WPARAM(0), LPARAM(-1));
				SendMessage(hEdit, EM_REPLACESEL, WPARAM(TRUE), LPARAM(tochnost));
			}
			else {
				MessageBox
				(
					hWnd,		// дескриптор окна владельца
					"\t\t\tОшибка ввода.\n\t Используйте числа только из восьмиричной системы \t\t\t\t счисления.\n \t\tНажмите \"OK\" и продолжите ввод.",	// адрес текста в окне сообщений
					"Ошибка",	// адрес заголовка в окне сообщений
					MB_OK 		// стиль окна сообщений
				);
			}
			SendMessage(hEdit, EM_SETSEL, WPARAM(0), LPARAM(-1));
			SendMessage(hEdit, EM_REPLACESEL, WPARAM(TRUE), LPARAM(s));
			break;
		case IDB_Button10:
			if (toch_flag) {
				tochnost[t_ind] = '0';
				t_ind++;
				SendMessage(hEdit, EM_SETSEL, WPARAM(0), LPARAM(-1));
				SendMessage(hEdit, EM_REPLACESEL, WPARAM(TRUE), LPARAM(tochnost));
			}
			else {
				s[i] = '0';
				i++;
				SendMessage(hEdit, EM_SETSEL, WPARAM(0), LPARAM(-1));
				SendMessage(hEdit, EM_REPLACESEL, WPARAM(TRUE), LPARAM(s));
			}
			break;
		case IDB_Button11:
			if (toch_flag) { 
				MessageBox
				(
					hWnd,		// дескриптор окна владельца
					"\t\t\tОшибка ввода.\n\t Используйте числа только числа для задания точности.\n \t\tНажмите \"OK\" и продолжите ввод.",	// адрес текста в окне сообщений
					"Ошибка",	// адрес заголовка в окне сообщений
					MB_OK 		// стиль окна сообщений
				);
			}
			else {
				s[i] = ' ';
				i++;
				s[i] = '/';
				i++;
				s[i] = ' ';
				i++;
			}
			SendMessage(hEdit, EM_SETSEL, WPARAM(0), LPARAM(-1));
			SendMessage(hEdit, EM_REPLACESEL, WPARAM(TRUE), LPARAM(s));
			break;
		case IDB_Button12:
			if (toch_flag) {
				MessageBox
				(
					hWnd,		// дескриптор окна владельца
					"\t\t\tОшибка ввода.\n\t Используйте числа только числа для задания точности.\n \t\tНажмите \"OK\" и продолжите ввод.",	// адрес текста в окне сообщений
					"Ошибка",	// адрес заголовка в окне сообщений
					MB_OK 		// стиль окна сообщений
				);
			}
			else {
				s[i] = ' ';
				i++;
				s[i] = '*';
				i++;
				s[i] = ' ';
				i++;
			}
			SendMessage(hEdit, EM_SETSEL, WPARAM(0), LPARAM(-1));
			SendMessage(hEdit, EM_REPLACESEL, WPARAM(TRUE), LPARAM(s));
			break;
		case IDB_Button13:
			if (toch_flag) {
				MessageBox
				(
					hWnd,		// дескриптор окна владельца
					"\t\t\tОшибка ввода.\n\t Используйте числа только числа для задания точности.\n \t\tНажмите \"OK\" и продолжите ввод.",	// адрес текста в окне сообщений
					"Ошибка",	// адрес заголовка в окне сообщений
					MB_OK 		// стиль окна сообщений
				);
			}
			else {
				s[i] = ' ';
				i++;
				s[i] = '-';
				i++;
				s[i] = ' ';
				i++;
			}
			SendMessage(hEdit, EM_SETSEL, WPARAM(0), LPARAM(-1));
			SendMessage(hEdit, EM_REPLACESEL, WPARAM(TRUE), LPARAM(s));
			break;
		case IDB_Button14:
			if (toch_flag) {
				MessageBox
				(
					hWnd,		// дескриптор окна владельца
					"\t\t\tОшибка ввода.\n\t Используйте числа только числа для задания точности.\n \t\tНажмите \"OK\" и продолжите ввод.",	// адрес текста в окне сообщений
					"Ошибка",	// адрес заголовка в окне сообщений
					MB_OK 		// стиль окна сообщений
				);
			}
			else {
				s[i] = ' ';
				i++;
				s[i] = '+';
				i++;
				s[i] = ' ';
				i++;
			}
			SendMessage(hEdit, EM_SETSEL, WPARAM(0), LPARAM(-1));
			SendMessage(hEdit, EM_REPLACESEL, WPARAM(TRUE), LPARAM(s));
			break;
		case IDB_Button15:
			if (toch_flag) {
				MessageBox
				(
					hWnd,		// дескриптор окна владельца
					"\t\t\tОшибка ввода.\n\t Используйте числа только числа для задания точности.\n \t\tНажмите \"OK\" и продолжите ввод.",	// адрес текста в окне сообщений
					"Ошибка",	// адрес заголовка в окне сообщений
					MB_OK 		// стиль окна сообщений
				);
			}
			else {
				
				if (count_point > 1) {
					MessageBox
					(
						hWnd,		// дескриптор окна владельца
						"\t\t\tОшибка ввода.\n\t\t\tНажмите \"OK\" и продолжите ввод.",	// адрес текста в окне сообщений
						"Ошибка",	// адрес заголовка в окне сообщений
						MB_OK 		// стиль окна сообщений
					);
				}
				else {
					s[i] = '.';
					i++;
					count_point++;
					SendMessage(hEdit, EM_SETSEL | ES_LEFT, WPARAM(0), LPARAM(-1));
					SendMessage(hEdit, EM_REPLACESEL | ES_RIGHT, WPARAM(TRUE), LPARAM(s));
				}
			}
			break;

		case IDB_Button17:
			if (toch_flag) {
				MessageBox
				(
					hWnd,		// дескриптор окна владельца
					"\t\t\tОшибка ввода.\n\t Используйте числа только числа для задания точности.\n \t\tНажмите \"OK\" и продолжите ввод.",	// адрес текста в окне сообщений
					"Ошибка",	// адрес заголовка в окне сообщений
					MB_OK 		// стиль окна сообщений
				);
			}
			else {
				s[i] = ' ';
				i++;
				s[i] = '(';
				i++;
				s[i] = ' ';
				i++;
			}
			SendMessage(hEdit, EM_SETSEL, WPARAM(0), LPARAM(-1));
			SendMessage(hEdit, EM_REPLACESEL, WPARAM(TRUE), LPARAM(s));
			break;
		case IDB_Button18:
			if (toch_flag) {
				MessageBox
				(
					hWnd,		// дескриптор окна владельца
					"\t\t\tОшибка ввода.\n\t Используйте числа только числа для задания точности.\n \t\tНажмите \"OK\" и продолжите ввод.",	// адрес текста в окне сообщений
					"Ошибка",	// адрес заголовка в окне сообщений
					MB_OK 		// стиль окна сообщений
				);
			}
			else {
				s[i] = ' ';
				i++;
				s[i] = ')';
				i++;
				s[i] = ' ';
				i++;
			}
			SendMessage(hEdit, EM_SETSEL, WPARAM(0), LPARAM(-1));
			SendMessage(hEdit, EM_REPLACESEL, WPARAM(TRUE), LPARAM(s));
			break;

		case IDB_Button19:
			if (toch_flag) {
				MessageBox
				(
					hWnd,		// дескриптор окна владельца
					"\t\t\tОшибка ввода.\n\t Используйте числа только числа для задания точности.\n \t\tНажмите \"OK\" и продолжите ввод.",	// адрес текста в окне сообщений
					"Ошибка",	// адрес заголовка в окне сообщений
					MB_OK 		// стиль окна сообщений
				);
			}
			else {
				s[i] = ' ';
				s[i + 1] = 'd';
				s[i + 2] = 'i';
				s[i + 3] = 'v';
				s[i + 4] = ' ';
				i = i + 5;
			}
			SendMessage(hEdit, EM_SETSEL, WPARAM(0), LPARAM(-1));
			SendMessage(hEdit, EM_REPLACESEL, WPARAM(TRUE), LPARAM(s));
			break;
		case IDB_Button20:
			if (toch_flag) {
				t_ind--;
				tochnost[t_ind] = ' ';
				SendMessage(hEdit, EM_SETSEL, WPARAM(0), LPARAM(-1));
				SendMessage(hEdit, EM_REPLACESEL, WPARAM(TRUE), LPARAM(tochnost));
			}
			else {
				i--;
				s[i] = ' ';
				SendMessage(hEdit, EM_SETSEL, WPARAM(0), LPARAM(-1));
				SendMessage(hEdit, EM_REPLACESEL, WPARAM(TRUE), LPARAM(s));
			}
			break;
		case IDB_Button16:
			
			s[i] = ' ';	
			for (int j = 0; j < size(s); j++) {
				p = p + s[j];
			}
		
			f.open(file_name);
		
			if (f.is_open()) {
				f << " Введенное вырадение: ";
					f << s;
				f<<"\n 1.Преобразование выражения из инфиксной записи в постфиксную для определения последовательности действий : ";
			}

			f << endl;			
			f.close();
			if (tochnost[0] = ' ') { 
				tochnost[0] = '1';
				SendMessage(hEdit, EM_SETSEL, WPARAM(0), LPARAM(-1));
				SendMessage(hEdit, EM_REPLACESEL, WPARAM(TRUE), LPARAM(tochnost));
			}

	
			SendMessage(hEdit, EM_SETSEL, WPARAM(0), LPARAM(-1));
			SendMessage(hEdit, EM_REPLACESEL, WPARAM(TRUE), LPARAM(parser(s, 8, file_name, stoi(tochnost)).c_str()));
			break;
		case IDB_Button21:
			if (!toch_flag) { toch_flag = true; }
			else { toch_flag = false; }
			break;

		case IDB_Button22:
			int start_text_x = start_line * 2 + 4 * size_of_button + 30;
			int consol_y = consol;
			hStat = CreateWindow("static", "Подробное решение:", WS_CHILD | WS_VISIBLE | SS_LEFT,
				start_text_x, consol_y, size_of_button * 2, width_input_line, hWnd, 0, hInst, NULL);
			consol_y = consol_y + width_input_line;
			string line;
			ifstream in(file_name); // окрываем файл для чтения
			if (in.is_open())
			{
				while (getline(in, line))
				{
					hStat = CreateWindow("static", line.c_str(), WS_CHILD | WS_VISIBLE | SS_LEFT,
						start_text_x, consol_y, size_of_button * 6, width_input_line, hWnd, 0, hInst, NULL);

					consol_y = consol_y + width_input_line;
				}
			}
			in.close();     // закрываем файл
			break;

		}
	
		break;

	
	 
	case WM_DESTROY:
		PostQuitMessage(0);  // реакция на сообщение
		break;
	default:
		// все сообщения не обработанные Вами обработает сама Windows
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}