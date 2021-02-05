#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
bool check(string s) {
    for (int i = 1; i < s.size(); i++) {
        if (s[i] < s[i - 1]) {
            return 0;
        }
    }
    return 1;
}
string f(string s) {
    string ret = s;
    while (ret[0] <= '0') {
        ret.erase(0, 1);
    }
    return ret;
}
int main() {
    fastio;
    int n;
    cin >> n;
    for (int k = 1; k <= n; k++) {
        string s;
        cin >> s;
        while (1) {
            if (check(s)) {
                cout << "Case #" << k << ": " << s << '\n';
                goto Flag;
            }
            for (int i = 0; i < s.size(); i++) {
                string temp = s;
                auto& cur = temp[s.size() - 1 - i];
                if (cur-- == '0') {
                    continue;
                }
                for (int j = s.size() - i; j < s.size(); j++) {
                    temp[j] = '9';
                }
                if (check(temp)) {
                    cout << "Case #" << k << ": " << f(temp) << '\n';
                    goto Flag;
                }
            }
            s[0]--;
            while (s[0] == '0') {
                s.erase(0, 1);
            }
        }
    Flag:;
    }
    return 0;
}