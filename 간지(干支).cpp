#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n;
    cin >> n; 
    n += 56;
    cout << "ABCDEFGHIJKL"[n % 60 % 12] << "0123456789"[n % 60 % 10];
    return 0;
}
