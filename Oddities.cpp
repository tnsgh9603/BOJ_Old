#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int N; 
    cin >> N;
    while (N--) {
        int n; 
        cin >> n;
        cout << n << " is " << (abs(n) & 1 ? "odd" : "even") << '\n';
    }
    return 0;
}