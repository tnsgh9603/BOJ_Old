#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int v[3][2];
int main() {
    fastio;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> v[i][j];
        }
    }
    for (int i = 0; i < 100; i++) {
        int a = i % 3, b = (i + 1) % 3;
        int t = (v[b][0] < v[a][1] + v[b][1]) * (v[a][1] + v[b][1] - v[b][0]);
        v[b][1] += v[a][1] - t;
        v[a][1] = t;
    }
    for (int i = 0; i < 3; i++) {
        cout << v[i][1] << '\n';
    }
    return 0;
}