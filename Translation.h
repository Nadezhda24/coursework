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
//перевод из 10-ой в 8-ую систему счисления
double translation_file(double  digit, int number_system, string file_name, int accuracy) {
	if (digit != 0) {


	bool flag_minus  = false;
	if (digit < 0) {
		  flag_minus = true;
		  digit = digit *(-1);
	}

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
			f.open(file_name.c_str(), ios::app);
			str++;
			n = whole_part % number_system;
			f<< setw(t2)<<whole_part << " % " << number_system << " = " << n << endl;
			answer = answer * 10 + n;

			f << setw(t2-1)<< "( " << whole_part << " - " << n << " ) " << " / " << number_system;
			whole_part = (whole_part - n) / number_system;
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
	// перевод дробной части
	if (fraction*accuracy != 0) {
		f.open(file_name.c_str(), ios::app);
		f << " Перевод дробной части числа : " << endl;

		answer = 0;

		int count_accuracy = 0;
		f << setw(t2+5) <<fraction  << endl;
		f.close();
		while (fraction*accuracy != 0) {
			ofstream f;
			f.open(file_name.c_str(), ios::app);
			f <<setw(t2)<< "* " << number_system << endl;
			f<<setw(t2+5) << "--------" << endl;
			f <<setw(t2)<< " " << fraction * number_system << endl;
			count_accuracy++;
			answer = answer * 10 + (int)(fraction*number_system);
			fraction = (fraction*number_system) - (int)(fraction*number_system);
			f.close();
		}

		g = answer / pow(10, count_accuracy);
	}
	else { g = 0; }


long double ans = whole_part + g;
	if (flag_minus) {
				  ans = ans *(-1);
	}
	return ans;
	  } else {return 0;}

}

// перевод из 8-ой в 10-ую
double translation_10(double digit, int number_system, int accuracy, string file_name) {
 int j =  accuracy ;
 if(digit != 0) {

 bool	f_m = false;

	if (digit < 0) {
					f_m = true;
					digit= digit * (-1);
	}
	ofstream f;

	f.open(file_name.c_str(), ios::app);

	f << setw(t) << " Перевод числа " << digit << " в 10-ую систему счисления : " << endl;


	long long answer = 0;
	long long whole_part = int(digit);
	// целая часть

	 // дробная часть
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
	   if (d > (number_system-1) )  {
		ShowMessage( "Ошибка.\nНажмите \"OK\" и введите корректное выражение заново.");
		return 0; }
	   else {rez_whole_part = rez_whole_part + d * pow(number_system, str); }

		f << d << " * " << number_system << '^' << str;
		str++;
		whole_part = whole_part / 10;
		if (whole_part > 0) f << " + ";
	}
	double rez_fraction = 0;
	str = 1;

	while ( fraction*accuracy != 0) {
	  f << " + ";
		int d = fraction % 10;

		if (d > (number_system - 1)) { f << "" ; }
	   else {	if (d == 0) { fraction = fraction / 10; }
		else {
			rez_fraction = rez_fraction + d / (pow(number_system, str));
			f << d << " * " << number_system << '^' << "(-" << str << ')';
			str++;
			fraction = fraction / 10;


		}
		}
	}


	long double rez = rez_whole_part + rez_fraction;
	 if (f_m) {
		  rez = rez *(-1);
	 }
	f << "= " <<  rez << endl;

	f.close();
	return rez; }
	else {return 0;}
}

   // перевод из десятичной в 16 , подается число, возврать строка
string  translation(double  digit, int number_system, string file_name, int accuracy) {
	if (digit != 0) {


	bool flag_minus  = false;
	if (digit < 0) {
		  flag_minus = true;
		  digit = digit *(-1);
	}

	accuracy = pow(10, accuracy);
  string result="";
	int str = 0;
	long long answer = 0;
	int whole_part = int(digit); // целая часть
	double fraction = digit - whole_part; // дробная часть
	int n;




		// перевод целой части
		while (whole_part > 0) {

			str++;
			n = whole_part % number_system;
		if(n==10){result=result+'A';}
    else if (n==11){result='B'+result;}
    else if (n==12){result='C'+result;}
    else if (n==13){result='D'+result;}
    else if (n==14){result='E'+result;}
    else if (n==15){result='F'+result;}
    else if (n==9){result='9'+result;}
    else if (n==8){result='8'+ result;}
    else if (n==7){result='7'+result;}
    else if (n==6){result='6'+result;}
    else if (n==5){result='5'+ result;}
    else if (n==4){result='4'+result;}
    else if (n==2){result='2'+result;}
    else if (n==3){result='3'+result;}
    else if (n==1){result='1'+result;}
    else if (n==0){result='0'+result;}
			answer = answer * 10 + n;


			whole_part = (whole_part - n) / number_system;

		}
	while (answer > 0) {
		n = answer % 10;
		whole_part = whole_part * 10 + n;

		answer = answer / 10;
		str--;
	}
	whole_part = whole_part * pow(10, str);
	double g;
    string result_fraction="";
	// перевод дробной части
	if (fraction*accuracy != 0) {


		answer = 0;

		int count_accuracy = 0;

		while (fraction*accuracy != 0) {

			cout  <<setw(5)<< " " << fraction * number_system << endl;
			count_accuracy++;
			answer = answer * 10 + (int)(fraction*number_system);
    if( (int)(fraction*number_system)==10){result_fraction=result_fraction+'A';}
    else if ( (int)(fraction*number_system)==11){result_fraction=result_fraction+'B';}
    else if ( (int)(fraction*number_system)==12){result_fraction=result_fraction+'C';}
    else if ( (int)(fraction*number_system)==13){result_fraction=result_fraction+'D';}
    else if ( (int)(fraction*number_system)==14){result_fraction=result_fraction+'E';}
    else if ( (int)(fraction*number_system)==15){result_fraction=result_fraction+'F';}
    else if ( (int)(fraction*number_system)==9){result_fraction=result_fraction+'9';}
    else if ( (int)(fraction*number_system)==8){result_fraction=result_fraction+'8';}
    else if ( (int)(fraction*number_system)==7){result_fraction=result_fraction+'7';}
    else if ( (int)(fraction*number_system)==6){result_fraction=result_fraction+'6';}
    else if ( (int)(fraction*number_system)==5){result_fraction=result_fraction+'5';}
    else if ( (int)(fraction*number_system)==1){result_fraction=result_fraction+'1';}
    else if ( (int)(fraction*number_system)==2){result_fraction=result_fraction+'2';}
    else if ( (int)(fraction*number_system)==3){result_fraction=result_fraction+'3';}
    else if ( (int)(fraction*number_system)==4){result_fraction=result_fraction+'4';}
    else if ( (int)(fraction*number_system)==0){result_fraction=result_fraction+'0';}

			fraction = (fraction*number_system) - (int)(fraction*number_system);

		}

		g = answer / pow(10, count_accuracy);
    result_fraction ='.' + result_fraction;
	}
	else { g = 0; result_fraction=""; }

string ans_s =result + result_fraction;
long double ans = whole_part + g;
	if (flag_minus) {
				  ans = ans *(-1);
	}
	return ans_s;
	  } else {return 0;}
}
 // перевод из 16 -ой в 10-ую
	long double translation_16(string digit, int number_system, int accuracy, string file_name) {

    int k = accuracy ;
    string fraction1="";
    if(digit != "0") {

    bool f_m = false;

    if (digit[0] == '-') {
    f_m = true;
    digit[0]= ' ';
    }

    long long answer = 0;
    string whole_part="";
    int i =0;
    while (digit[i]!='.' && i!=digit.length()){

    whole_part=whole_part+digit[i];
    i++;
    }


    i++;
    while (i<digit.length()){

    fraction1=fraction1+digit[i];
    i++;
    }

    long long fraction_1 ;

    int str = 0;
    long double rez_whole_part = 0;

    for (int j =whole_part.length()-1 ; j>= 0;j--){

    if (whole_part[j]=='1'){rez_whole_part = rez_whole_part + 1 * pow(number_system, str); }
    else if (whole_part[j]=='2'){rez_whole_part = rez_whole_part + 2 * pow(number_system, str); }
    else if (whole_part[j]=='3'){rez_whole_part = rez_whole_part + 3 * pow(number_system, str); }
    else if (whole_part[j]=='4'){rez_whole_part = rez_whole_part + 4 * pow(number_system, str); }
    else if (whole_part[j]=='5'){rez_whole_part = rez_whole_part + 5 * pow(number_system, str); }
    else if (whole_part[j]=='6'){rez_whole_part = rez_whole_part + 6 * pow(number_system, str); }
    else if (whole_part[j]=='7'){rez_whole_part = rez_whole_part + 7 * pow(number_system, str); }
    else if (whole_part[j]=='8'){rez_whole_part = rez_whole_part + 8 * pow(number_system, str); }
    else if (whole_part[j]=='9'){rez_whole_part = rez_whole_part + 9 * pow(number_system, str); }
    else if (whole_part[j]=='A'){rez_whole_part = rez_whole_part + 10 * pow(number_system, str); }
    else if (whole_part[j]=='B'){rez_whole_part = rez_whole_part + 11 * pow(number_system, str); }
    else if (whole_part[j]=='C'){rez_whole_part = rez_whole_part + 12 * pow(number_system, str); }
    else if (whole_part[j]=='D'){rez_whole_part = rez_whole_part + 13 * pow(number_system, str); }
    else if (whole_part[j]=='E'){rez_whole_part = rez_whole_part + 14 * pow(number_system, str); }
    else if (whole_part[j]=='F'){rez_whole_part = rez_whole_part + 15 * pow(number_system, str); }

    str++;

	}

    long double rez_fraction = 0;
    str = 1;

    for (int j=0;j< fraction1.length();j++) {

    if (fraction1[j] == 0) { j++; }


    if (fraction1[j]=='1'){rez_fraction = rez_fraction + 1 / (pow(number_system, str)); }
    else if (fraction1[j]=='2'){rez_fraction = rez_fraction + 2 / (pow(number_system, str)); }
    else if (fraction1[j]=='3'){rez_fraction = rez_fraction + 3/ (pow(number_system, str)); }
    else if (fraction1[j]=='4'){rez_fraction = rez_fraction + 4 / (pow(number_system, str)); }
    else if (fraction1[j]=='5'){rez_fraction = rez_fraction + 5 / (pow(number_system, str)); }
    else if (fraction1[j]=='6'){rez_fraction = rez_fraction + 6 / (pow(number_system, str)); }
    else if (fraction1[j]=='7'){rez_fraction = rez_fraction + 7 / (pow(number_system, str)); }
    else if (fraction1[j]=='8'){rez_fraction = rez_fraction + 8 / (pow(number_system, str)); }
    else if (fraction1[j]=='9'){rez_fraction = rez_fraction + 9 / (pow(number_system, str)); }
    else if (fraction1[j]=='A'){rez_fraction = rez_fraction + 10 / (pow(number_system, str)); }
	else if (fraction1[j]=='B'){rez_fraction = rez_fraction + 11 / (pow(number_system, str)); }
    else if (fraction1[j]=='C'){rez_fraction = rez_fraction + 12 / (pow(number_system, str)); }
    else if (fraction1[j]=='D'){rez_fraction = rez_fraction + 13 / (pow(number_system, str)); }
    else if (fraction1[j]=='E'){rez_fraction = rez_fraction + 14 / (pow(number_system, str)); }
    else if (fraction1[j]=='F'){rez_fraction = rez_fraction + 15 / (pow(number_system, str)); }
    str++;


    }


    long double rez = rez_fraction +rez_whole_part ;
    if (f_m) {
    rez = rez *(-1);
    }

    return rez; }
    else {return 0;}
    }


#define _CRT_SECURE_NO_WARNINGS
#endif   #pragma once
