#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
string v[5][5]{
   "***", "***", "***", "***", "***",
   "*.*", "*.*", "*..", "*.*", "*..",
   "***", "***", "*..", "*.*", "***",
   "*.*", "*.*", "*..", "*.*", "*..",
   "*.*", "***", "***", "***", "***"
};
int main() {
    fastio;
    int n;
    string s; 
    cin >> n >> s;
    for (int i = 0; i < 5; i++) {
        for (auto j : s) {
            cout << v[i][j - 'A'];
        }
        cout << '\n';
    }
    return 0;
}