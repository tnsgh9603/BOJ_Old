#include <bits/stdc++.h>
using namespace std;
int main() {
	int x1, x2, x3, x4, y1, y2, y3, y4;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
	cout << pow(max(max(x4, x2) - min(x3, x1), max(y4, y2) - min(y3, y1)), 2);
	return 0;
}
