#include <iostream>
using namespace std;
#include <algorithm>

long long INF = 2147483647;
int n;
long long a[20001], b[20001], c[20001];

long long sol(long long mid) {
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        if (mid >= a[i]) {
            ans += (min(mid, c[i]) - a[i]) / b[i] + 1;
        }
    }
    return ans;
}

int main() {
    long long low = 0, high = INF;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> c[i] >> b[i];
    }
    while (low < high) {
        long long mid = (low + high) / 2;
        if (sol(mid) % 2) {
            high = mid; 
        }
        else {
            low = mid + 1;
        }
    }

    if (low == INF) {
        cout << "NOTHING";
    }
    else {
        cout << low << " " << sol(low) - sol(low - 1) << "\n";
    }
    return 0;
}