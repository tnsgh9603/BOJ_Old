#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main() {
    int test_number, number;
    char sentence[21] = { 0, };
    scanf("%d", &test_number);
    for (int i = 1; i <= test_number; i++) {
        scanf("%d", &number);
        scanf("%s", sentence);
        for (int k = 0; k < strlen(sentence);k++ ) {
            for (int j = 0; j < number; j++) {
                printf("%c", sentence[k]);
            }
            
        }
        printf("\n");
    }
    return 0;
}