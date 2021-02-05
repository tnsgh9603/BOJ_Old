#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int N;
string q = "ACAGCGTAATCGGAGT";
char sol(char a, char b) {
    int idx = (a == 'A' ? 0 : a == 'G' ? 1 : a == 'C' ? 2 : 3), idx2 = (b == 'A' ? 0 : b == 'G' ? 1 : b == 'C' ? 2 : 3);
    return q[idx * 4 + idx2];
}
int main() {
    fastio;
    string s;
    cin >> N >> s;
    for (int i = s.length() - 2; i >= 0; i--) {
        s[i] = sol(s[i], s[i + 1]);
    }
    cout << s[0];
    return 0;
}
