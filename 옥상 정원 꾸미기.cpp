#include <iostream>
#include <vector>
#include <stack>
using namespace std;
stack <int> s;
vector<int> vec(1000);
int main() {
	int N;
	long long ans = 0;
	cin >> N;
	vec.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> vec[i];
	}
	for (int i = 0; i < N; i++) {
		while (!s.empty() && s.top() <= vec[i]) {
			s.pop();
		}
		ans += (long long)s.size();
		s.push(vec[i]);
	}
	cout << ans;
}