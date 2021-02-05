#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int T; 
    cin >> T;
    while (T--) {
        double n; 
        cin >> n;
        string s; 
        getline(cin, s);
        for (auto i : s) {
            if (i == '@') {
                n *= 3;
            }
            else if (i == '%') {
                n += 5;
            }
            else if (i == '#') {
                n -= 7;
            }
        }
        cout << fixed << setprecision(2) << n << '\n';
    }
    return 0;
}
