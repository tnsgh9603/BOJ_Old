#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
bitset<10001> visited;
int main() {
    fastio;
    int n, cnt = 0;
    cin >> n;
    while (!visited[n]) {
        cnt++, visited[n] = 1;
        int t = n / 10 % 100;
        n = t * t;
    }
    cout << cnt;
    return 0;
}