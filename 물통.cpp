#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
bool visited[201][201][201];
vector<int> vec;
int main() {
	fastio;
	int A, B, C;
	cin >> A >> B >> C;
	queue<pair<pair<int, int>, int>> q;
	q.push({ { 0,0 }, C });
	while (!q.empty()) {
		int a = q.front().first.first;
		int b = q.front().first.second;
		int c = q.front().second;
		q.pop();
		if (visited[a][b][c]) {
			continue;
		}
		visited[a][b][c] = 1;
		if (!a) {
			vec.push_back(c);
		}
		if (a + b > B) {
			q.push({ {a + b - B, B }, c });
		}
		else {
			q.push({ { 0,a + b }, c });
		}
		if (a + c > C) {
			q.push({ {a + c - C, b}, C });
		}
		else {
			q.push({ {0, b},a + c });
		}
		if (b + a > A) {
			q.push({ {A, b + a - A},c });
		}
		else {
			q.push({ {a + b, 0},c });
		}
		if (b + c > C) {
			q.push({ {a, b + c - C},C });
		}
		else {
			q.push({ {a, 0},b + c });
		}
		if (c + a > A) {
			q.push({ {A, b},a + c - A });
		}
		else {
			q.push({ {c + a, b},0 });
		}
		if (c + b > B) {
			q.push({ {a, B},b + c - B });
		}
		else {
			q.push({ {a, c + b},0 });
		}
	}
	sort(vec.begin(), vec.end());
	for (auto i : vec) {
		cout << i << " ";
	}
	return 0;
}