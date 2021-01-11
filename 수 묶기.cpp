#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> addition, subtraction;
int main() {
    int N, k, zero = 0, one = 0, ans = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> k;
        if (k == 1) {
            one++;
        }
        else if (k > 0) {
            addition.push_back(k);
        }
        else if (k < 0) {
            subtraction.push_back(k);
        }
        else {
            zero++;
        }
    }

    // 내림차순 정렬
    sort(addition.begin(), addition.end(), greater<int>());
    // 오름차순 정렬
    sort(subtraction.begin(), subtraction.end());

    // 개수를 맞춰주기 위해 1을 넣어줌
    if (addition.size() % 2 == 1) {
        addition.push_back(1);
    }
    // 얘도 마찬가지로 개수를 맞춰주기 위해 
    // minus에서는 zero가 있으면 0을 넣어주고 없으면 1을 넣어준다.
    if (subtraction.size() % 2 == 1) {
        subtraction.push_back(zero > 0 ? 0 : 1);
    }
    for (int i = 0; i < addition.size(); i += 2) {
        ans += addition[i] * addition[i + 1];
    }
    for (int i = 0; i < subtraction.size(); i += 2) {
        ans += subtraction[i] * subtraction[i + 1];
    }
    ans = ans + one;
    cout << ans;
    return 0;
}
