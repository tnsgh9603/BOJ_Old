#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int num1=0, num2=0, i, n;
    cin >> n;
    for (i = 0; i < n; i++) {
        int test1 = 0, test2 = 0;
        cin >> test1 >> test2;
        if (test1 == test2) {
            continue;
        }
        else if (test1 > test2) {
            num1++;
        }
        else if (test1 < test2) {
            num2++;
        }
    }
    cout << num1 << " " << num2 << "\n";
    return 0;
}
