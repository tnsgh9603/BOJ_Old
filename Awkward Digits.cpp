#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int to_int(string s, int n) {
    int ret = 0;
    for (auto i : s) {
        ret = n * ret + i - '0';
    }
    return ret;
}
int main() {
    fastio;
    string a, b; 
    cin >> a >> b;
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            for (int k = 1; k < 6; k++) {
                string t1 = a, t2 = b;
                t1[i] = (t1[i] - '0' + k / 3) % 2 + '0';
                t2[j] = (t2[j] - '0' + k / 2) % 3 + '0';
                if (to_int(t1, 2) == to_int(t2, 3)) {
                    cout << to_int(t1, 2) << '\n';
                    return 0;
                }
            }
        }
    }
    return 0;
}