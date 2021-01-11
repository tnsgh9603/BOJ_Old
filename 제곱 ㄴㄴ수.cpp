#include <iostream>
using namespace std;
long long numbers[1000001];
long long prinum[10001];
typedef long long ll;
int main() {
    ll max, min, num, prinum_num = 0, cnt = 0, x;
    cin >> min >> max;
    for (ll i = 2; i * i <= max; i++) {
        x = min / (i * i);
        if (min % (i * i) != 0) {
            x++;
        }
        while (x * (i * i) <= max) {
            numbers[x * (i * i) - min]++;
            x++;
        }
    }
    for (int i = 0; i <= max - min; i++) {
        if (!numbers[i]) {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}