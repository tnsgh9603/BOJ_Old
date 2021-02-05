/// 10936.BASE64 µðÄÚµù

#include <iostream>
#include <string>

#define endl '\n'

using namespace std;

static const string base64Char =
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz"
"0123456789+/";

int base64Index[128];

string base64decoder(string s) {
	string ret = "";
	for (int i = 0; i < s.size(); i += 2) {
		ret.push_back((base64Index[s[i]] << 2) + (base64Index[s[i + 1]] >> 4));
		i++;
		ret.push_back((base64Index[s[i]] % 16 << 4) + (base64Index[s[i + 1]] >> 2));
		i++;
		ret.push_back((base64Index[s[i]] % 4 << 6) + base64Index[s[i + 1]]);
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < 64; i++)
		base64Index[base64Char[i]] = i;

	string s;
	cin >> s;
	string base64decode = base64decoder(s);
	while (base64decode.back() == '\0')
		base64decode.pop_back();
	cout << base64decode << endl;
}