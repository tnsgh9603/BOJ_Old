#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int N, M, ans = 0;
    cin >> N >> M;
    string arr[100], brr[100];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> brr[i];
    }
    for (int i = 0; i < M; i++) {
        int r = 0;
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                if (arr[j][i] == brr[k][i]) {
                    r++;
                }
            }
        }
        if (!r) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}
