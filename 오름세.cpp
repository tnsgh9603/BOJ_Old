#include <iostream>
#include <vector>
using namespace std;
vector<int> vec;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            int num, pos;
            cin >> num;
            pos = lower_bound(vec.begin(), vec.end(), num) - vec.begin();
            if (pos == vec.size()) {
                vec.push_back(num);
            }
            else if (vec[pos] > num) {
                vec[pos] = num;
            }
        }
        cout << vec.size() << "\n";
        vec.clear();
    }
    return 0;
}