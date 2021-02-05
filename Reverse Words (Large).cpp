#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n; 
    cin >> n; 
    cin.ignore();
    for (int i = 1; i <= n; i++) {
        string s; 
        getline(cin, s);
        stringstream in(s);
        vector<string> v;
        while (in >> s) {
            v.push_back(s);
        }
        cout << "Case #" << i << ": ";
        for (int i = v.size() - 1; i >= 0; i--) {
            cout << v[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}