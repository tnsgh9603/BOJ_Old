#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n;
    cin >> n;
    vector<int> v{ 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
    auto f = [&](int h, int m) {
        ostringstream out1, out2;
        out1 << setw(2) << setfill('0') << h;
        out2 << setw(2) << setfill('0') << m;
        string s1 = out1.str();
        string s2 = out2.str();
        string s = s1 + s2;
        int sum = 0;
        for (auto i : s) {
            sum += v[i - '0'];
        }
        return sum == n;
    };
    for (int h = 0; h < 24; h++) {
        for (int m = 0; m < 60; m++) {
            if (!f(h, m)) {
                continue;
            }
            cout << setw(2) << setfill('0') << h << ':';
            cout << setw(2) << setfill('0') << m << '\n';
            return 0;
        }
    }
    cout << "Impossible" << '\n';
    return 0;
}