#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int sum, book;
    cin >> sum;
    for (int i = 0; i < 9; i++) {
        cin >> book;
        sum -= book;
    }
    cout << sum;
    return 0;
}