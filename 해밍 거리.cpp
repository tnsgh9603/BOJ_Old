#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
int main() {
    fastio;
    int N; 
    cin >> N;
    while (N--) {
        string a, b; 
        cin >> a >> b;
        int ans = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) {
                ans++;
            }
        }
        cout << "Hamming distance is " << ans << ".\n";
    }
    return 0;
}
