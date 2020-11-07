#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main() {
    char sentence[1000001];
    int length, count = 0;
    gets(sentence);
    length = strlen(sentence);
    for (int i = 0; i < length; i++) {
        if (sentence[i] != ' ') {
            if ((sentence[i + 1] < 'a' || sentence[i + 1] > 'z') && (sentence[i + 1] < 'A' || sentence[i + 1] > 'Z')){
                count++;
            }
        }
    }
    printf("%d", count);
    return 0;
}