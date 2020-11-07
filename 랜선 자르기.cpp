#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<long long> vec;

long long binarySearch(long long start, long long end, int target) {
    long long mid = (start + end) / 2;
    //���� Ž�� ����
    while (start <= end) {
        long long sum = 0;
        mid = (start + end) / 2;
        for (int i = 0; i < vec.size(); i++) {
            sum += vec[i] / mid;
        }
        //sum�� target���� ������ ���� ���� ���� Ž��
        if (target > sum) {
            end = mid - 1;
        }
        //sum�� target���� ũ�ų� ������ ������ ���� ���� Ž��
        else if (sum >= target) {
            start = mid + 1;
        }
    }
    return end;
}

int main() {
    int K, N; // K : �̹� ������ �ִ� ���� ��, N : �ʿ��� ���� ��
    long long temp;
    cin >> K >> N;
    for (int i = 0; i < K; i++) {
        cin >> temp;
        vec.push_back(temp);
    }
    //����Ž���� ���� �������� ����
    sort(vec.begin(), vec.end());
    // 1, vec�� ������ ������ ��, �ʿ��� ���� ��
    // start, end , target
    cout << binarySearch(1, vec[vec.size() - 1], N);
    return 0;
}