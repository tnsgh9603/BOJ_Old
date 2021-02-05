#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
vector<string> foo{ "Mon", "Tue", "Wed", "Thu", "Fri" };
int main() {
    int n, m;
    cin >> n >> m ;
    for (int i = 0; i < m; i++) {
        char z[8];
        int x;
        scanf("%s%d", z, &x);
        int s = x + 24 * (find(foo.begin(), foo.end(), z) - foo.begin());
        scanf("%s%d", z, &x);
        int e = x + 24 * (find(foo.begin(), foo.end(), z) - foo.begin());
        n -= e - s;
    }
    if (n <= 0) {
        cout << 0;
    }
    else if (n <= 48) {
        cout << n;
    }
    else {
        cout << -1;
    }
    return 0;
}