#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n, sum = 0, Max = -1;
    cin >> n; 
    for (int i = 1; i <= n; i++) {
        int c;
        cin >> c;
        sum += c;
        Max = max(Max, c);
    }
    cout << sum - Max;
    return 0;
}
