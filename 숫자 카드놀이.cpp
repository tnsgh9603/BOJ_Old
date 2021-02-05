#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n;
    while (cin >> n && n) {
        vector<int> v{ n };
        while (n >= 10) {
            string s = to_string(n);
            int t = 1;
            for (int i = 0; i < s.size(); i++) {
                t *= s[i] - '0';
            }
            v.push_back(t);
            n = t;
        }
        for (auto i : v) {
            cout << i << ' '; 
        }
        cout << '\n';
    }
    return 0;
}
