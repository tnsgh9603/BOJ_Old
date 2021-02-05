#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    fastio;
    string s;
    while (cin >> s && s != "#") {
        int cnt = 0;
        while (string("aeiou").find(s[0]) == -1 && cnt < s.size()) {
            s.push_back(s[0]);
            s.erase(0, 1);
            cnt++;
        }
        cout << s + "ay" << '\n';
    }
}