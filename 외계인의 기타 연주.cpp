#include <iostream>
#include <stack>
using namespace std;
stack <int> s[7];
int main() {
	int N, P, a, b, count = 0;
	cin >> N >> P;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		if (s[a].empty()) {
			s[a].push(b);
			count++;
		}
		else if (!s[a].empty() && s[a].top() > b) {
			while (!s[a].empty() && s[a].top() > b) {
				s[a].pop();
				count++;
			}
			if (!s[a].empty() && s[a].top() == b) {
				continue;
			}
			s[a].push(b);
			count++;
		}
		else if (!s[a].empty() && s[a].top() < b) {
			s[a].push(b);
			count++;
		}
	}
	cout << count;
	return 0;
}