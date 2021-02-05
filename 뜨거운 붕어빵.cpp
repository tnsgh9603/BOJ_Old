#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n, m; 
    cin >> n >> m;
    while (n--) {
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        cout << s << '\n';
    }
    return 0;
}
