#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    string s;
    while (1) {
        getline(cin, s);
        if (s == "I quacked the code!") {
            return 0;
        }
        else if (s.back() == '?') {
            cout << "Quack!" << endl;
        }
        else if (s.back() == '.') {
            cout << "*Nod*" << endl;
        }
    }
    return 0;
}