#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.second == b.second) 
        return (a.first < b.first);
    return (a.second < b.second);
}
int main() {
    int input;
    cin >> input;
    vector <pair<int, int>> v(input);
    for (int i = 0; i < input; i++) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end(), compare);
    for (int i = 0; i < input; i++) {
        cout << v[i].first << ' ' << v[i].second << '\n';
    }
    return 0;
}