#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> history, science;
int main() {
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	science.push_back(a);
	science.push_back(b);
	science.push_back(c);
	science.push_back(d);
	history.push_back(e);
	history.push_back(f);
	sort(science.begin(), science.end());
	sort(history.begin(), history.end());
	cout << science[1] + science[2] + science[3] + history[1];
	return 0;
}