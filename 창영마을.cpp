#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int a[3] = { 1,0,0 };
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        switch (s[i]) {
        case 'A':
            swap(a[0], a[1]);
            break;
        case 'B':
            swap(a[1], a[2]);
            break;
        case 'C':
            swap(a[0], a[2]);
            break;
        }
    }
    for (int i = 0; i < 3; i++) {
        if (a[i] == 1) {
            cout << i + 1 << '\n';
            break;
        }
    }
    return 0;
}