#include <iostream>
#include <string>
using namespace std;

string sentence;
int main() {
	int P;
	cin >> P;
	cin.ignore();
	for (int k = 1; k <= P; k++) {
		getline(cin, sentence);
		for (int i = 0; i < sizeof(sentence); i++) {
			if (sentence[i] == 'A' && sentence[i + 1] == 'E') {
				sentence.replace(i, i + 1, "[AE]");
			}
			if (sentence[i] == 'a' && sentence[i + 1] == 'e') {
				sentence.replace(i, i + 1, "[]");
			}
			if (sentence[i] == 'O' && sentence[i + 1] == 'E') {
				sentence.replace(i, i + 1, "[OE]");
			}
			if (sentence[i] == 'o' && sentence[i + 1] == 'e') {
				sentence.replace(i, i + 1, "[oe]");
			}
			if (sentence[i] == 'c' && sentence[i + 1] == 't') {
				sentence.replace(i, i + 1, "[ct]");
			}
			if (sentence[i] == 'f' && sentence[i + 1] == 'f') {
				sentence.replace(i, i + 1, "[ff]");
			}
			if (sentence[i] == 'f' && sentence[i + 1] == 'f' && sentence[i + 2] == 'i') {
				sentence.replace(i, i + 2, "[ffi]");
			}
			if (sentence[i] == 'f' && sentence[i + 1] == 'f' && sentence[i + 2] == 'l') {
				sentence.replace(i, i + 2, "[ffl]");
			}
			if (sentence[i] == 's' && sentence[i + 1] == 's' && sentence[i + 2] == 'i') {
				sentence.replace(i, i + 2, "[longssi]");
			}
			if (sentence[i] == 's' && sentence[i + 1] == 'i') {
				sentence.replace(i, i + 1, "[longsi]");
			}
			if (sentence[i] == 's' && sentence[i + 1] == 'h') {
				sentence.replace(i, i + 1, "[longsh]");
			}
			if (sentence[i] == 's' && sentence[i + 1] == 'l') {
				sentence.replace(i, i + 1, "[longsl]");
			}
			if (sentence[i] == 's' && sentence[i + 1] == 's') {
				sentence.replace(i, i + 1, "[longss]");
			}
			if (sentence[i] == 's' && sentence[i + 1] == 't') {
				sentence.replace(i, i + 1, "[longst]");
			}
			
		}
	}

	return 0;
}