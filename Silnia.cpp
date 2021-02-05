#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n; 
    cin >> n;
    int t = 1;
    for (int i = 1; i <= n; i++) {
        t *= i;
        t %= 10;
    }
    cout << t % 10 << '\n';
    return 0;
}