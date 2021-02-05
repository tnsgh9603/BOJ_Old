#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n, i;
    long long total, ans, cnt = 0, arr[1001];
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> total;
    for (i = 0; i < n; i++) {
        if (arr[i] > 0 && arr[i] <= total) {
            cnt++;
        }
        else if (arr[i] > total) {
            if (arr[i] % total == 0) {
                cnt += arr[i] / total;
            }
            else {
                cnt += (arr[i] / total) + 1;
            }
        }
    }
    ans = total * cnt;
    cout << ans;
    return 0;
}