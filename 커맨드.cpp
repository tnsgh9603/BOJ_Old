#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
char S[10101];
int t;
int main() {
    fastio;
    cin >> t;
    for (; t--; ) {
        cin >> S;
        cout << (!S[7] && S[0] == S[1] && S[0] == S[4] && S[2] == S[3] && S[2] == S[5] && S[2] == S[6] && S[0] != S[2]) << "\n";
    }
    return 0;
}