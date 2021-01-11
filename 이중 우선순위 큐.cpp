#include <iostream>
#include <set>
using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int k;
		char a; int b;
		multiset <int> st;
		cin >> k;
		for (int i = 0; i < k; i++) {
			cin >> a >> b;
			if (a == 'I') {
				st.insert(b);
			}
			else if (a == 'D') {
				if (!st.empty()) {
					if (b == 1) {
						st.erase(--st.end());
					}
					else if (b == -1) {
						st.erase(st.begin());
					}
				}
			}
		}
		if (st.empty()) {
			cout << "EMPTY\n";
		}
		else {
			cout << *--st.end() << " " << *st.begin() << "\n";
		}
	}
	return 0;
}