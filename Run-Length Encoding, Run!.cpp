#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    char c;
    string s;
    cin >> c >> s;
    if (c == 'D') {
        regex r(R"(([^\d])(\d+))");
        smatch m;
        for (auto it = sregex_iterator(s.begin(), s.end(), r); it != sregex_iterator(); it++) {
            string t = it->str();
            regex_match(t, m, r);
            cout << string(stoi(m[2].str()), m[1].str()[0]);
        }
        cout << '\n';
    }
    else {
        for (int i = 0, t = 1; i < s.size(); i++) {
            if (i != s.size() - 1 && s[i] == s[i + 1]) {
                t++;
            }
            else {
                cout << s[i] << t, t = 1;
            }
        }
        cout << '\n';
    }
    return 0;
}