#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n, i;
    cin >> n;
    while (n--) {
        string s; 
        cin >> s;
        for (i = s.size() - 2; i >= 0; i--) {
            if (s[i] < s[i + 1]) {
                break;
            }
        }
        cout << "The longest decreasing suffix of " << s << " is " << s.substr(i + 1, s.size()) << '\n';
    }
    return 0;
}