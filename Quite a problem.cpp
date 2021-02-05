#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
int main() {
    fastio;
    string s;
    regex r(R"(.*problem.*)", regex::icase);
    while (getline(cin, s)) {
        regex_match(s, r) ? cout << "yes\n" : cout << "no\n";
    }
    return 0;
}
