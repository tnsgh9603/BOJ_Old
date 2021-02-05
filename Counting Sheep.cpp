#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n; 
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int t, cnt = 0;
        cin >> t;
        while (t--) {
            string s; 
            cin >> s;
            if (s == "sheep") {
                cnt++;
            }
        }
        cout << "Case " << i << ": This list contains " << cnt << " sheep." << "\n\n";
    }
}