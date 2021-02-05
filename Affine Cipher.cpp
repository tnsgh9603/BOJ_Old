#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int N;
    cin >> N;
    while (N--) {
        int a, b;
        string s; 
        cin >> a >> b >> s;
        for (auto i : s) {
            cout << char((a * (i - 'A') + b) % 26 + 'A');
        }
        cout << '\n';
    }
    return 0;
}