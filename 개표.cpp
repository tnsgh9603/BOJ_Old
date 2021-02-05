#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n;
    string s;
    cin >> n >> s;
    int cnt = 0;
    for (auto i : s) {
        i == 'A' ? cnt++ : cnt--;
    }
    if (cnt > 0) {
        cout << 'A' << '\n';
    }
    else if (cnt < 0) {
        cout << 'B' << '\n';
    }
    else {
        cout << "Tie" << '\n';
    }
    return 0;
}
