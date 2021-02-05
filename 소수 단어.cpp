#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    string s; 
    cin >> s;
    int sum = 0;
    for (auto i : s) {
        if ('a' <= i && i <= 'z') {
            sum += i - 'a' + 1;
        }
        else {
            sum += i - 'A' + 27;
        }
    }
    bool flag = 1;
    for (int i = 2; i * i <= sum; i++) {
        if (sum % i == 0) {
            flag = 0;
        }
    }
    if (flag) {
        cout << "It is a prime word." << '\n';
    }
    else {
        cout << "It is not a prime word." << '\n';
    }
    return 0;
}
