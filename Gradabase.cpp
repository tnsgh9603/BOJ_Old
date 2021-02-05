#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cout << "Case " << i + 1 << ":\n";
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int t; 
            cin >> t;
            if (t < 6) {
                cout << t + 1 << '\n';
            }
        }
    }
    return 0;
}