/*
#include <iostream>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;
	cout.precision(11);

	int t;
	cin >> t;
	while (t--) {
		vector <int> vec;
		int l, n, a, sum = 0, k = 1, div = 1;
		double avg = 0, ans = 987654321;
		cin >> l >> n;
		for (int i = 1; i <= l; i++) {
			cin >> a;
			vec.push_back(a);
		}
		for (int j = 0; j < vec.size(); j++) {
			for (int k = j; k < vec.size(); k++) {
				sum = 0;
				for (int q = j; q <= k; q++) {
					sum += vec[q];
				}
				avg = double(sum) / double(k - j + 1);
				if (avg < ans && k - j + 1 >= n) {
					ans = avg;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
*/
/*
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int N; cin >> N;
	while (N--) {
		int n, m; cin >> n >> m;
		vector<int> v(n + 1), prefix(n + 1);
		for (int i = 1; i <= n; i++) cin >> v[i];
		for (int i = 1; i <= n; i++) prefix[i] = prefix[i - 1] + v[i];
		double ans = 1e9;
		for (int k = m; k <= n; k++) for (int i = 1; i <= n - k + 1; i++) {
			ans = min(ans, (double)(prefix[i + k - 1] - prefix[i - 1]) / k);
		}
		cout << fixed << setprecision(8) << ans << '\n';
	}
}
*/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n, m, v[1001];
double prefix[1001], arr[1001], dp[1001];

bool check(double mid) {
	for (int i = 1; i <= n; i++) {
		arr[i] = mid - v[i];
	}
	for (int i = 1; i <= n; i++) {
		prefix[i] = prefix[i - 1] + arr[i];
	}
	for (int i = m; i <= n; i++) {
		if (i == m) {
			dp[i] = prefix[i] - prefix[i - m];
		}
		else {
			dp[i] = max(dp[i - 1] + arr[i], prefix[i] - prefix[i - m]);
		}
		if (dp[i] >= 0.0) {
			return true;
		}
	}
	return false;
}

int main() {
	fastio;
	int N; cin >> N;
	while (N--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) cin >> v[i];
		double lo = 0.0, hi = 100.0;
		while (hi - lo >= 1e-8) {
			double mid = (lo + hi) / 2;
			(check(mid) ? hi : lo) = mid;
		}
		cout << fixed << setprecision(8) << (lo + hi) / 2 << '\n';
	}
}