#include <iostream>
using namespace std;
int dp[10001];
int main(){
    int N, M; 
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int v, c, k; 
        cin >> v >> c >> k;
        int t = 1;
        int temp;
        while (k > 0) {
            temp = min(k, t);
            for (int j = M; j >= v * temp; j--) {
                dp[j] = max(dp[j - v * temp] + c * temp, dp[j]);
            }
            t *= 2;
            k -= temp;
        }
    }
    int ans = 0;
    for (int i = 0; i <= M; i++) {
        ans = max(dp[i], ans);
    }
    cout << ans;
}
