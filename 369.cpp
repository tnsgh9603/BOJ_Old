#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int N, i = 1, cnt = 0;;
    cin >> N;
    do {
        int temp = i;
        while (temp > 0) {
            cnt = (temp % 10 == 3 || temp % 10 == 6 || temp % 10 == 9) ? cnt + 1 : cnt;
            temp = temp / 10;
        }
        i++;
    } while (i <= N);
    cout << cnt;
    return 0;
}