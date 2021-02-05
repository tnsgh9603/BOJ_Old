#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int N;
    cin >> N;
    while (N--) {
        vector<int> v(5), w(4);
        for (int i = 0; i < 5; i++) {
            cin >> v[i];
            v[i] *= 16;
            v[i] /= "88419"[i] - '0';
        }
        for (int i = 0; i < 4; i++) {
            cin >> w[i];
            w[i] /= vector<int>{1, 30, 25, 10}[i];
        }
        cout << min(*min_element(v.begin(), v.end()), accumulate(w.begin(), w.end(), 0)) << '\n';
    }
    return 0;
}
