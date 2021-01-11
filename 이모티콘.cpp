#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int arr[1003];
int main() {
    fastio;
    int n;
    cin >> n;
    fill(arr, arr + 1002, INT_MAX / 2);
    arr[1] = 0;
    for (int i = 1; i <= 1000; ++i) {
        for (int j = 2; j * i <= 1000; ++j) {
            arr[j * i] = min(arr[j * i], arr[i] + j);
        }
        for (int j = 1000; j >= 2; --j) {
            arr[j] = min(arr[j], arr[j + 1] + 1);
        }
    }
    cout << arr[n];
    return 0;
}