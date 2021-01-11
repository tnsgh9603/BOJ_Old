#include <iostream>
#include <deque>
using namespace std;
deque <int> dq;
int main() {
	int N, M, num, index, cnt = 0;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		dq.push_back(i);
	}
	while (M--) {
		cin >> num;
		for (int i = 0; i < dq.size(); i++) {
			if (dq[i] == num) {
				index = i;
			}
		}
		if (index < dq.size() - index) {
			while (1) {
				if (dq.front() == num) {
					dq.pop_front();
					break;
				}
				cnt++;
				dq.push_back(dq.front());
				dq.pop_front();
			}
		}
		else {
			while (1) {
				if (dq.front() == num) {
					dq.pop_front();
					break;
				}
				cnt++;
				dq.push_front(dq.back());
				dq.pop_back();
			}
		}
	}
	cout << cnt;
	return 0;
}