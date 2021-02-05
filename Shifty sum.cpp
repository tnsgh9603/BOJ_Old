#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    long a, b;
    cin >> a >> b;
    long sum = a;
    for (int i = 1; i <= b; i++) {
        sum += a * (pow(10, i));
    }
    cout << sum;
    return 0;
}