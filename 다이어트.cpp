#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
vector <long long> ans;
int main() {
	int G, a;
	cin >> G;
	for (int i = 1;; i++) {
		if (i * i > G) {
			a = i;
			break;
		}
	}
	int start = 1, end = a;
	bool flag = false;

	while (start < end) {
		long long result = end * end - start * start;
		if (result == G) {
			ans.push_back(end);
			flag = true;
			end++;
		}
		else if (result > G) {
			start++;
		}
		else {
			end++;
		}
	}
	sort(ans.begin(), ans.end());
	if (flag) {
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << "\n";
		}
	}
	else {
		cout << "-1" << "\n";
	}
	return 0;
}