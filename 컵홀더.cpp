#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n; 
    string s;
    cin >> n >> s;
    int a = count(s.begin(), s.end(), 'S'), b = 0;
    for (int i = 1; i <= s.size(); i++) {
        if (s[i] == 'L' && s[i - 1] == 'L') {
            b++;
            i++;
        }
    }
    cout << a + b + bool(b) << '\n';
    return 0;
}
