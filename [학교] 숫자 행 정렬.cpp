#include <iostream>
#include <algorithm>
using namespace std;
int arr[1001][51] = { 0 };
int main() {
	int N, input;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int k = 0;
		while (1) {
			cin >> input;
			if (input == -1) {
				break;
			}
			else {
				arr[i][k] = input;
				k++;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int k = 1; i + k < N; k++) {
			if (arr[i][0] > arr[i + k][0]) {
				int arr2[1][1];
				arr[i] = arr[i + k];
				arr[i + k] = arr2;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		int a = vec[i].size();
		int k = 0;
		while (a--) {
			cout << vec[i][k];
			if (a != 0) {
				cout << " ";
			}
			k++;
		}
		cout << "\n";
	}
	return 0;
}
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> vec[1001];
int main() {
	int N, input;
	cin >> N;
	for (int i = 0; i < N; i++) {
		while (1) {
			cin >> input;
			if (input == -1) {
				break;
			}
			else {
				vec[i].push_back(input);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int k = 1; i + k < N; k++) {
			if (vec[i][0] > vec[i + k][0]) {
				vector <int> arr;
				arr = vec[i];
				vec[i] = vec[i + k];
				vec[i + k] = arr;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		int a = vec[i].size();
		int k = 0;
		while (a--) {
			cout << vec[i][k];
			if (a != 0) {
				cout << " ";
			}
			k++;
		}
		cout << "\n";
	}
	return 0;
}
*/