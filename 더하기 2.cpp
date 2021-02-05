#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    string s, temp;
    int sum = 0;
    while (cin >> temp) {
        s += temp;
    }
    temp.clear();
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != ',') {
            temp += s[i];
        }
        if (s[i] == ',' || i == s.size() - 1) { 
            sum += stoi(temp); 
            temp.clear(); 
        }
    }
    cout << sum;
    return 0;
}