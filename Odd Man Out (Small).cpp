#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int N; 
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int n; 
        cin >> n;
        map<int, int> M;
        while (n--) {
            int t;
            cin >> t;
            M[t]++;
        }
        for (auto [a, b] : M) {
            if (b ^ 1) {
                continue;
            }
            cout << "Case #" << i << ": " << a << '\n';
            break;
        }
    }
    return 0;
}