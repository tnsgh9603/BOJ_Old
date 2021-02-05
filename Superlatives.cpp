#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        int a, b; 
        cin >> a >> b;
        int cnt = 0;
        while (a > b) {
            cnt++;
            b *= 5;
        }
        cout << "Data Set " << i << ":\n";
        if (!cnt) {
            cout << "no drought" << '\n';
        }
        else {
            for (int j = 0; j < cnt - 1; j++) {
                cout << "mega ";
            }
            cout << "drought" << '\n';
        }
        cout << '\n';
    }
    return 0;
}