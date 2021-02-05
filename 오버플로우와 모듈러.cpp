#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n, m, arr[100];
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    long long asw = arr[0];
    for (int i = 1; i < n; i++) {
        asw = (asw % m) * (arr[i] % m);
    }
    cout << asw % m;
    return 0;
}