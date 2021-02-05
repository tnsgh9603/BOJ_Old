#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
int main() {
    fastio;
    string s;
    cin >> s;
    vector<int> v;
    string temp;
    temp += s[0];
    for (int i = 1; i < s.size(); i++) {
        if (s[i] != ',' && i != s.size() - 1) {
            temp += s[i];
        }
        else {
            if (i == s.size() - 1) {
                temp += s[i];
            }
            v.push_back(stoi(temp));
            temp.clear();
        }
    }
    cout << accumulate(v.begin(), v.end(), 0);
    return 0;
}
