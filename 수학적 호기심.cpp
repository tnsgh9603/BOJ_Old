#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int cnt, n, m, t, a, b;
	cin >> t;  //�׽�Ʈ ���̽� �Է�
	while (t) {
		t--;
		cnt = 0;
		cin >> n >> m;
		for (a = 1; a < n; a++) { //1���� n���� �ϳ��ϳ� �� �غ���.
			for (b = a + 1; b < n; b++) {
				if (!((a * a + b * b + m) % (a * b))) {  //������ �������� ������ �����̹Ƿ� ī��Ʈ���ش�.
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}