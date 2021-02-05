#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n; 
    cin >> n; 
    cin.ignore();
    while (n--) {
        string s;
        getline(cin, s);
        int cnt = 0;
        for (auto i : s) {
            if (string("ADOPQR").find(i) != -1) {
                cnt++;
            }
            else if (i == 'B') {
                cnt += 2;
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}