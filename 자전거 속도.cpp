#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    int i = 1;
    while (1) {
        double diameter, rotation, sec;
        cin >> diameter >> rotation >> sec;
        if (!rotation) {
            break;
        }
        double temp = diameter * rotation * 3.1415927 / 5280 / 12;
        double res = temp / sec * 3600;
        cout <<fixed << setprecision(2) << "Trip #" << i++ << ": " << temp << ' ' << res << '\n';
    }
    return 0;
}