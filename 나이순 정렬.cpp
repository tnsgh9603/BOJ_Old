#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool compare(const pair<int, string>& a, const pair<int, string>& b) {
    if (a.first < b.first)
        return true;
    // else if (a.first == b.first)
    //    return false;
    return false;
}
int main() {
    int input;
    cin >> input;
    vector <pair<int, string>> v(input);
    for (int i = 0; i < input; i++) {
        cin >> v[i].first >> v[i].second;
    }
    stable_sort(v.begin(), v.end(), compare);
    for (int i = 0; i < input; i++) {
        cout << v[i].first << ' ' << v[i].second << '\n';
    }
    return 0;
}