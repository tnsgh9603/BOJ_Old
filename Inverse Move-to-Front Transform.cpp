#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int t;
    cin >> t;
    while(t--){
        string s = "abcdefghijklmnopqrstuvwxyz", result = "";
        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int idx;
            cin >> idx;
            char letter = s[idx];
            result += letter;
            string temp1 = s.substr(0, idx), temp2 = s.substr(idx + 1, s.length());
            s = letter + temp1 + temp2;
        }
        cout << result << "\n";
    }
    return 0;
}

