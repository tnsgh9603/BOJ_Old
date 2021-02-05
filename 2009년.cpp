#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int D, M;
    cin >> D >> M;
    int month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    string arr[7] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
    int cnt = 0;
    for (int i = 0; i < M - 1; i++) {
        cnt += month[i];
    }
    cnt += D;
    cout << arr[(cnt + 2) % 7] << '\n';
    return 0;
}
