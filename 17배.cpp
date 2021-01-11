#include <bits/stdc++.h>
using namespace std;


constexpr size_t sz = 1005;

bitset<sz> add(const bitset<sz>& a, const bitset<sz>& b) {
	bitset<sz> ret;

	bool carry = false;
	for (auto i = 0; i < sz; ++i) {
		bool sum = a.test(i) ^ b.test(i) ^ carry;
		carry = (a.test(i) & b.test(i)) | (carry & (a.test(i) ^ b.test(i)));

		ret.set(i, sum);
	}

	return ret;
}

void print(const bitset<sz>& a) {
	bool flag = false;
	for (int i = sz - 1; i >= 0; --i) {
		if (!flag && a.test(i))
			flag = true;

		if (flag)
			cout << a.test(i);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	bitset<sz> a, b;
	cin >> a;

	b = a;
	a <<= 4;

	print(add(a, b));

	return 0;
}