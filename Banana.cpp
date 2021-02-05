#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
map<string, string> mp;
int main() {
    fastio;
    int N, T;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        string pep, equal, mpmi;
        cin >> pep >> equal >> mpmi;
        mp[pep] = mpmi;
    }
    cin >> T;
    for (int i = 1; i <= T; i++) {
        int K;
        cin >> K;
        string str;
        for (int j = 1; j <= K; j++) {
            cin >> str;
            cout << mp[str] << " ";
        }
        cout << "\n";
    }
    return 0;
}