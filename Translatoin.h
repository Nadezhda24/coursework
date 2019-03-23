#ifndef _TRANSLATION_H   
#define _TRANSLATION_H  
#include <string>
#include <math.h>
#include <iomanip>
using namespace std;
int t = 5;

//������� �� 10-�� � 8-�� ������� ��������� 
double translation(double  digit, int ss, int accuracy) {
	accuracy = pow(10, accuracy);
	int str = 0;
	long long answer = 0;
	int whole_part = int(digit); // ����� ����� 
	double fraction = digit - whole_part; // ������� ����� 
	int n;



	// ������� ����� ����� 
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
	// ������� ������� ����� 
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
//������� �� 10-�� � 8-�� ������� ��������� 
double translation_file(double  digit, int ss, string file_name, int accuracy) {
	accuracy = pow(10, accuracy);
	int str = 0;
	long long answer = 0;
	int whole_part = int(digit); // ����� ����� 
	double fraction = digit - whole_part; // ������� ����� 
	int n;

	ofstream f;
	f.open(file_name, ios::app);

	f << setw(t) << " ������� ����� " << digit << " � 8-�� ������� ��������� : " << endl;

	f << setw(t) << " ������� ����� ����� �����: " << endl;
	f.close();

	// ������� ����� ����� 
	while (whole_part > 0) {
		ofstream f;
		f.open(file_name, ios::app);
		f << setw(t) << ' ' << whole_part << " | " << ss << endl;

		str++;
		n = whole_part % ss;
		answer = answer * 10 + n;
		whole_part = (whole_part - n) / ss;

		f << "-" << whole_part * ss << " |--" << endl;
		f << "---- " << whole_part << endl;
		f << " " << n << endl;

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
		f.open(file_name, ios::app);
		f << " ������� ������� ����� ����� : " << endl;
		f << "| " << fraction << endl;
		f.close();

		answer = 0;

		int count_accuracy = 0;
		while (fraction*accuracy != 0) {
			ofstream f;
			f.open(file_name, ios::app);
			f << "|* " << ss << endl;
			f << "|--------" << endl;
			f << "| " << fraction * ss << endl;
			f.close();
			count_accuracy++;

			answer = answer * 10 + (int)(fraction*ss);
			fraction = (fraction*ss) - (int)(fraction*ss);
		}

		f.open(file_name, ios::app);
		f << "V" << endl;
		f.close();
		g = answer / pow(10, count_accuracy);
	}
	else { g = 0; }


	double ans = whole_part + g;
	return ans;

}

// ������� �� 8-�� � 10-�� 
double translation_10(double digit, int ss, int accuracy, string file_name) {

	ofstream f;

	f.open(file_name, ios::app);
	f << endl;
	f << setw(t) << " ������� ����� " << digit << " � 10-�� ������� ��������� : " << endl;


	long long answer = 0;
	int whole_part = int(digit);
	// ����� ����� 

	int fraction = (digit - whole_part)*pow(10, accuracy); // ������� ����� 

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



#define _CRT_SECURE_NO_WARNINGS
#endif   #pragma once
