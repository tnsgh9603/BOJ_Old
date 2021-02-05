#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    int n;
    while (cin >> n && n) {
        string s; 
        char c;
        while (n--) {
            cin >> c, s += c;
        }
        int cnt = 0;
        for (int i = 0, t = 0; i < s.size(); i++) {
            if (s.substr(i, 4) == "2020") {
                cnt++;
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}