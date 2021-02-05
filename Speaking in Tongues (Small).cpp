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
        string t = "yhesocvxduiglbkrztnwjpfmaq";
        for (auto& i : s) {
            if (isalpha(i)) {
                i = t[i - 'a'];
            }
        }
        cout << "Case #" << i << ": " << s << '\n';
    }
    return 0;
}