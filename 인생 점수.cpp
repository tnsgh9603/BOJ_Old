#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    fastio;
    int n; cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {
        string s; getline(cin, s);
        int sum = 0;
        for (auto i : s) {
            if (i == ' ') continue;
            sum += i - 'A' + 1;
        }
        if (sum == 100) cout << "PERFECT LIFE" << '\n';
        else cout << sum << '\n';
    }
}