#include <iostream>
#include <cstring>
#include <stdlib.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	char* sentence = (char*)malloc(sizeof(char) * 1000001);
	int alphabet[26] = { 0, }, max = 0, count = 0, order = 0;
	cin >> sentence;
	int a = strlen(sentence);
	for (int i = 0; i < a; i++) {
		if ('a' <= sentence[i] && 'z' >= sentence[i]) {
			sentence[i] = sentence[i] - 32; //�Է� ���� ��� �빮�ڷ� �ٲپ �迭�� ����
		}
		alphabet[sentence[i] - 'A']++;
	}
	for (int i = 0; i < 26; i++) {
		if (alphabet[i] > max) {
			max = alphabet[i];
		}
	}
	for (int i = 0; i < 26; i++) {
		if (max == alphabet[i]) {
			count++;
			order = i;
		}
	}
	if (count > 1) {
		cout << "?";
	}
	else {
		cout << (char)(order + 'A');
	}
	return 0;
}