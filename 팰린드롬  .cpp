#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int dp[5001][5001];
int main() {
	fastio;
	int n;
	cin >> n;
	string str;
	cin >> str;
	string str_rv = str;
	reverse(str_rv.begin(), str_rv.end());
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (str[i - 1] == str_rv[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
		}
	}
	cout << n - dp[n][n];
	return 0;
}
/*
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n, cache[5000][5000];
string s;

int sol(int l, int r) {
	if (r - l <= 1) return s[l] != s[r];
	int& ret = cache[l][r];
	if (ret != -1) return ret;
	if (s[l] == s[r]) return ret = sol(l + 1, r - 1);
	return ret = min(sol(l, r - 1), sol(l + 1, r)) + 1;
}

int main() {
	fastio;
	memset(cache, -1, sizeof(cache));
	cin >> n >> s;
	cout << sol(0, s.size() - 1) << '\n';
}
*/
/*
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
map <char, int> mp;
map <char, int>::iterator iter;
int main() {
	fastio;
	int n;
	cin >> n;
	string s;
	cin >> s;
	int len = s.length();
	for (int i = 0; i < len; i++) {
		mp[s[i]]++;
	} 
	int cnt = 0;
	for (iter = mp.begin(); iter != mp.end(); iter++) {
		if (iter->second % 2) {
			cnt++;
		}
	}
	if (!cnt) {
		cout << 0;
	}
	else {
		cout << cnt - 1;
	}
	return 0;
}
*/