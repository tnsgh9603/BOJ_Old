#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int N;
    cin >> N;
    while (N--) {
        string s;
        cin >> s;
        string s2 = s; reverse(s2.begin(), s2.end());
        string s3 = to_string(stoi(s) + stoi(s2));
        bool ispal = 1;
        for (int i = 0; i <= s3.size() / 2; i++) {
            if (s3[i] != s3[s3.size() - 1 - i]) {
                cout << "NO\n";
                ispal = 0;
                break;
            }
        }
        if (ispal) {
            cout << "YES\n";
        }
    }
    return 0;
}
