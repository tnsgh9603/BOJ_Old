#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
map<int, string> M;
int main() {
    fastio;
    int n; 
    cin >> n;
    while (n--) {
        string s; 
        int t; 
        cin >> s >> t;
        if (M.count(t) && M[t] <= s) {
            continue;
        }
        M[t] = s;
    }
    cout << (--M.end())->second;
    return 0;
}