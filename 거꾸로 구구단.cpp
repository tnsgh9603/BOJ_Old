#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    vector<int> v;
    for (int i = 1; i <= m; i++) {
        int temp = i * n;
        string s = to_string(temp);
        reverse(s.begin(), s.end());
        v.push_back(stoi(s));
    }
    cout << *max_element(v.begin(), v.end());
    return 0;
}