#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int a, b, c;
    cin >> a >> b >> c;
    if (a == 1 && !b && !c) {
        cout << "A";
    }
    else if (!a && b == 1 && c == 1) {
        cout << "A";
    }
    else if (!a && b == 1 && !c) {
        cout << "B";
    }
    else if (a == 1 && !b && c == 1) {
        cout << "B";
    }
    else if (!a && !b && c == 1) {
        cout << "C";
    }
    else if (a == 1 && b == 1 && !c) {
        cout << "C";
    }
    else {
        cout << "*";
    }
    return 0;
}