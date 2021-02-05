#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int N; 
    cin >> N;
    for (int i = 1; i <= N; i++) {
        string s;
        cin >> s;
        cout << "String #" << i << '\n';
        for (auto i : s) {
            cout << char((i - 'A' + 1) % 26 + 'A');
        }
        cout << '\n' << '\n';
    }
    return 0;
}
