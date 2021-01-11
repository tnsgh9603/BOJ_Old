#include <bits/stdc++.h>
using namespace std;
vector <int> vec;
int main() {
	for (int i = 0; i < 2; i++) {
		string s;
		getline(cin, s);
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == ':') {
				s.erase(i, 1);
			}
		}
		stringstream ss(s);
		int a, b, c;
		ss >> a >> b >> c;
		vec.push_back(a);
		vec.push_back(b);
		vec.push_back(c);
	}
	int h1 = vec[0], m1 = vec[1], s1 = vec[2], h2 = vec[3], m2 = vec[4], s2 = vec[5];
	if (h1 > h2 || (h1 == h2 && m1 > m2) || (h1 == h2 && m1 == m2 && s1 > s2)) {
		if (s2 > s1) {
			m1--;
			s1 += 60;
		}
		if (m2 > m1) {
			h1--;
			m1 += 60;
		}
		cout << 86400 - ((h1 - h2) * 3600 + (m1 - m2) * 60 + s1 - s2);
	}
	else if (h1 == h2 && m1 == m2 && s1 == s2) {
		cout << 0;
	}
	else if (h1 < h2 || (h1 == h2 && m1 < m2) || (h1 == h2 && m1 == m2 && s1 < s2)) {
		if (s1 > s2) {
			m2--;
			s2 += 60;
		}
		if (m1 > m2) {
			h2--;
			m2 += 60;
		}
		cout << (h2 - h1) * 3600 + (m2 - m1) * 60 + s2 - s1;
	}
	return 0;
}