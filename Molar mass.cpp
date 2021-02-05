#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n; 
    cin >> n;
    vector<double> v{ 12.01, 1.008, 16.00, 14.01 };
    while (n--) {
        string s; cin >> s;
        regex r(R"(([A-Z])(\d*))");
        smatch m;
        double ans = 0;
        while (regex_search(s, m, r)) {
            int t = m[2].str().empty() ? 1 : stoi(m[2].str());
            for (auto i : m[1].str()) {
                ans += v[string("CHON").find(i)] * t;
            }
            s = m.suffix();
        }
        cout << fixed << setprecision(3) << ans << '\n';
    }
    return 0;
}