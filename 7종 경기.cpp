#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int arr[200001];
int main() {
    fastio;
    int tc;
    cin >> tc;
    while (tc--) {
        int sum = 0;
        double p;
        cin >> p;
        sum += 9.23076 * pow(26.7 - p, 1.835);
        cin >> p; 
        sum += 1.84523 * pow(p - 75, 1.348);
        cin >> p;
        sum += 56.0211 * pow(p - 1.5, 1.05);
        cin >> p;
        sum += 4.99087 * pow(42.5 - p, 1.81);
        cin >> p;
        sum += 0.188807 * pow(p - 210, 1.41);
        cin >> p;
        sum += 15.9803 * pow(p - 3.8, 1.04);
        cin >> p;
        sum += 0.11193 * pow(254 - p, 1.88);
        cout << (int)sum << '\n';
    }
    return 0;
}