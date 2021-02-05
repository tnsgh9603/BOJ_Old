#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    string a, b;
    while (cin >> a >> b && (a != "#" || b != "#")) {
        int n, t1 = 0, t2 = 0; 
        cin >> n;
        while (n--) {
            char c1, c2; 
            cin >> c1 >> c2;
            c1^ c2 ? t2++ : t1++;
        }
        cout << a << ' ' << t1 << ' ' << b << ' ' << t2 << '\n';
    }
    return 0;
}