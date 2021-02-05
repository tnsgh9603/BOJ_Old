#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	double speed;
	int weight, strength;
	cin >> speed >> weight >> strength;
	bool hasposition;
	while (speed != 0 || weight != 0 || strength != 0) {
		if (speed <= 4.5 && weight >= 150 && strength >= 200) {
			cout << "Wide Receiver ";
			hasposition = true;
		}
		if (speed <= 6.0 && weight >= 300 && strength >= 500) {
			cout << "Lineman ";
			hasposition = true;
		}
		if (speed <= 5.0 && weight >= 200 && strength >= 300) {
			cout << "Quarterback";
			hasposition = true;
		}
		if (!hasposition) {
			cout << "No positions";
		}
		cout << "\n";
		hasposition = false;
		cin >> speed >> weight >> strength;
	}
	return 0;
}