#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int N;
    cin >> N;
    while (N--) {
        string s;
        int n;
        cin >> s >> n;
        vector<int> v(26);
        for (auto i : s) {
            v[i - 'A']++;
        }
        while (n--) {
            string t; 
            cin >> t;
            vector<int> w(26);
            for (auto i : t) {
                w[i - 'A']++;
            }
            for (int i = 0; i < 26; i++) {
                if (v[i] < w[i]) {
                    cout << "NO" << '\n';
                    goto Flag;
                }
            }
            cout << "YES" << '\n';
        Flag:;
        }
    }
    return 0;
}