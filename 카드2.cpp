#include <iostream>
#include <queue>
using namespace std;
int main() {
	queue <int> q;
	int N, a;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		q.push(i);
	}
	int b = q.front();
	while (!q.empty()) {
		q.pop();
		if (q.empty()) {
			break;
		}
		a = q.front();
		q.pop();
		q.push(a);
		a = q.front();
		b = a;
	}
	cout << b;
	return 0;
}