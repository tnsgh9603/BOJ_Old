#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n, cnt, indegree[26], adj[26][26];
int main() {
	// indegree �迭 -1�� �ʱ�ȭ
	memset(indegree, -1, sizeof(indegree));
	cin >> n;
	vector<string> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < n; i++) {
		for (auto c : v[i]) {
			// �� ���ĺ��� üũ���ְ�, cnt�� ����� ���ĺ� ����
			if (indegree[c - 'a'] == -1) {
				indegree[c - 'a'] = 0;
				cnt++;
			}
		}
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			// mx���� ���ϴ� �� ���ڿ� �� ũ�Ⱑ ���� ���� ���� ����
			int idx = 0, mx = min(v[i].size(), v[j].size());
			string& s1 = v[i], s2 = v[j];
			// ���ϴ� �ε����� mx���� �۰�, �� ���ڰ� ���� ������ ��� idx++
			// ���� ��� �Է���
			// 3
			// abc
			// aqw
			// baw
			// �� ������ ��, i=0, j=1, idx=0 �̸�, ù ��° �ٰ� �� ��° ���� a�� ���� ���ϰ� �����Ƿ�
			// idx�� ++�ǰ� b�� q�� �񱳵ȴ� �̶� idx++�� ���߰� �ٷ� ù ��° ��(abc)�� �� ��° ��(baw)�� ���ϴ°ɷ� �Ѿ��.
			// �� ������ �̹� b�� q�� �������Ƿ� c�� w�� ���ϴ� ���� �ǹ̰� ���� �����̴�.
			// �� ��Ȯ�� �����ڸ� c�� w�������� ������ ������ �̹� b�� q���� ���� ���Ƿ� �񱳰� �Ұ����ϱ� ����
			// �������̹Ƿ� ��� ���� �翬�� ����
			while (idx < mx && s1[idx] == s2[idx]) {
				idx++;
			}
			// �Ʒ� if���� �Է���
			// aaaa
			// aa
			// ���� ������ ��쿡 �ش�� (�Է��� 
			// ��¥ �����°��� ���̽�;;
			if (idx == mx && s1.size() > s2.size()) {
				cout << '!' << '\n';
				return 0;
			}
			// idx������ �Ѱų� �̹� üũ�Ǿ��ִٸ� continue
			if (idx == mx || adj[s1[idx] - 'a'][s2[idx] - 'a']) {
				continue;
			}
			// si[idx] - 'a'�� s2[idx] - 'a'���� ���� �´ٴ� ���� üũ
			adj[s1[idx] - 'a'][s2[idx] - 'a'] = 1;
			// ������ ������ �� ++
			indegree[s2[idx] - 'a']++;
		}
	}
	vector<char> ans;
	queue<int> Q;
	for (int i = 0; i < 26; i++) {
		// ���������� 0�� �͵� push
		if (indegree[i] == 0) {
			Q.push(i);
		}
	}
	while (!Q.empty()) {
		// size�� 1���� ũ�� ����Ŭ�� �����Ƿ� ? ���
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