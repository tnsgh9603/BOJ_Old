#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n; 
    cin >> n;
    while (n--) {
        string s, a; 
        int t;
        cin >> s >> t; a = s;
        for (int i = 0; i < t; i++) {
            s.insert(s.begin(), s.back());
            s.pop_back();
        }
        cout << "Shifting " << a << " by " << t << " positions gives us: " << s << '\n';
    }
    return 0;
}