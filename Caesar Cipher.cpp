#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    string s;
    int a, b;
    cin >> a >> b;
    cin.ignore();
    getline(cin, s);
    a %= 26;
    for (int i = 0; i < b; i++) {
        if ('A' <= s[i] && s[i] <= 'Z') {
            int tmp = s[i] - 'A';
            tmp += a;
            if (tmp >= 26) {
                tmp -= 26;
            }
            s[i] = tmp + 'A';
        }
        if ('a' <= s[i] && s[i] <= 'z') {
            int tmp = s[i] - 'a';
            tmp += a;
            if (tmp >= 26) {
                tmp -= 26;
            }
            s[i] = tmp + 'a';
        }
        cout << s[i];
    }
    return 0;
}