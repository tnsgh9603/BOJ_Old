#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n; 
    cin >> n;
    while (n--) {
        string s; 
        cin >> s;
        bitset<10> v;
        for (auto i : s) {
            v[i - '0'] = 1;
        }
        cout << v.count() << '\n';
    }
    return 0;
}
