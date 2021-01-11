#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    for (int i = 6; i <= 100; i++) {
        for (int j = 2; j < i; j++) {
            for (int k = j + 1; k < i; k++) {
                for (int l = k + 1; l < i; l++) {
                    if (i * i * i == j * j * j + k * k * k + l * l * l) {
                        cout << "Cube = " << i << ", Triple = (" << j << ',' << k << ',' << l << ")\n";
                    }
                }
            }
        }
    }
    return 0;
}