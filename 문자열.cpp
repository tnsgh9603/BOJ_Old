#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
int main() {
    fastio;
    string s; 
    int n;
    for (cin >> n; n--;) {
        cin >> s; 
        cout << s[0] << s.back() << '\n';
    }
    return 0;
}