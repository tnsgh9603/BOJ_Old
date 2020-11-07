#include <iostream>
#include <queue>
using namespace std;
queue <int> q;
int main() {
	int K, N;
	cin >> K >> N;
	for (int i = 1; i <= K; i++) {
		q.push(i);
	}
	cout << "<";
	while (!q.empty()) {
		for (int i = 1; i < N; i++) {
			q.push(q.front());
			q.pop();
		}
		cout << q.front();
		q.pop();
		if (!q.empty()) {
			cout << ", ";
		}
	}
	cout << ">";
	return 0;
}