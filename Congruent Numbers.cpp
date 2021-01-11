#include<bits/stdc++.h>
using namespace std;
int main() {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << ((a * c) % (2 * b * d) == 0);
    return 0;
}