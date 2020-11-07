#include <iostream>
#include <queue> // FIFO
#include <algorithm> // sort �Լ��� ����
using namespace std;

pair<int, int> jewelry[300000]; // ������ ���Կ� ��ġ�� ����
priority_queue<int> pq; 
int bag[300000]; // ������ �ִ� ���� ����

int main() {
    int n, k, j = 0;
    // n : ���� ���� , k : ���� ����
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        // ù ��° ��ҿ��� ������ ���Ը�, �� ��° ��ҿ��� ������ ��ġ�� �����Ѵ�.
        cin >> jewelry[i].first >> jewelry[i].second;
    }
    for (int i = 0; i < k; i++) {
        cin >> bag[i]; // ������ �ִ� ���� ���� 
    }

    // �������� ����
    sort(jewelry, jewelry + n);
    sort(bag, bag + k);

    long long sum = 0;  // ������ �ִ� ���� <= 300000 , ������ �ִ� ��ġ <= 1,000,000 �̹Ƿ� 
                        // int���� ������ �Ѿ �� �ֱ� ������ long long�� �ڷ������� ���� ����� �Ѵ�.
    for (int i = 0, j = 0; i < k; i++) {
        // ��� �����鿡 ����, ���濡 ���� �� �ִٸ� push
        // ���� ���԰� ���� �������� ����
        // ������ �ִ� ���Էδ� �ش� ������ ������ �� ������ ���� ���溸�� ���԰� ū ���� ���� ���� ������ �ٽ� �ҷ���
        while (j < n && jewelry[j].first <= bag[i]) {
            pq.push(jewelry[j].second);
            j++;
        }
        if (!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
    }
    cout << sum;
    return 0;
}