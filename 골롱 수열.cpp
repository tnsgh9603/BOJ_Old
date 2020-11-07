#include <iostream>
using namespace std;
int arr[1000000]; // 크기 백만이면 충분함
int main() {
    int n, i;
    cin >> n;
    if (n == 1) {
        cout << "1";
        return 0;
    }
    arr[1] = 1;
    int sum = arr[1];
    for (i = 2; i <= n; i++) {
        // 골롱 수열 점화식 
        arr[i] = 1 + arr[i - arr[arr[i - 1]]];
        sum += arr[i];
        // sum에는 계속해서 골롱 수열의 f(i)값이 담기고 있고 결국 sum이 n을 넘으면
        // 그때 i값이 n일때 f(n)의 값이 된다.
        if (sum >= n) {
            break;
        }
    }
    cout << i;
    return 0;
}