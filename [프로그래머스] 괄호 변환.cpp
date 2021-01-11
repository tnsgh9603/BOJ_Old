#include <iostream>
#include <string>
using namespace std;

bool check(string s) {
	int t = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') {
			t++;
		}
		else {
			//괄호가 맞지 않음
			if (t == 0) {
				return false;
			}
			t--;
		}
	}
	return true;
}

string sol(string s) {
	if (s == "") {
		return s;
	}
	string u, v;
	int Lcnt = 0, Rcnt = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') {
			Lcnt++;
		}
		else {
			Rcnt++;
		}
		if (Lcnt == Rcnt) {
			u = s.substr(0, i + 1);
			v = s.substr(i + 1);
			break;
		}
	}
	if (check(u)) {
		return u + sol(v);
	}
	else {
		string temp = "(";
		temp += sol(v) + ")";
		u = u.substr(1, u.length() - 2);
		for (size_t i = 0; i < u.length(); i++) {
			if (u[i] == '(') {
				temp += ')';
			}
			else {
				temp += '(';
			}
		}
		return temp;
	}
}

string solution(string s) {
	if (check(s)) {
		return s;
	}
	return sol(s);
}

int main() {
	string s;
	cin >> s;
	cout << solution(s);
}