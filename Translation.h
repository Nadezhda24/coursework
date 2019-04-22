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
int t = 20;
int t2 = 25;
//������� �� 10-�� � 8-�� ������� ���������
double translation_file(double  digit, int ss, string file_name, int accuracy) {
	if (digit != 0) {


	bool flag_minus  = false;
	if (digit < 0) {
		  flag_minus = true;
		  digit = digit *(-1);
	}

	accuracy = pow(10, accuracy);
	int str = 0;
	long long answer = 0;
	int whole_part = int(digit); // ����� �����
	double fraction = digit - whole_part; // ������� �����
	int n;

	ofstream f;
	f.open(file_name.c_str(), ios::app);

	f << setw(t) << " ������� ����� " << digit << " � 8-�� ������� ��������� : " << endl;

	f << setw(t) << " ������� ����� ����� �����: " << endl;
	f.close();

		// ������� ����� �����
		while (whole_part > 0) {
			f.open(file_name.c_str(), ios::app);
			str++;
			n = whole_part % ss;
			f<< setw(t2)<<whole_part << " % " << ss << " = " << n << endl;
			answer = answer * 10 + n;

			f << setw(t2-1)<< "( " << whole_part << " - " << n << " ) " << " / " << ss;
			whole_part = (whole_part - n) / ss;
			f << " = " << whole_part << endl;
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
	// ������� ������� �����
	if (fraction*accuracy != 0) {
		f.open(file_name.c_str(), ios::app);
		f << " ������� ������� ����� ����� : " << endl;

		answer = 0;

		int count_accuracy = 0;
		f << setw(t2+5) <<fraction  << endl;
		f.close();
		while (fraction*accuracy != 0) {
			ofstream f;
			f.open(file_name.c_str(), ios::app);
			f <<setw(t2)<< "* " << ss << endl;
			f<<setw(t2+5) << "--------" << endl;
			f <<setw(t2)<< " " << fraction * ss << endl;
			count_accuracy++;
			answer = answer * 10 + (int)(fraction*ss);
			fraction = (fraction*ss) - (int)(fraction*ss);
			f.close();
		}

		g = answer / pow(10, count_accuracy);
	}
	else { g = 0; }


	double ans = whole_part + g;
	if (flag_minus) {
				  ans = ans *(-1);
	}
	return ans;
	  } else {return 0;}
}

// ������� �� 8-�� � 10-��
double translation_10(double digit, int ss, int accuracy, string file_name) {
 int j =  accuracy ;
 if(digit != 0) {

 bool	f_m = false;

	if (digit < 0) {
					f_m = true;
					digit= digit * (-1);
	}
	ofstream f;

	f.open(file_name.c_str(), ios::app);

	f << setw(t) << " ������� ����� " << digit << " � 10-�� ������� ��������� : " << endl;


	long long answer = 0;
	long long whole_part = int(digit);
	// ����� �����

	 // ������� �����
long long fraction_1 = (digit - whole_part)*pow(10, accuracy);
long long fraction=0;
while (fraction_1>0){
int d = fraction_1 % 10;
fraction = fraction*10 + d;
fraction_1=fraction_1/10;

}

	int str = 0;
	int rez_whole_part = 0;
	while (whole_part > 0)
	{

		int d = whole_part % 10;
	   if (d > (ss-1) )  { f << "ERROR" << endl; return 0; }
	   else {rez_whole_part = rez_whole_part + d * pow(ss, str); }

		f << d << " * " << ss << '^' << str;
		str++;
		whole_part = whole_part / 10;
		if (whole_part > 0) f << " + ";
	}
	double rez_fraction = 0;
	str = 1;

	while ( fraction*accuracy != 0) {
	  f << " + ";
		int d = fraction % 10;

		if (d > (ss - 1)) { f << "" ; }
	   else {	if (d == 0) { fraction = fraction / 10; }
		else {
			rez_fraction = rez_fraction + d / (pow(ss, str));
			f << d << " * " << ss << '^' << "(-" << str << ')';
			str++;
			fraction = fraction / 10;

			//if (fraction > 0) f << " + ";
		}
		}
	}


	double rez = rez_whole_part + rez_fraction;
	 if (f_m) {
		  rez = rez *(-1);
	 }
	f << "= " <<  rez << endl;

	f.close();
	return rez; }
	else {return 0;}
}



#define _CRT_SECURE_NO_WARNINGS
#endif   #pragma once
