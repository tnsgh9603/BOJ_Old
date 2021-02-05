#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int N; 
    cin >> N;
    while (N--) {
        int n, sum = 0; 
        cin >> n;
        for (int i = 1; i < n; i++) {
            if (n % i == 0) {
                sum += i;
            }
        }
        cout << n << (n != sum ? n > sum ? " is a deficient" : " is an abundant" : " is a perfect") << " number.\n\n";
    }
    return 0;
}