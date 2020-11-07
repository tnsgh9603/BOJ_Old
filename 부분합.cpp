#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;
int arr[100001];
int main() {
    int N, S, input;
    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    int low = 0, high = 0;
    int sum = arr[0];
    int result = INT_MAX;
    while (low <= high && high < N){
        if (sum < S) {
            sum += arr[++high];
        }
        else if (sum == S) {
            result = min(result, (high - low + 1));
            sum += arr[++high];
        }
        else if (sum > S) {
            result = min(result, (high - low + 1));
            sum -= arr[low++];
        }
    }
    int ans = result == INT_MAX ? 0 : result;
    cout << ans;
    return 0;
}