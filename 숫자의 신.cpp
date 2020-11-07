#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // sort �Լ� ���
using namespace std;
vector<string> ans;

// ���ڿ� a�� b�� �ٿ����� a�� �տ� b�� �ڿ� �پ������� �� ũ�� true ����
// a�� �ڿ� b�� �տ� �پ������� �� ũ�� false ����
// �� ���ڿ��� �� ū ������ ����
bool cmp(string a, string b) {
	return a + b > b + a;
}

int main() {
	int N, K;
	cin >> K >> N;
	string str = ""; // ����ִ� string ����
	string tmp;
	for (int i = 1; i <= K; i++) { 
		cin >> tmp;
		// str ���� tmp�� ���̰� ��ų� (���̰� �� ��ٴ� ���� �ڸ����� ���ٴ� ���̹Ƿ� �ʿ������� �� ũ��) 
		// str�� tmp�� ���̰� ������ tmp�� str���� Ŭ �� str�� tmp�� �ִ´�.
		if (str.size() < tmp.size() || (str.size() == tmp.size() && str < tmp)) {
			str = tmp; //str�� ū ���� �ٲ��ش�.
		}
		ans.push_back(tmp);
	}
	// �׷� ���� str�� ���ݱ��� �Է¹��� ���� ���� ū ���� ���ִ�.
	// �� �������� ��� ���� �� ������ ������ ����ؾ��Ѵ�.
	// �� ���� ��� ���� ����������� ���� �� ����Ѵٸ� ���� ū ���� ��� push���ش�.
	for (int i = 1; i <= N - K; i++) {
		ans.push_back(str);
	}
	
	// ����
	sort(ans.begin(), ans.end(), cmp);
	
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i];
	}
}