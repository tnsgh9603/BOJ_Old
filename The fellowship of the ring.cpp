#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int arr[32769]; //nÀÇ 15½Â= 32768
int main() {
    fastio;
    int a, b, c; 
    cin >> a >> b >> c;
    int ans = 0;
    while (c--) {
        int t;
        cin >> t;
        if (a <= t && t <= b) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}