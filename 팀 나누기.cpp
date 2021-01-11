#include <iostream>
#include <vector>
using namespace std;
vector <int> vec;
int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	vec.push_back(a);
	vec.push_back(b);
	vec.push_back(c);
	vec.push_back(d);
	cout << abs(b + c - a - d);
	return 0;
}