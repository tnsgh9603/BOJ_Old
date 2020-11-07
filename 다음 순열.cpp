#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    vector <int> vec;
    int N, input;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> input;
        vec.push_back(input);
    }
    if (next_permutation(vec.begin(), vec.end())) {
        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i] << " ";
        }
    }
    else {
        cout << "-1";
    }
    return 0;
}