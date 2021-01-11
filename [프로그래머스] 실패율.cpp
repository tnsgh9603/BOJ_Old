#include <bits/stdc++.h>
using namespace std;
// arr1���� �ش� �ε�����ȣ�� ���������� ���� Ŭ�������� ���� ��� ��
// arr2���� �ش� �ε�����ȣ�� ���������� ������ ��� ��
double arr1[200001], arr2[200001];
vector<pair<int, double>>vec;
bool compare(const pair<int, double>& a, const pair<int, double>& b) {
	if (a.second > b.second) {
		return true;
	}
	else if (a.second == b.second) {
		if (a.first < b.first) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}
vector<int> solution(int N, vector<int> stages) {
	for (int i = 0; i < stages.size(); i++) {
		arr1[stages[i]]++;
		for (int j = 1; j <= stages[i]; j++) {
			arr2[j]++;
		}
	}
	for (int i = 1; i <= N; i++) {
		double rate;
		if (arr1[i] == 0) {
			rate = 0;
		}
		else {
			rate = (double)arr1[i] / arr2[i];
		}
		vec.push_back({ i ,rate });
	}
	vector<int> answer;
	sort(vec.begin(), vec.end(), compare);
	for (int i = 0; i < vec.size(); i++) {
		answer.push_back(vec[i].first);
	}
	return answer;
}