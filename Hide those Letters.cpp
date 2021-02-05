#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int cnt = 0; 
    char c1, c2;
    while (cin >> c1 >> c2 && c1 != '#') {
        int n; 
        cin >> n;
        cin.ignore();
        cout << "Case " << ++cnt << '\n';
        while (n--) {
            string s;
            getline(cin, s);
            for (auto& i : s) {
                if (tolower(i) == c1 || tolower(i) == c2) {
                    i = '_';
                }
            }
            cout << s << '\n';
        }
        cout << '\n';
    }
    return 0;
}