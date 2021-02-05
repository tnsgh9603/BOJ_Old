#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    bitset<10000001> v;
    int n;
    cin >> n;
    while (n--) {
        int t; 
        cin >> t;
        if (v[t]) {
            cout << t << '\n';
            return 0;
        }
        v[t] = 1;
    }
    return 0;
}