#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int P, K, N;
    cin >> P;
    for (int i = 0; i < P; i++) {
        cin >> K >> N;
        cout << K << " " << N * (N + 1) / 2 + N << "\n";
    }
    return 0;
}