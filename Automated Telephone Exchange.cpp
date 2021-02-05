#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int ate;
    cin >> ate;
    int cnt = 0;
    for (int i = 0; i <= 99; i++) {
        for (int j = 0; j <= 99; j++) {
            if (ate - i - j == 0) {
                cnt++; 
            }
        }
    }
    cout << cnt;
    return 0;
}
