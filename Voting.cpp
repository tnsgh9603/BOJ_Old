#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    string s;
    while (cin >> s && s != "#") {
        vector<int> v(4);
        for (auto i : s) {
            v[string("YNPA").find(i)]++;
        }
        if (v[3] >= 1. * s.size() / 2) {
            cout << "need quorum" << '\n';
        }
        else {
            cout << (v[0] ^ v[1] ? v[0] > v[1] ? "yes" : "no" : "tie") << '\n';
        }
    }
    return 0;
}