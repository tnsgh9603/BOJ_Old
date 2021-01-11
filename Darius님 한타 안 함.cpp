#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
int main() {
	int k, d, a;
	scanf("%d/%d/%d", &k, &d, &a);
	string ans = k + a < d || d == 0 ? "hasu" : "gosu";
	cout << ans;
	return 0;
}