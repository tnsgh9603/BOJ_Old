#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int arr1[11], arr2[11];
int main() {
	fastio;
	for (int i = 1; i <= 10; i++) {
		cin >> arr1[i];
	}
	for (int i = 1; i <= 10; i++) {
		cin >> arr2[i];
	}
	int score1 = 0, score2 = 0, flag = 1, flag2 = 0;
	for (int i = 1; i <= 10; i++) {
		if (arr1[i] > arr2[i]) {
			score1 += 3;
			flag = 0;
			flag2++;
		}
		else if (arr1[i] < arr2[i]) {
			score2 += 3;
			flag = 1;
			flag2++;
		}
		else {
			score1 += 1;
			score2 += 1;
		}
	}
	cout << score1 << " " << score2 << "\n";
	if (score1 > score2) {
		cout << "A";
	}
	else if (score1 < score2) {
		cout << "B";
	}
	else {
		if (!flag2) {
			cout << "D";
		}
		else if (flag == 0) {
			cout << "A";
		}
		else if (flag == 1) {
			cout << "B";
		}
		
	}
	return 0;
}