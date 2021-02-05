#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int num;
		cin >> num;
		vector<int> vec;
		for (int j = 0; j < num; j++) {
			int input;
			cin >> input;
			vec.push_back(input);
		}
		cin >> num;
		int mn = INT_MAX;
		for (int j = 0; j < num; j++) {
			int input;
			cin >> input;
			for (int k = 0; k < vec.size(); k++) {
				if (abs(input - vec[k]) < mn) {
					mn = abs(input - vec[k]);
				}
			}
		}
		cout << mn << "\n";
	}
	return 0;
}