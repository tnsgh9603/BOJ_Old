#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int t;
    cin >> t;
    while (t--) {
        int n, d, ans = 0;
        cin >> n >> d;
        while (n--) {
            int vi, fi, ci;//���ּ� �ְ�ӵ�,���ᷮ,����Һ���
            cin >> vi >> fi >> ci;
            //�Ÿ��� �ӷ� * �� �� �ִ� �ð�
            if (vi * fi / ci >= d) {
                ans++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}