#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int v[3][2];
int main() {
    fastio;
    int n, k;
    cin >> n >> k;
    while (n--) {
        int a, b; 
        cin >> a >> b;
        v[--b >> 1][a]++;
    }
    int cnt = 0;
    for (auto i : vector<int>{
       v[0][0] + v[0][1],
       v[1][0], v[1][1],
       v[2][0], v[2][1]
        }) {
        cnt += i / k + bool(i % k);
    }
    cout << cnt;
    return 0;
}