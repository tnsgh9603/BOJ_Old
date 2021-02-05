#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int tc; 
    cin >> tc;
    double bunmo = 0, bunja = 0;
    while (tc--) {
        int n; 
        cin >> n;
        if (n != -1) {
            bunmo++;
            bunja += n;
        }
    }
    cout << fixed << setprecision(4) << bunja / bunmo;
    return 0;
}