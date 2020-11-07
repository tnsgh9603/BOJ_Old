#include <iostream>
#include <string>
#include <vector>
using namespace std;
int arr[21]; // Á¤´ä
int arr2[21];
bool is_correct(int size) {
	for (int i = 1; i <= size; i++) {
		if (arr[i] == arr2[i]) {
			if (i == size) {
				return true;
			}
		}
		else {
			return false;
		}
	}
}
int main() {
	string sentence;
	cin >> sentence;
	int size = sentence.size(), cnt = 0, cur_where = 1;
	for (int i = 0; i < sentence.size(); i++) {
		arr[i + 1] = sentence[i] - 'A';
	}
	while (1) {
		if (is_correct) {
			cout << cnt;
			return 0;
		}
	}
	return 0;
}