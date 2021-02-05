#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int n = 0, i, j, s_1 = 0, s_2 = 0, s_3 = 0, s_4 = 0, axis = 0, one = 0, two = 0;
	cin >> n;
	for (i = 0; i < n; i++) {
		one = two = 0;
		cin >> one >> two;
		if (!one || !two) {
			axis++;
		}
		if ((one > 0) && (two > 0)) {
			s_1++;
		}
		else if ((one > 0) && (two < 0)) {
			s_4++;
		}
		else if ((one < 0) && (two > 0)) {
			s_2++;
		}
		else if ((one < 0) && (two < 0)) {
			s_3++;
		}
	}
	printf("Q1: %d\nQ2: %d\nQ3: %d\nQ4: %d\nAXIS: %d\n", s_1, s_2, s_3, s_4, axis);
	return 0;
}