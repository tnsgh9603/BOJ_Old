#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    fastio;
    int n; cin >> n;
    while (n--) {
        string s; int t; cin >> s >> t;
        cout << s << ' ';
        if (t < 60) cout << 'F';
        else if (t < 67) cout << 'D';
        else if (t < 70) cout << "D+";
        else if (t < 77) cout << 'C';
        else if (t < 80) cout << "C+";
        else if (t < 87) cout << 'B';
        else if (t < 90) cout << "B+";
        else if (t < 97) cout << 'A';
        else cout << "A+";
        cout << '\n';
    }
}