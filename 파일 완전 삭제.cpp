#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n; 
    cin >> n;
    string a, b;
    cin >> a >> b;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i] ^ n & 1) {
            cout << "Deletion failed" << '\n';
            return 0;
        }
    }
    cout << "Deletion succeeded" << '\n';
    return 0;
}