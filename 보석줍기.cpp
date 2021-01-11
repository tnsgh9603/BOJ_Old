#include <iostream>
using namespace std;
int N, M, arr[100001];
double mid;
int check() {
    double sum1 = 0, sum2 = 0, mini = 0;
    for (int i = 1; i < M; i++) {
        sum1 += arr[i] - mid;
    }
    for (int i = M; i <= N; i++) {
        sum1 += arr[i] - mid;
        if (sum2 < mini) {
            mini = sum2;
        }
        if (sum1 - mini >= 0) {
            return 1;
        }
        sum2 += arr[i - M + 1] - mid;
    }
    return 0;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    double low = 0, high = 2000;
    for (int i = 0; i < 100; ++i) {
        mid = (low + high) / 2;
        if (check()) {
            low = mid;
        }
        else {
            high = mid;
        }
    }
    cout << int(mid * 1000 + 1e-6);
    return 0;
}