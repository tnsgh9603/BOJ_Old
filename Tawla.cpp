#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	string nickname[7] = { "null", "Yakk", "Doh", "Seh", "Ghar", "Bang", "Sheesh" };
	int t; int a, b, Max, Min;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> a >> b;
		Max = max(a, b);
		Min = min(a, b);
		cout << "Case " << i + 1 << ": ";
		if (Max == Min) {
			switch (Max) {
			case 1:
				cout << "Habb Yakk\n";
				break;
			case 2:
				cout << "Dobara\n";
				break;
			case 3:
				cout << "Dousa\n";
				break;
			case 4:
				cout << "Dorgy\n";
				break;
			case 5:
				cout << "Dabash\n";
				break;
			case 6:
				cout << "Dosh\n";
				break;
			}
		}
		else if (Min == 5 && Max == 6) {
			cout << "Sheesh Beesh\n";
		}
		else {
			cout << nickname[Max] << " " << nickname[Min] << "\n";
		}
	}
	return 0;
}