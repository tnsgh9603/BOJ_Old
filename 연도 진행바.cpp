#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
string Month[13] = { "", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" },M, D, Y, T;
double DayOfMonth[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }, ans, sum, tmp, NDY; 
int main() {
	fastio;
	cin >> M >> D >> Y >> T;
	if (stoi(Y) % 400 == 0 || (stoi(Y) % 4 == 0 && stoi(Y) % 100 != 0)) {
		NDY = 366; // À±³â
	}
	else {
		NDY = 365; // Æò³â
	}
	for (int i = 1; i <= 12; i++) {
		if (Month[i] == M) {
			sum += stod(D) - 1;
			break;
		}
		else {
			sum += DayOfMonth[i];
			if (i == 2 && NDY == 366) {
				sum++;
			}
		}
	}
	tmp = double((T[0] - '0') * 10.0 + (T[1] - '0')) * 60.0 + double((T[3] - '0') * 10 + (T[4] - '0'));
	tmp /= 24.0 * 60.0;
	cout << fixed << setprecision(9) << (sum + tmp) / NDY * 100.0;
	return 0;
}