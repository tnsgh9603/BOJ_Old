#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    vector<int> v;
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        int a;
        cin >> a;
        v.push_back(a);
        sum += a;
    }
    sort(v.begin(), v.end());
    cout << sum / 5 << '\n' << v[2];
    return 0;
}
