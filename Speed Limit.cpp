#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    while (1) {
        int t; 
        cin >> t;
        if (t == -1) {
            break;
        }
        int sum = 0;
        int temp = 0;
        while (t--) {
            int a, b;
            cin >> a >> b;
            sum += a * (b - temp);
            temp = b;
        }
        cout << sum << " miles\n";
    }
    return 0;
}