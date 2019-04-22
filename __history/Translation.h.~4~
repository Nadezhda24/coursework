#ifndef _TRANSLATION_H
#define _TRANSLATION_H
#pragma hdrstop
#include "Unit1.h"
#include "Unit2.h"
#include <vcl.h>
#include <tchar.h>
#include <string>
#include <math.h>
#include <iomanip>
#include <iostream>
#include <iomanip>


using namespace std;
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
 bool	f_m = false;

	if (digit < 0) {
					f_m = true;
					digit= digit * (-1);
	}
	ofstream f;

	f.open(file_name.c_str(), ios::app);

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
	 if (f_m) {
		  rez = rez *(-1);
	 }
	f << "= " <<  rez << endl;

	f.close();
	return rez;
}



#define _CRT_SECURE_NO_WARNINGS
#endif   #pragma once
