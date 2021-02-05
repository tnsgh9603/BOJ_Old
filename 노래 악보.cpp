#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int arr_N[101], arr_Q[1001];
int main() {
    fastio;
    int N, Q;
    cin >> N >> Q;
    for (int i = 0; i < N; i++) {
        cin >> arr_N[i];
    }
    for (int j = 0; j < Q; j++) {
        cin >> arr_Q[j];
    }
    for (int j = 0; j < Q; j++) {
        int sum = -1, temp = arr_Q[j];
        for (int i = 0; i < N; i++) {
            sum = sum + arr_N[i];
            if (sum >= temp) {
                cout << i + 1 << "\n";
                break;
            }
        }
    }
    return 0;
}
