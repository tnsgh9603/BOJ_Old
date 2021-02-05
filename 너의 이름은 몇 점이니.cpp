#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
int main() {
    fastio;
    int n; 
    cin >> n;
    char c;
    int ans = 0;
    while (n--) {
        cin >> c;
        ans += c - 'A' + 1;
    }
    cout << ans;
    return 0;
}
