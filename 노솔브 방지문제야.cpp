#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int t; 
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n & (n - 1)) {
            cout << "0\n";
        }
        else {
            cout << "1\n";
        }
    }
    return 0;
}