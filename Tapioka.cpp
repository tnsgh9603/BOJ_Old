#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    vector<string> words;
    while (1) {
        string word;
        cin >> word;
        if (word == "") {
            break;
        }
        if (word == "bubble" || word == "tapioka") {
            continue;
        }
        else {
            words.push_back(word);
        }
    }
    if (words.empty()) {
        cout << "nothing";
        return 0;
    }
    for (auto word : words) {
        cout << word << ' ';
    }
    return 0;
}