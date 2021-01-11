#include <cmath>
#include <iostream>
using namespace std;

int main() {
    string s;
    while (1) {
        cin >> s;
        int sum = 0, len = s.length() - 1;
        if (s == "#") return 0;
        for (int i = len; i >= 0; i--) {
            int num;
            switch (s[i]) {
            case '-':
                num = 0;
                break;
            case '\\':
                num = 1;
                break;
            case '(':
                num = 2;
                break;
            case '@':
                num = 3;
                break;
            case '?':
                num = 4;
                break;
            case '>':
                num = 5;
                break;
            case '&':
                num = 6;
                break;
            case '%':
                num = 7;
                break;
            case '/':
                num = -1;
                break;
            }
            sum += pow(8, len - i) * num;
        }
        cout << sum << "\n";
    }
}