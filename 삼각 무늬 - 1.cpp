#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int N, i;
    double A, B;
    cin >> N;
    for (i = 0; i < N; i++) {
        cin >> A >> B;
        cout << fixed << setprecision(0) << (A * A / 2) / (B * B / 2) << "\n";
    }
    return 0;
}