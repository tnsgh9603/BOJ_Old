#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int arr[100001];
int main() {
    fastio;
    int N, n;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> n;
        arr[n]++;
    }
    for (int i = N; i >= 0; i--) {
        if (arr[i] == i) {
            cout << i;
            return 0;
        }
    }
    cout << -1;
    return 0;
}
