#ifndef _ARITHMETIC_H
#define _ARITHMETIC_H
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int osn = 10;

int num = 1000;

class ar {

vector<int> a;

public:
	
	ar(int n) {
	
		for(int i = 0; i<n; i++){
			a.push_back(0);
		
		}
		
	
	
	}

	ar() {
	
	}

	vector<int> GetA() {
		return a;
	}
	

      void StrToVector(string str) {
		  a.clear();

		for (int i = str.size()-1; i >= 0; i--) {
			a.push_back(str[i] - '0' );
			
		}
		
	}

	void Output()
	{
		for (int i = a.size()-1; i >= 0; i--)
			cout << a[i];
	}


	bool  operator==(ar b) {
		
		if (a.size() != b.a.size()) { 
			return false; }
		for (int i = 0; i < a.size(); i++) {
			if (a.at(i) != b.a.at(i)) {
				return false;
			}
		}
		return true;
	}

	bool operator>(ar b) {
		if (a.size() != b.a.size())
			return a.size() > b.a.size();
		for (int i = a.size() - 1; i >= 0; i--) {
			if (a.at(i) != b.a.at(i)) {
				return a.at(i) > b.a.at(i);
			}
		}
		return false;
	}

	bool operator<(ar b) {
		if (a.size() != b.a.size())
			return a.size() < b.a.size();
		for (int i = a.size() - 1; i >= 0; i--) {
			if (a.at(i) != b.a.at(i)) {
				return a.at(i) < b.a.at(i);
			}
		}
		return false;
	}

	ar operator+(ar b) {
	
		ar temp;
		int max_size; 
		if (a.size() < b.a.size()) {
			max_size = b.a.size();
			while (a.size() < max_size) {
				a.push_back(0);
			}
		}
		else {
			max_size = a.size();
			while (b.a.size() < max_size) {
				b.a.push_back(0);
			}
		}
		
		int r = 0;

		for (int i = 0; i < max_size; i++) {
			
			temp.a.push_back( a.at(i) + b.a.at(i) + r);
			
			if (temp.a.back() >= osn) {
				int n = temp.a.back();
			    temp.a.pop_back();
				temp.a.push_back(n -osn);
				r = 1;
			}
			else {
				r = 0;
			}
		}
		
		
		return  temp;
	}
	ar operator-(ar b){
		ar temp(num);

		int max_size;
		if (a.size() < b.a.size()) {
			max_size = b.a.size();
			while (a.size() < max_size) {
				a.push_back(0);
			}
		}
		else {
			max_size = a.size();
			while (b.a.size() < max_size) {
				b.a.push_back(0);
			}
		}

		temp.a = a;
		int r = 0;

		for (int i = 0; i < a.size()-1; i++) {
		
			temp.a.at(i) -= b.a.at(i) + r;
			if (temp.a.at(i) < 0) {
				temp.a.at(i) += osn;
				temp.a.at(i + 1)--;
			}	
		}

	
		return temp;
	}	
	ar operator*(ar b) {
		ar temp(a.size() + b.a.size());
		while (temp.a.size() <a.size() * b.a.size()) {
			temp.a.push_back(0);
		
		}
		temp.a.push_back(0);
		b.a.push_back(0);
		
	

		for (int i = 0; i < a.size(); i++) {
			int r = 0;
			
			for (int j = 0; j < b.a.size() | r; j++) {

				
				temp.a.at(i + j) += a.at(i) * b.a.at(j) + r;
				
				r = temp.a.at(i + j) / osn;
				
				int n = temp.a.at(i + j);
				
				temp.a.at(i + j) = n - (r*osn);
				
			}
		}

		int index;
		for (int i = 0; i < temp.a.size(); i++) {
			if (temp.a.at(i) != 0) { index = i; }

		}
		
		temp.a.erase(temp.a.begin() + index +1, temp.a.begin() + temp.a.size());
		return temp;
	}	

	/*void Levelup() {
		for (int i = a.size(); i >= 1; i--)
			a.at(i) = a.at(i - 1);
		
			a.push_back(0);
	}

	ar operator/(ar b) {
		ar temp(num), temp1(num);
		for (int i = a.size() - 1; i >= 0; i--) {
			//temp1.Levelup();
			temp1.a.at(0) = a.at(i);
			ar x(num) ;
			x.a.clear();
			ar l(num);
			l.a.clear();
			ar r(num);
			int a = osn;
			stringstream ss;
			ss << a;
			string str = ss.str();
			r.StrToVector(str);
			cout << "r: ";
			r.Output();
			while (l < r  || l==r ) {
				ar m = (l + r) * 2 ;
				cout << "b: ";
				b.Output();

				ar cur = m *b;

				if (cur < temp1 || cur == temp1) {
				
					x = m;
					m.Output();
					cout << endl;
					l = m + 1;
					l.Output();
					cout << endl;

				}
				else {
					ar j(1);
					j.a.push_back(1);
					r = m - j;
					j.a.clear();
					r.Output();
					cout << endl;
				}
				cout << temp.a.at(i)<< endl;
				cout << x.a.at(0)<< endl;
				temp.a.at(i) = x.a.at(0);
				temp = temp - b * x;
			}
		
		
		}
		return temp;

	}*/
		
};

#define _CRT_SECURE_NO_WARNINGS
#endif




