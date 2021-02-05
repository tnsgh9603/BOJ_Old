#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int N; 
    cin >> N;
    while (N--) {
        int n;
        cin >> n;
        if (n == 1) {
            cout << 'A' << '\n';
        }
        else {
            cout << char('A' + (n / 3 + "101"[n % 3] - '0') % 4) << '\n';
        }
    }
    return 0;
}