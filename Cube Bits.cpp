#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
void sol(long long N) {
    if (!N) {
        return;
    }
    sol(N / 3);
    cout << N % 3;
}
int main() {
    fastio;
    int tc;
    cin >> tc;
    for (int t = 0; t < tc; t++) {
        long long N;
        cin >> N;
        if (!N) {
            cout << 0;
        }
        else {
            sol(N);
        }
        cout << "\n";
    }
    return 0;
}
