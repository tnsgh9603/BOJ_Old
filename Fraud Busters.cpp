#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
vector <string> vec;
int main() {
    fastio;
    string s, arr;
    int n;
    cin >> arr >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        int t = 1;
        for (int j = 0; j < 9; j++) {
            if (arr[j] == '*') {
                continue;
            }
            if (arr[j] != s[j]) {
                t = 0;
                break;
            }
        }
        if (t) {
            vec.push_back(s);
        }
    }
    cout << vec.size() << "\n";
    for (string a : vec) {
        cout << a << "\n";
    }
    return 0;
}