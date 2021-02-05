#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
long long t(int x) {
    long long sum = 0;
    for (int i = 1; i <= x; i++) {
        sum += i;
    }
    return sum;
}
int main() {
    fastio;
    int a, b; 
    cin >> a >> b;
    long long sum = 1;
    for (int i = a; i <= b; i++) {
        sum *= t(i);
        sum %= 14579;
    }
    cout << sum;
    return 0;
}