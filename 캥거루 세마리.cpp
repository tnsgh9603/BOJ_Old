#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int A, B, C;
    cin >> A >> B >> C;
    int sum = B - A > C - B ? B - A - 1 : C - B - 1;
    cout << sum;
    return 0;
}