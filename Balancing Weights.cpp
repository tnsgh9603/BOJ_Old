#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int N;
    cin >> N;
    while (N--) {
        int n, t, sum = 0;
        cin >> n;
        while (n--) {
            cin >> t, sum += t;
        }
        cout << (sum ? sum > 0 ? "Right" : "Left" : "Equilibrium") << '\n';
    }
    return 0;
}