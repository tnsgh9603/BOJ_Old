#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int a, b;
	cin >> a >> b;
	int quo = a / b, rest = a % b, i = 0;
	cout << quo << "."; //�Ҽ����� ���� �κ��� ���� ����Ѵ�.
	while (i < 2000) {
		quo = rest * 10 / b;
		cout << quo;
		rest = rest * 10 % b;
		if (rest == 0) {
			break;
		}
		i++;
	}
	return 0;
}