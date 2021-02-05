#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int dp[101][101][101];
int main() {
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            for (int k = 1; k <= len3; k++) {
                // s1의 i번째 문자와  s2의 j번째 문자와 s3의 k번째 문자가 모두 같다면
                if (s1[i - 1] == s2[j - 1] && s2[j - 1] == s3[k - 1]) {
                    // 각각 그 전 번째 문자까지의 길이의 최대 길이에 +1 해줌
                    dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                }
                // 같지 않다면
                else {
                    // 지금까지 탐색한 것 중 가장 큰 값을 넣어줌
                    dp[i][j][k] = max(dp[i - 1][j][k], max(dp[i][j - 1][k], dp[i][j][k - 1]));
                }
            }
        }
    }
    cout << dp[len1][len2][len3];
    return 0;
}
/*
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int dp[101][101][101];
string s1, s2, s3;
int lcs(int idx1, int idx2, int idx3) {
    if (idx1 == s1.length() || idx2 == s2.length() || idx3 == s3.length()) {
        return 0;
    }
    int& result = dp[idx1][idx2][idx3];
    if (result != -1) {
        return result;
    }
    // 인덱스가 각각 하나씩 증가할 때와 모두 하나씩 증가할 때의 최댓값을 비교
    result = max(lcs(idx1 + 1, idx2, idx3), max(lcs(idx1, idx2 + 1, idx3), max(lcs(idx1, idx2, idx3 + 1), (s1[idx1] == s2[idx2] && s1[idx1] == s3[idx3] && s2[idx2] == s3[idx3]) + lcs(idx1 + 1, idx2 + 1, idx3 + 1))));
    return result;
}
int main() {
    cin >> s1 >> s2 >> s3;
    memset(dp, -1, sizeof(dp));
    cout << lcs(0, 0, 0) << "\n";
    return 0;
}
*/