#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() { 
	fastio;
	int N;
	cin >> N; 
	while (N--) { 
		string a, b, sum = ""; 
		int sumInt = 0, aInt, bInt;
		cin >> a >> b;
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		aInt = stoi(a); bInt = stoi(b);
		sumInt = aInt + bInt;
		sum = to_string(sumInt);
		reverse(sum.begin(), sum.end());
		sumInt = stoi(sum);
		cout << sumInt << '\n';
	}
	return 0;
}