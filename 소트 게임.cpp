#include <iostream>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;
int N, K;
map <string, bool> visited;
int BFS(string s) {
	// 오름차순 정렬 -> 만들고자 하는 순서
	string correct = s;
	sort(correct.begin(), correct.end());
	// pair < 만든 순서, 바꾼 횟수 >
	queue<pair<string, int>> Q;
	Q.push(pair<string, int>(s, 0));
	visited[s] = true;

	while (!Q.empty()) {
		string now = Q.front().first;
		int cnt = Q.front().second;
		Q.pop();
		// 정답 나오면 끝!
		if (now == correct) {
			return cnt;
		}
		// 바꿀 수 있는 경우를 다 바꿔봄
		for (int i = 0; i <= N - K; i++) {
			// 중간부분 빼서
			string temp = now.substr(i, K);
			// 돌려보고
			reverse(temp.begin(), temp.end());
			// 새로운거 만듬
			string next = now.substr(0, i);
			next += temp;
			// now 의 끝까지
			next += now.substr(i + K);
			// 중복체크
			if (!visited.count(next)) {
				Q.push(pair<string, int>(next, cnt + 1));
				visited[next] = true;
			}
		}
	}
	return -1;
}
int main() {
	ios_base::sync_with_stdio(false); 
	cout.tie(NULL); 
	cin.tie(NULL);
	
	string ST;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		char a;
		cin >> a;
		ST += a;
	}

	cout << BFS(ST);

	return 0;
}