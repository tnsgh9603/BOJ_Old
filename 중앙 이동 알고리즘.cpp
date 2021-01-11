#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n, i, k = 2, sum = 3;
    cin >> n;
    for (i = 1; i < n; i++) {
        sum += k;
        k *= 2;
    }
    cout << sum * sum;
}