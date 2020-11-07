#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main() {
	char sentence[101] = { 0, };
	int alphabet[26] = { 0, };
	for (int i = 0; i < 26; i++) {
		alphabet[i] = -1;
	}
	scanf("%s", sentence);
	int a;
	for (int order = 0; order <= strlen(sentence); order++) {
		a = sentence[order] - 'a';
		if (alphabet[a] == -1) {
			alphabet[a] = order;
		}
	}
	for (int i= 0; i < 26; i++) {
		printf("%d ", alphabet[i]);
	}
	return 0;
}
