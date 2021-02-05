#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int N, M, i, j, sum, num;
    cin >> N;
    for (i = 0; i < N; i++) {
        sum = 0;
        cin >> M;
        for (j = 0; j < M; j++) {
            cin >> num;
            sum += num;
        }
        cout << sum << "\n";
    }
}