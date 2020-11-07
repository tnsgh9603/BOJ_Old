#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool compare(const pair<string, int>& a, const pair<string, int>& b) {
    if (a.second == b.second)
        return (a.first < b.first);
    return (a.second < b.second);
}
int main() {
    int input;
    cin >> input;
    vector <pair<string, int>> v(input);
    for (int i = 0; i < input; i++) {
        cin >> v[i].first;
        v[i].second = v[i].first.length();
    }
    sort(v.begin(), v.end(), compare);
    v.erase(unique(v.begin(), v.end()), v.end());
    
    for (int i = 0; i < v.size(); i++){
        cout << v[i].first << ' ' << '\n';
    }
    return 0;
}