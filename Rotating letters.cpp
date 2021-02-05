#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    string str;
    cin >> str;
    vector<char> v = { 'I', 'O', 'S', 'H', 'Z', 'X', 'N' };
    for (auto c : str) {
        if (auto it = find(v.begin(), v.end(), c); it == v.end()) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}
