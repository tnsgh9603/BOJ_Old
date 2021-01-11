#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n, cnt, indegree[26], adj[26][26];
int main() {
	// indegree 배열 -1로 초기화
	memset(indegree, -1, sizeof(indegree));
	cin >> n;
	vector<string> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < n; i++) {
		for (auto c : v[i]) {
			// 쓴 알파벳을 체크해주고, cnt는 사용한 알파벳 종류
			if (indegree[c - 'a'] == -1) {
				indegree[c - 'a'] = 0;
				cnt++;
			}
		}
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			// mx에는 비교하는 두 문자열 중 크기가 가장 작은 것을 저장
			int idx = 0, mx = min(v[i].size(), v[j].size());
			string& s1 = v[i], s2 = v[j];
			// 비교하는 인덱스가 mx보다 작고, 비교 문자가 서로 같으면 계속 idx++
			// 예를 들어 입력이
			// 3
			// abc
			// aqw
			// baw
			// 가 들어왔을 때, i=0, j=1, idx=0 이면, 첫 번째 줄과 두 번째 줄의 a를 서로 비교하고 같으므로
			// idx가 ++되고 b랑 q가 비교된다 이때 idx++이 멈추고 바로 첫 번째 줄(abc)와 세 번째 줄(baw)을 비교하는걸로 넘어간다.
			// 그 이유는 이미 b랑 q를 비교했으므로 c와 w를 비교하는 것은 의미가 없기 때문이다.
			// 더 정확히 말하자면 c가 w순서보다 느리든 빠르든 이미 b가 q보다 먼저 오므로 비교가 불가능하기 때문
			// 사전순이므로 어떻게 보면 당연한 것임
			while (idx < mx && s1[idx] == s2[idx]) {
				idx++;
			}
			// 아래 if문은 입력이
			// aaaa
			// aa
			// 같이 들어오는 경우에 해당됨 (입력이 
			// 진짜 개변태같은 케이스;;
			if (idx == mx && s1.size() > s2.size()) {
				cout << '!' << '\n';
				return 0;
			}
			// idx범위를 넘거나 이미 체크되어있다면 continue
			if (idx == mx || adj[s1[idx] - 'a'][s2[idx] - 'a']) {
				continue;
			}
			// si[idx] - 'a'가 s2[idx] - 'a'보다 먼저 온다는 것을 체크
			adj[s1[idx] - 'a'][s2[idx] - 'a'] = 1;
			// 들어오는 간선의 수 ++
			indegree[s2[idx] - 'a']++;
		}
	}
	vector<char> ans;
	queue<int> Q;
	for (int i = 0; i < 26; i++) {
		// 진입차수가 0인 것들 push
		if (indegree[i] == 0) {
			Q.push(i);
		}
	}
	while (!Q.empty()) {
		// size가 1보다 크면 사이클이 있으므로 ? 출력
		if (Q.size() > 1) {
			cout << '?' << '\n';
			return 0;
		}
		auto cur = Q.front();
		Q.pop();
		ans.push_back(cur + 'a');
		for (int nxt = 0; nxt < 26; nxt++) {
			if (adj[cur][nxt] == 0) {
				continue;
			}
			if (--indegree[nxt] == 0) {
				Q.push(nxt);
			}
		}
	}
	if (ans.size() < cnt) {
		cout << '!' << '\n';
	}
	else for (auto c : ans) {
		cout << c;
	}
}