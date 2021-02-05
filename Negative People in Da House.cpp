#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int N; 
    cin >> N;
    while (N--) {
        int n, sum = 0, mn = 0; 
        cin >> n;
        while (n--) {
            int a, b; 
            cin >> a >> b;
            sum += a - b;
            mn = min(mn, sum);
        }
        cout << max(-mn, 0) << '\n';
    }
    return 0;
}