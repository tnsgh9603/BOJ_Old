#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int arr[100], a, i;
int main() {
    for (i = 0; i < 50; i++) {
        cin >> arr[i];
    }
    cin >> a;
    for (i = 0; i < 50; i++) {
        if (a == arr[i]) {
            if (i > 47) {
                printf("F");
            }
            else if (i > 44) {
                printf("C0");
            }
            else if (i > 34) {
                printf("C+");
            }
            else if (i > 29) {
                printf("B0");
            }
            else if (i > 14) {
                printf("B+");
            }
            else if (i > 4) {
                printf("A0");
            }
            else {
                printf("A+");
            }
            break;
        }
    }
    return 0;
}