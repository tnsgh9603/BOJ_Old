#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n; 
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        cout << (s.back() & 1 ? "odd" : "even") << '\n';
    }
    return 0;
}