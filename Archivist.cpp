#include <bits/stdc++.h>
using namespace std;
int main() {
	int a;
	cin >> a;
	if (a == 1996 || a == 1997 || a == 2000 || a == 2007 || a == 2008 || a == 2013 || a == 2018) {
		cout << "SPbSU";
	}
	else if (a==2006){
		cout << "PetrSU, ITMO";
	}
	else {
		cout << "ITMO";
	}
	return 0;
}