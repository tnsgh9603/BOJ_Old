#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    string color[10] = { "black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white" }, t;
    int mem[3];
    long long r = 0;
    for (int i = 0; i < 3; ++i) {
        cin >> t;
        for (int j = 0; j < 10; ++j) {
            if (color[j] == t) {
                mem[i] = j;
            }
        }
    }
    r = mem[0] * 10 + mem[1];
    for (int i = 0; i < mem[2]; ++i) {
        r *= 10;
    }
    cout << r;
    return 0;
}