#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
string arr[100];
int main() {
    int N , p;
    cin >> N >> p;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    cout << arr[p - 1];
    return 0;
}