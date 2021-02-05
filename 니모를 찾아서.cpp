#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    string s;
    while (getline(cin, s) && s != "EOI") {
        regex r(".*?nemo.*?", regex::icase);
        cout << (regex_match(s, r) ? "Found" : "Missing") << '\n';
    }
    return 0;
}