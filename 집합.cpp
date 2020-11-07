#include <iostream>
#include <string>
using namespace std;

int M, num, BIT;
string input;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M;
    while (M--) {
        input.clear();
        cin >> input;
        if (input == "add") {
            cin >> num;
            BIT |= (1 << num);
        }
        else if (input == "remove") {
            cin >> num;
            BIT &= ~(1 << num);
        }
        else if (input == "check") {
            cin >> num;
            if (BIT & (1 << num)) {
                cout << 1 << '\n';
            }
            else {
                cout << 0 << '\n';
            }
        }
        else if (input == "toggle") {
            cin >> num;
            BIT ^= (1 << num);
        }
        else if (input == "all") {
            BIT = (1 << 21) - 1;
        }
        else if (input == "empty") {
            BIT = 0;
        }
    }
    return 0;
}
/*
#include <iostream>
#include <string>
#include <memory.h>
using namespace std;
bool arr[21];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M, num;
    string sentence;
    cin >> M;
    for (int i = 1; i <= M; i++) {
        cin >> sentence;
        if (sentence == "add") {
            cin >> num;
            arr[num] = true;
        }
        else if (sentence == "remove") {
            cin >> num;
            arr[num] = false;
        }
        else if (sentence == "check") {
            cin >> num;
            if (arr[num]) {
                cout << "1\n";
            }
            else {
                cout << "0\n";
            }
        }
        else if (sentence == "toggle") {
            cin >> num;
            if (arr[num]) {
                arr[num] = false;
            }
            else {
                arr[num] = true;
            }
        }
        else if (sentence == "all") {
            memset(arr, true, sizeof(arr));
        }
        else if (sentence == "empty") {
            memset(arr, false, sizeof(arr));
        }
    }
    return 0;
}
*/