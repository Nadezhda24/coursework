#ifndef _ARITHMETIC_H
#define _ARITHMETIC_H
#include <string>
#include <vector>

using namespace std;

int osn = 10;


class ar {
	
vector<int> a;

public:
	


	vector<int> GetA() {
		return a;
	}
	ar() {
		
	}
	
	ar(int n) {
		vector<int> a(n);
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

		temp.a = a;
		int r = 0;

		for (int i = 0; i < a.size(); i++) {
		
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

		return temp;
	}	
	void div(string a, string b) {

	}
	

};

#define _CRT_SECURE_NO_WARNINGS
#endif




