#include <iostream>
#include <string>
#include "arithmetic.h"

using namespace std;


int main() {

	ar str_a, str_b;
	string st_a, st_b;
	cin >> st_a >> st_b;
	str_a.StrToVector(st_a);
	str_b.StrToVector(st_b);
	 str_a= str_a + str_b;
	cout << "a+b=" ;
	str_a.Output();
	cout << endl;


	system("pause");
	return 0;
}