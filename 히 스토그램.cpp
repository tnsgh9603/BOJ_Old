#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n, a;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        for (int j = 0; j < a; j++) {
            cout << "=";
        }
        cout << '\n';
    }
    return 0;
}