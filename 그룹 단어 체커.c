#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main() {
	int number, length, count = 0, k = 2, answer = 0;
	char sentence[101];
	scanf("%d", &number);
	for (int i = 0; i < number; i++) {
		scanf("%s",sentence);
		length = strlen(sentence);
		for (int j = 0; j< length; j++) {
			if (sentence[j] != sentence[j + 1]){
				for (k = 2; k+j < length; k++) {
					if (sentence[j] == sentence[j + k]) {
						count++;
						k = 2;
						break;
					}
				}
			}
		}
		if (count == 0) {
			answer++;
		}
		count = 0;
	}
	printf("%d", answer);
	return 0;
}