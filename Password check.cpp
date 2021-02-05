#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n; 
    cin >> n;
    while (n--) {
        int t;
        string s;
        cin >> t >> s;
        string t1 = "abcdefghijklmnopqrstuvwxyz", t2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ", t3 = "0123456789", t4 = "+_)(*&^%$#@!./,;{}";
        auto f = [&](string t) {
            for (auto i : t) {
                if (s.find(i) != -1) {
                    return 1;
                }
            }
            return 0;
        };
        if (t < 12 || !f(t1) || !f(t2) || !f(t3) || !f(t4)) {
            cout << "invalid" << '\n';
        }
        else {
            cout << "valid" << "\n";
        }
    }
    return 0;
}