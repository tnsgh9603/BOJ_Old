#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int M, a = 1, b = 1, s, r_num = 1;
	bool r = true;
	cin >> M;
	for (int i = 0; i < M; i++)	{
		cin >> a >> b >> s;
		r_num = (r_num / a) * b;
		r = s == 1 ? !r : r; 
	}
	if (r) {
		cout << "0 " << r_num;
	}
	else {
		cout << "1 " << r_num;
	}
	return 0;
}