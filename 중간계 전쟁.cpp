#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n; 
    cin >> n;
    for (int c = 0; c < n; c++) {
        int a = 0, b = 0;
        for (int i = 0; i < 6; i++) {
            int t;
            cin >> t;
            a += t * vector<int>{ 1, 2, 3, 3, 4, 10 }[i];
        }
        for (int i = 0; i < 7; i++) {
            int t;
            cin >> t;
            b += t * vector<int>{ 1, 2, 2, 2, 3, 5, 10 }[i];
        }
        cout << "Battle " << c + 1 << ": ";
        if (a > b) {
            cout << "Good triumphs over Evil";
        }
        else if (a < b) {
            cout << "Evil eradicates all trace of Good";
        }
        else {
            cout << "No victor on this battle field";
        }
        cout << '\n';
    }
    return 0;
}
