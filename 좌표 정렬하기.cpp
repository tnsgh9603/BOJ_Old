#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int input;
    cin >> input;
    vector <pair<int, int>> v(input); 
    for (int i = 0; i < input; i++) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < input; i++) {
        cout << v[i].first << ' ' << v[i].second << '\n';
    }
    return 0;
}