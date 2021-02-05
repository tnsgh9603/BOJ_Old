#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int sam, sys, ans, samf = 0, sysf = 0;
    cin >> sam >> sys;
    while (sam--) {
        int s, man;
        cin >> s >> man;
        if (s != man) {
            samf = 1;
        }
    }
    while (sys--) {
        int s, man;
        cin >> s >> man;
        if (s != man) {
            sysf = 1;
        }
    }
    if (samf == 0 && sysf) {
        cout << "Why Wrong!!!\n";
    }
    else if (samf == 0 && sysf == 0) {
        cout << "Accepted\n";
    }
    else {
        cout << "Wrong Answer\n";
    }
    return 0;
}