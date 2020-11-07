#include <iostream>
#include <queue>
using namespace std;
int main() {
    int T, N, M, input;
	cin >> T;
	for (int i = 1; i <= T; i++) {
        int count = 0;
		cin >> N >> M;
        queue<pair<int, int>> q;
        priority_queue<int> pq; // 우선순위 큐
        for (int j = 0; j < N; j++) {
            cin >> input;
            q.push({ j, input });
            pq.push(input);
        }
        while (!q.empty()) {
            int index = q.front().first;
            int value = q.front().second;
            q.pop();
            if (pq.top() == value) {
                pq.pop();
                count++;
                if (index == M) {
                    cout << count << endl;
                    break;
                }
            }
            else {
                q.push({ index,value });
            }
        }
	}
	return 0;
}