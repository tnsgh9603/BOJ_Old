#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	int n;
	cin >> n;
	for (int a0 = 0; a0 < n; ++a0) {
		int pd, pc;
		char dot, coupon, payment;
		scanf("%d.%d %c %c %c", &pd, &pc, &dot, &coupon, &payment);
		double price = 100 * pd + pc;
		switch (dot) {
		case 'R':
			price *= 0.55;
			break;
		case 'G':
			price *= 0.7;
			break;
		case 'B':
			price *= 0.8;
			break;
		case 'Y':
			price *= 0.85;
			break;
		case 'O':
			price *= 0.9;
			break;
		case 'W':
			price *= 0.95;
			break;
		}
		if (coupon == 'C') {
			price *= 0.95;
		}
		int discounted = (int)round(price), dollars = discounted / 100, cents = discounted % 100;
		if (payment == 'C') {
			if (cents % 10 <= 5) {
				cents -= cents % 10;
			}
			else {
				cents += 10 - cents % 10;
				if (cents == 100) {
					++dollars;
					cents = 0;
				}
			}
		}
		printf("$%d.%02d\n", dollars, cents);
	}
	return 0;
}