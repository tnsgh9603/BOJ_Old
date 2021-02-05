#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n;
    cin >> n;
    long long sum = 0;
    for (auto i = 0; i < n * n; i++) {
        int temp;
        cin >> temp;
        sum += temp;
    }
    cout << sum;
    return 0;
}