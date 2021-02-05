#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int N, cnt = 0;
	cin >> N;
	bool ok = true;
	for (int i = 0; i < N; ++i) {
		string str;
		cin >> str;
		if (str != "mumble") {
			if (cnt + 1 != stoi(str.c_str())) {
				ok = false;
				break;
			}
		} 
		cnt++;
	}
	if (ok) {
		cout << "makes sense\n";
	}
	else {
		cout << "something is fishy\n";
	}
	return 0;
}