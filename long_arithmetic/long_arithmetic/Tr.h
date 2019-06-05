#ifndef _TR_H
#define _TR_H
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;
double translation(double  digit, int number_system_of, int number_system_in, int accuracy) {
	if (digit != 0) {


		bool flag_minus = false;
		if (digit < 0) {
			flag_minus = true;
			digit = digit * (-1);
		}
		accuracy = pow(10, accuracy);
		int str = 0;
		long long answer = 0;
		int whole_part = int(digit); // целая часть
		double fraction = digit - whole_part; // дробная часть
		int n;



		// перевод целой части
		while (whole_part > 0) {

			str++;
			n = whole_part % number_system_of;


			answer = answer * 10 + n;


			whole_part = (whole_part - n) / number_system_of;

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
				answer = answer * 10 + (int)(fraction*number_system_of);
				fraction = (fraction*number_system_of) - (int)(fraction*number_system_of);

			}

			g = answer / pow(10, count_accuracy);
		}
		else { g = 0; }


		long double ans = whole_part + g;
		if (flag_minus) {
			ans = ans * (-1);
		}
		digit = ans;
		cout << digit << endl;
	}
	else { digit = 0; }


	int j = accuracy;
	cout << digit << endl;
	if (digit != 0) {

		bool	f_m = false;

		if (digit < 0) {
			f_m = true;
			digit = digit * (-1);
		}



		long long answer = 0;
		long long whole_part = int(digit);
		// целая часть

		// дробная часть
		long long fraction_1 = (digit - whole_part)*pow(10, accuracy);
		long long fraction = 0;
		while (fraction_1>0) {
			int d = fraction_1 % 10;
			fraction = fraction * 10 + d;
			fraction_1 = fraction_1 / 10;

		}

		int str = 0;
		int rez_whole_part = 0;
		while (whole_part > 0)
		{

			int d = whole_part % 10;
			if (d > (number_system_in - 1)) {

				return 0;
			}
			else { rez_whole_part = rez_whole_part + d * pow(number_system_in, str); }


			str++;
			whole_part = whole_part / 10;

		}
		double rez_fraction = 0;
		str = 1;

		while (fraction*accuracy != 0) {

			int d = fraction % 10;

			if (d > (number_system_in - 1)) {}
			else {
				if (d == 0) { fraction = fraction / 10; }
				else {
					rez_fraction = rez_fraction + d / (pow(number_system_in, str));

					str++;
					fraction = fraction / 10;


				}
			}
		}
		cout << rez_whole_part << " " << rez_fraction << endl;

		long double rez = rez_whole_part + rez_fraction;
		if (f_m) {
			rez = rez * (-1);
		}

		return rez;
		cout << rez << endl;
	}
	else { return 0; }

}



#define _CRT_SECURE_NO_WARNINGS
#endif

