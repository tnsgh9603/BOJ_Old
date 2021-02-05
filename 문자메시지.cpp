#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int a, b, sum = 0;
    cin >> a >> b; 
    cin.ignore();
    string s; 
    getline(cin, s); 
    s = ' ' + s;
    string t1 = "11122233344455566667778888", t2 = "12312312312312312341231234";
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == ' ') {
            sum += a;
        }
        else {
            sum += (t2[s[i] - 'A'] - '0') * a;
            if (s[i - 1] != ' ' && t1[s[i] - 'A'] == t1[s[i - 1] - 'A']) {
                sum += b;
            }
        }
    }
    cout << sum;
    return 0;
}
