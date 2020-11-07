#include <iostream>
#include <stack>
using namespace std;
stack <pair<int,int>> s;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, input;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		bool flag = false;
		cin >> input;
		while (!s.empty()) {
			if (s.top().second > input) {
				cout << s.top().first << " ";
				break;
			}
			s.pop();
		}
		if (s.empty()) {
			cout << '0' << " ";
		}
		s.push(make_pair(i, input));
	}
	return 0;
}