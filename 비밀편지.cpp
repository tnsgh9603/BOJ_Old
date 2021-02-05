#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
map<string, char> M = { { "000000", 'A' }, { "001111", 'B' }, { "010011", 'C' }, { "011100", 'D' }, { "100110", 'E' }, { "101001", 'F' }, { "110101", 'G' }, { "111010", 'H' } };
vector<string> v{ "000000", "001111", "010011", "011100", "100110", "101001", "110101", "111010" };
int main() {
    fastio;
    int n; 
    string s, ans;
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        string t = s.substr(6 * i, 6);
        if (M.count(t)) {
            ans += M[t];
        }
        else {
            bool flag = 0;
            for (int j = 0; j < v.size(); j++) {
                int cnt = 0;
                for (int k = 0; k < v[j].size(); k++) {
                    if (t[k] != v[j][k]) {
                        cnt += 1;
                    }
                }
                if (cnt == 1) { 
                    flag = 1;
                    ans += 'A' + j;
                }
            }
            if (!flag) {
                cout << i + 1 << '\n';
                return 0;
            }
        }
    }
    cout << ans;
    return 0;
}
