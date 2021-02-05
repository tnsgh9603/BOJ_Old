/// 10935.BASE64ÀÎÄÚµù

#include <iostream>
#include <string>

#define endl '\n'

using namespace std;

static const string base64Char =
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz"
"0123456789+/";

int base64_decode_index[128];

string base64encoder(string s) {
	string ret = "";
	int sSize = s.size();
	s += '\0';

	for (int i = 0; i < sSize;) {
		ret.push_back(base64Char[s[i] >> 2]);
		ret.push_back(base64Char[(s[i] % 4 << 4) + (s[i + 1] >> 4)]);
		if (++i == sSize) {
			ret.push_back('=');
			ret.push_back('=');
			break;
		}
		ret.push_back(base64Char[(s[i] % 16 << 2) + (s[i + 1] >> 6)]);
		if (++i == sSize) {
			ret.push_back('=');
			break;
		}
		ret.push_back(base64Char[s[i++] % 64]);
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	string base64encode = base64encoder(s);
	cout << base64encode << endl;
}