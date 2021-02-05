#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    int n, cnt = 0;
    cin >> n;
    string a, b; 
    cin >> a >> b;
    for (int i = 0; i < n; i++) {
        if (a[i] == 'C' && b[i] == 'C') {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}