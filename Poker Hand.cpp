#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int v[128];
int main() {
    fastio;
    for (int i = 0; i < 5; i++) {
        string s;
        cin >> s;
        v[s[0]]++;
    }
    cout << *max_element(v, v + 128) << '\n';
    return 0;
}