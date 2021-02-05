#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int a, b, c; 
    cin >> a >> b >> c;
    int t = a + b, sum = 0;
    while (t >= c) {
        sum += t / c;
        t = t % c + t / c;
    }
    cout << sum;
    return 0;
}
