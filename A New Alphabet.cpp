#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
string arr[26] = { "@", "8", "(", "|)", "3", "#", "6", "[-]", "|", "_|", "|<", "1", "[]\\/[]", "[]\\[]", "0", "|D", "(,)", "|Z", "$", "']['", "|_|", "\\/", "\\/\\/", "}{", "`/", "2" };
int main() {
    fastio;
    string s;
    getline(cin, s);
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            cout << (arr[s[i] - 'A']);
        }
        else if (s[i] >= 'a' && s[i] <= 'z') {
            cout << (arr[s[i] - 'a']);
        }
        else {
            cout << s[i];
        }
    }
    return 0;
}