#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
void printResult(int y, int a, int b, char c) {
    if (b >= 10)
        printf("%d%c", b, c);
    else
        printf("0%d%c", b, c);

    if (a >= 10)
        printf("%d%c", a, c);
    else
        printf("0%d%c", a, c);

    if (y >= 1000)
        printf("%d", y);
    else if (y >= 100)
        printf("0%d", y);
    else if (y >= 10)
        printf("00%d", y);
    else
        printf("000%d", y);
}
int main() {
    int n, y, m, d, len, p;
    char dates[12];
    bool chk;
    scanf("%d", &n);
    while (n--) {
        scanf(" %s", dates);
        len = strlen(dates);
        y = 0; m = 0; d = 0;
        chk = false;

        for (int i = 0; i < len; i++) {
            if (dates[i] == '.') {
                chk = true;
                break;
            }
        }

        if (chk) {
            for (int i = len - 1, j = 1; i >= 0; i--, j *= 10) {
                if (dates[i] == '.') {
                    p = i;
                    break;
                }
                y += (dates[i] - '0') * j;
            }
            for (int i = p - 1, j = 1; i >= 0; i--, j *= 10) {
                if (dates[i] == '.') {
                    p = i;
                    break;
                }
                m += (dates[i] - '0') * j;
            }
            for (int i = p - 1, j = 1; i >= 0; i--, j *= 10)
                d += (dates[i] - '0') * j;
        }
        else {
            for (int i = len - 1, j = 1; i >= 0; i--, j *= 10) {
                if (dates[i] == '/') {
                    p = i;
                    break;
                }
                y += (dates[i] - '0') * j;
            }
            for (int i = p - 1, j = 1; i >= 0; i--, j *= 10) {
                if (dates[i] == '/') {
                    p = i;
                    break;
                }
                d += (dates[i] - '0') * j;
            }
            for (int i = p - 1, j = 1; i >= 0; i--, j *= 10)
                m += (dates[i] - '0') * j;
        }

        printResult(y, m, d, '.');
        printf(" ");
        printResult(y, d, m, '/');
        printf("\n");
    }
    return 0;
}