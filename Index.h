#ifndef _INDEX_H   
#define _INDEX_H 
#include <string>
using namespace std;

int k, k_op;
//����������� ��� ������ ��������� 
int index(char c) {
	if (((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z'))) { k = 1; }
	else if (((c >= '0') && (c <= '9'))) { k = 2; }
	else if ((c == '%') || (c == '+') || (c == '-') || (c == '*') || (c == '/') || (c == '(') || (c == ')')) { k = 3; }
	else if (c == ' ') { k = 4; }
	return k;
}

//��������� ��������� 
int indexk_op(string z) {

	if ((z == "/") || (z == "*") || (z == "%") || (z == "div")) { k_op = 3; }
	else if ((z == "+") || (z == "-")) { k_op = 2; }
	else if (z == "(") { k_op = 1; }
	else if (z == ")") { k_op = 0; }
	else if (isdigit(z[0]) || z[0] == ' ') { k_op = 4; }
	return k_op;
}


#define _CRT_SECURE_NO_WARNINGS
#endif   
