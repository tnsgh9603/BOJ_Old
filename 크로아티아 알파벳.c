#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main() {
	char sentence[101];
	gets(sentence);
	int length = strlen(sentence), count = 0;
	for (int i = 0; i < length; i++) {
		if (sentence[i] == 'c') {
			if (sentence[i + 1] == '-' || sentence[i + 1] == '=') {
				count++;
				i++;
			}
			else {
				count++;
			}
		}
		else if (sentence[i] == 'd') {
			if (sentence[i + 1] == 'z') {
				if (sentence[i + 2] == '=') {
					count++;
					i = i + 2;
				}
				else {
					count++;
				}
			}
			else if (sentence[i + 1] == '-') {
				count++;
				i++;
			}
			else {
				count++;
			}
		}
		else if (sentence[i] == 'l') {
			if (sentence[i + 1] == 'j') {
				count++;
				i++;
			}
			else {
				count++;
			}
		}
		else if (sentence[i] == 'n') {
			if (sentence[i+1] == 'j') {
				count++;
				i++;
			}
			else {
				count++;
			}
		}
		else if (sentence[i] == 's') {
			if (sentence[i + 1] == '=') {
				count++;
				i++;
			}
			else {
				count++;
			}
		}
		else if (sentence[i] == 'z') {
			if (sentence[i + 1] == '=') {
				count++;
				i++;
			}
			else {
				count++;
			}
		}
		else {
			count++;
		}
	}
	printf("%d", count);
	return 0;
}