#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    fastio;
    string s, t; cin >> s;
    for (auto& i : s) if (i == '|') i = ' ';
    stringstream in(s);
    int cnt = 0;
    while (in >> t) {
        if (string("ADE").find(t[0]) != -1) cnt++;
        if (string("CFG").find(t[0]) != -1) cnt--;
    }
    cout << (cnt > 0 || !cnt && string("ADE").find(s.back()) != -1 ? "A-minor" : "C-major") << '\n';
}