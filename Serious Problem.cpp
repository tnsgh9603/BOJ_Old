#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n; 
    cin >> n;
    string s; 
    cin >> s;
    int a = 0, b = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '2') {
            a++;
        }
        else {
            b++;
        }
    }
    if (a > b) {
        cout << 2;
    }
    else if (a < b) {
        cout << "e";
    }
    else {
        cout << "yee";
    }
    return 0;
}