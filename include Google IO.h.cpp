#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int N; 
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int n; 
        string s;
        cin >> n >> s;
        cout << "Case #" << i << ": ";
        for (int j = 0; j < 8 * n; j += 8) {
            int t = 0;
            for (int k = 0; k < 8; k++) {
                if (s[j + k] == 'I') {
                    t |= 1 << 7 - k;
                }
            }
            cout << char(t);
        }
        cout << '\n';
    }
    return 0;
}