#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n; 
    cin >> n;
    cin.ignore();
    while (n--) {
        string s, t;
        getline(cin, s);
        stringstream in(s);
        in >> t;
        s = "god";
        while (in >> t) {
            s += t;
        }
        cout << s << '\n';
    }
    return 0;
}