#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int t1, t2;
    string a, b; 
    cin >> a >> b;
    for (int i = 0; i < a.size(); i++) {
        if (b.find(a[i]) == -1) {
            continue;
        }
        t1 = i;
        t2 = b.find(a[i]);
        break;
    }
    for (int i = 0; i < b.size(); i++) {
        for (int j = 0; j < a.size(); j++) {
            if (i != t2 && j != t1) {
                cout << '.';
            }
            else if (i == t2) {
                cout << a[j];
            }
            else {
                cout << b[i];
            }
        }
        cout << '\n';
    }
    return 0;
}
