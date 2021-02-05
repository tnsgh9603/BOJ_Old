#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
const int INF = int(1e9);
int main() {
    fastio;
    int n; 
    cin >> n;
    while (n--) {
        int a, b, cnt = 0; 
        cin >> a >> b;
        while (a < b) {
            cnt++;
            a <<= 1;
        }
        cout << cnt << '\n';
    }
    return 0;
}