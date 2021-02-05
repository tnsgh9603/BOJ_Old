#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int n;
	cin >> n;
	cin.ignore();
	string s;
	for (int i = 0; i < n; i++)	{
		getline(cin, s);
		if (s == "P=NP") {
			cout << "skipped\n";
		}
		else {
			istringstream ss(s);
			string stringbuffer;
			getline(ss, stringbuffer, '+');
			int a = stoi(stringbuffer);
			getline(ss, stringbuffer, '+');
			getline(ss, stringbuffer, '+');
			int b = stoi(stringbuffer);
			cout << a + b << "\n";
		}
	}
	return 0;
}