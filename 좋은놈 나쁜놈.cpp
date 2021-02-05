#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    fastio;
    int n; cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {
        string s; getline(cin, s);
        int cnt = 0;
        for (auto i : s) {
            if (tolower(i) == 'g') cnt++;
            if (tolower(i) == 'b') cnt--;
        }
        cout << s << " is " << (cnt ? cnt > 0 ? "GOOD" : "A BADDY" : "NEUTRAL") << '\n';
    }
}