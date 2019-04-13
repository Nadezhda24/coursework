#ifndef _PARSER_H
#define _PARSER_H

#include "translation.h"
#include "index.h"
  #include <sstream>


  double string_to_double( const std::string& s )
 {
   std::istringstream i(s);
   double x;
   if (!(i >> x))
	 return 0;
   return x;
 }


enum state { start, digit, double_digit, word, symbol, error };

string z;
stack <string> number_stack;
stack <string> operation_stack;
stack <string> num;

int const ss = 8; // ������� ��������
string file_name = "detailed_answer_kr.txt";
int count_point = 0; // ������� �����
bool toch_flag = false; // ���� ��� ���������� ��������� ����� � ��������� ������ �����
char s[100] = ""; // ������, ���������� �������� ���������
int i = 0;
char tochnost[5] = "";
int t_ind = 0; // ������ ������ ��� �������� �����
string p = ""; // ��� �������������� char to string
    class counter {
public:
	double element;


	void Addition(double el_1, double el_2) { element = el_1 + el_2; } //��������
	void Subtraction(double el_1, double el_2) { element = el_1 - el_2; } //���������
	void Multiplication(double el_1, double el_2) { element = el_1 * el_2; } //���������
	void Division(double el_1, double el_2) { element = el_1 / el_2; } // ������� � ��������
	void DivisionWithoutRemainder(double el_1, double el_2) { element = (int)el_1 / (int)el_2; } // ������� ��� �������

};

class calculator {
protected:
	string line;
	counter obj;

public:

	//�������������� ��������� � ���
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

	//���������� ���������, ����������� � ���
	void answer(int ss, string file_name, int accuracy) {
		counter obj;
		string s;
		double n1, n2;
		int count_action = 1; //  ����� ��������
		while (!num.empty()) {
			if (indexk_op(num.top()) == 4) {
				operation_stack.push(num.top());
				num.pop();
			}
			else {
			 string d1 = operation_stack.top().c_str();
				 for (int i=0;i <d1.length(); i++){
			   if (d1[i]==','){d1[i]='.';  }
	 }
				AnsiString d1_1 = d1.c_str();
			double ch1 = string_to_double(d1_1.c_str());
			n2 = translation_10(ch1,ss, accuracy, file_name);
			operation_stack.pop();

					string d2 = operation_stack.top().c_str();
						 for (int i=0;i <d2.length(); i++){
			   if (d2[i]==','){d2[i]='.';  }
	 }

					AnsiString d2_2 = d2.c_str();
				 double ch2 = string_to_double(d2_2.c_str());
				n1 = translation_10(ch2, ss, accuracy, file_name);
				operation_stack.pop();

				 AnsiString	pr ;
				switch (indexk_op(num.top())) {
				case 2:
					if (num.top() == "+") {
						obj.Addition(n1, n2);

				  	pr = FloatToStr(translation_file(obj.element, ss, file_name, accuracy)) ;



						ofstream f;
						f.open(file_name.c_str(), ios::app);
						f << '\t' << count_action << ") " << translation(n1, ss, accuracy) << " + " << translation(n2, ss, accuracy) << " = " <<  pr.c_str() << endl;
						f.close();


						count_action++;
					}
					else {
						obj.Subtraction(n1, n2);

							pr = FloatToStr(translation(obj.element, ss, accuracy));


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
							pr = FloatToStr(translation(obj.element, ss, accuracy));


						ofstream f;
						f.open(file_name.c_str(), ios::app);
						f << '\t' << count_action << ") " << translation_file(n1, ss, file_name, accuracy) << " * " << translation_file(n2, ss, file_name, accuracy) << " = " << pr.c_str() << endl;
						f.close();


						//cout << count_action << ' ' << translation(n1, ss, file_name, accuracy) << " * " << translation(n2, ss, file_name, accuracy) << " = " << s << endl;
						count_action++;
					}
					else if (num.top() == "/") {
						if (n2 == 0) {
							ShowMessage(	"\t\t\t������.\n\t\t\t������� �� 0.\n \t\t������� \"OK\" � ������� ���������� ��������� ������.");

						}
						else {

							obj.Division(n1, n2);
								pr = FloatToStr(translation(obj.element, ss, accuracy));



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
							ShowMessage(	"\t\t\t������.\n\t\t\t������� �� 0.\n \t\t������� \"OK\" � ������� ���������� ��������� ������.");


						}
						else {
							obj.DivisionWithoutRemainder(n1, n2);
								pr =FloatToStr(translation(obj.element, ss, accuracy));

							ofstream f;
							f.open(file_name.c_str(), ios::app);
							f << '\t' << count_action << ") " << translation_file(n1, ss, file_name, accuracy) << " div " << translation_file(n2, ss, file_name, accuracy) << " = " << pr.c_str()<< endl;
							f.close();

						}
						//	cout << count_action << ' ' << translation(n1, ss, file_name, accuracy) << " div " << translation(n2, ss, file_name, accuracy) << " = " << s << endl;
						count_action++;
					} //������������� �������
					break;
				}
				num.pop();
				operation_stack.push(pr.c_str());
			}


		}

	}




};


string parser(string s, int ss, string file_name, int  accuracy) {
	string  sl = "", data = ""; // sl ��� ������������ ����� , data ��� ������������ �����
	int count_bracket = 0;
	state state = start;
	calculator  cl;
	int i = 0; // ������� � ������� ������
			   //int j = 0, l = 0, m = 0;
	char c, next_c; // c ������� ������ ������ , next_c c��������
	bool flag = false; // ���� ��� �������� � ��������� "double_digit"

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
				 if (c=='(') { count_bracket +=1;}
				 if (c==')') {count_bracket -=1;}
				if (index(next_c) == 4) { state = start; }
				cl.opz(z);
				i++;
				if (count_bracket < 0) {
			 ShowMessage("\t\t\t������.\n �� ��������� ������������ ������. \t\t������� \"OK\" � ������� ���������� ��������� ������.");
				return 0;
				}
				break;
			default: state = error;
				break;
			}
			break;
		case error:
		ShowMessage("\t\t\t������.\n \t\t������� \"OK\" � ������� ���������� ��������� ������.");
              return 0;
			state = start;
			i = s.length();
			break;
		}
	}
	 if (count_bracket!=0) {
			ShowMessage("\t\t\t������.\n �� ��������� ������������ ������. \t\t������� \"OK\" � ������� ���������� ��������� ������.");
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

	cl.answer(ss, file_name, accuracy);

	string ans = operation_stack.top();
	return  ans;

}



#define _CRT_SECURE_NO_WARNINGS
#endif