#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int t;
    cin >> t;
    while (t--) {
        int box;
        cin >> box;
        for (int i = 0; i < box; i++) {
            for (int j = 0; j < box; j++) {
                if (i != 0 && i != box - 1 && j != 0 && j != box - 1) {
                    cout << "J";
                }
                else {
                    cout << "#";
                }
            }
            cout << '\n';
        }
        cout << '\n';
    }
    return 0;
}