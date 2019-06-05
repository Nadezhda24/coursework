#include <iostream>
#include <string>
#include "arithmetic.h"
#include "muParser.h"
using namespace std;


int main() {

	ar str_a(1000), str_b(1000);
	string st_a, st_b;
	cin >> st_a >> st_b;
	str_a.StrToVector(st_a);
	str_b.StrToVector(st_b);
	 str_a= str_a + str_b;
	cout << "a+b=" ;
	str_a.Output();
	cout << endl;

	str_a.StrToVector(st_a);
	str_b.StrToVector(st_b);
	str_a = str_a - str_b;
	cout << "a-b=";
	str_a.Output();
	cout << endl;
	str_a.StrToVector(st_a);
	str_b.StrToVector(st_b);
	if (str_a == str_b) { cout << "true\n"; }
	else { cout << "false\n"; }

	str_a.StrToVector(st_a);
	str_b.StrToVector(st_b);
	if (str_a > str_b) { cout << "true\n"; }
	else { cout << "false\n"; }

	str_a.StrToVector(st_a);
	str_b.StrToVector(st_b);
	str_a = str_a * str_b;
	cout << "a*b=";
	str_a.Output();
	cout << endl;


	system("pause");
	return 0;
}