#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int fingers[8];
int main() {
    fastio;
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        switch (s[i]) {
        case '1':
        case 'Q':
        case 'A':
        case 'Z':
            fingers[0]++;
            break;
        case '2':
        case 'W':
        case 'S':
        case 'X':
            fingers[1]++;
            break;
        case '3':
        case 'E':
        case 'D':
        case 'C':
            fingers[2]++;
            break;
        case '4':
        case 'R':
        case 'F':
        case 'V':
        case '5':
        case 'T':
        case 'G':
        case 'B':
            fingers[3]++;
            break;
        case '6':
        case 'Y':
        case 'H':
        case 'N':
        case '7':
        case 'U':
        case 'J':
        case 'M':
            fingers[4]++;
            break;
        case '8':
        case 'I':
        case 'K':
        case ',':
            fingers[5]++;
            break;
        case '9':
        case 'O':
        case 'L':
        case '.':
            fingers[6]++;
            break;
        default:
            fingers[7]++;
            break;
        }
    }
    for (int i = 0; i < 8; i++) {
        cout << fingers[i] << "\n";
    }
    return 0;
}