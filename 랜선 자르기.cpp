#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<long long> vec;

long long binarySearch(long long start, long long end, int target) {
    long long mid = (start + end) / 2;
    //이진 탐색 시행
    while (start <= end) {
        long long sum = 0;
        mid = (start + end) / 2;
        for (int i = 0; i < vec.size(); i++) {
            sum += vec[i] / mid;
        }
        //sum이 target보다 작으면 왼쪽 절반 범위 탐색
        if (target > sum) {
            end = mid - 1;
        }
        //sum이 target보다 크거나 같으면 오른쪽 절반 범위 탐색
        else if (sum >= target) {
            start = mid + 1;
        }
    }
    return end;
}

int main() {
    int K, N; // K : 이미 가지고 있는 랜선 수, N : 필요한 랜선 수
    long long temp;
    cin >> K >> N;
    for (int i = 0; i < K; i++) {
        cin >> temp;
        vec.push_back(temp);
    }
    //이진탐색을 위한 오름차순 정렬
    sort(vec.begin(), vec.end());
    // 1, vec의 마지막 원소의 값, 필요한 랜선 수
    // start, end , target
    cout << binarySearch(1, vec[vec.size() - 1], N);
    return 0;
}