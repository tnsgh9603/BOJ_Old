#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int x, y; 
    cin >> x >> y;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            if ((i + j) % 2 == 0) {
                cout << "*";
            }
            else {
                cout << ".";
            }
        }
        cout << '\n';
    }
    return 0;
}