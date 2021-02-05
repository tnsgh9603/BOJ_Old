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
        bitset<26> v;
        for (auto i : s) {
            v[i - 'A'] = 1;
        }
        int sum = 0;
        for (int i = 0; i < 26; i++) {
            if (v[i]) {
                continue;
            }
            sum += i + 'A';
        }
        cout << sum << '\n';
    }
    return 0;
}
