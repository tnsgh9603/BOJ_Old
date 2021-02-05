#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int arr[101][2];
int main() {
    fastio;
    int sum = 0;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        sum += arr[i][1] % arr[i][0];
    }
    cout << sum;
    return 0;
}