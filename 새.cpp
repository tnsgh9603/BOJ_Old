#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int N;
    cin >> N;
    int result = 1, bird = 1;
    while (1) {
        if (N - bird >= 0) {
            N -= bird;
        }
        else {
            bird = 1;
            N -= bird;
        }
        if (N == 0) {
            break;
        }
        result++;
        bird++;
    }
    cout << result;
    return 0;
}
