#include <iostream>
#include <vector>
#include <cmath> // ceil �Լ� ����Ϸ���
#include <algorithm>
#include <limits.h> // INT_MAX ǥ���� ����
using namespace std;

int num[100001]; 
vector<int> min_tree, max_tree; 
void init(int node, int start, int end) {
    if (start == end) { // start�� end�� ������ �� �Ʒ� ���(���� ���)���� �������ٴ� ��
        min_tree[node] = max_tree[node] = num[start];
        return;
    }
    int mid = (start + end) / 2;
    init(node * 2, start, mid);
    init(node * 2 + 1, mid + 1, end);
    min_tree[node] = min(min_tree[node * 2], min_tree[node * 2 + 1]);
    max_tree[node] = max(max_tree[node * 2], max_tree[node * 2 + 1]);
    return;
}

pair<int, int> find(int node, int a, int b, int left, int right) {
    if (left > b || right < a) { // �������� �������
        return make_pair(INT_MAX, 0);
    }
    if (a <= left && right <= b) { // ���ϴ� ������ ����� ������ ������ ��
        return make_pair(min_tree[node], max_tree[node]);
    }
    
    //���߰��ϰ� ��ĥ��
    int mid = (left + right) / 2;
    pair<int, int> l, r;
    l = find(node * 2, a, b, left, mid);
    r = find(node * 2 + 1, a, b, mid + 1, right);
    return make_pair(min(l.first, r.first), max(l.second, r.second));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    int size = 1 << int(ceil(log2(N)) + 1); // ceil�� �ø� �Լ� -> double������ ��ȯ�ϹǷ� int�� ����ȯ����
    min_tree.resize(size);
    max_tree.resize(size);

    for (int i = 1; i <= N; i++) {
        cin >> num[i];
    }
    init(1, 1, N);
    for (int i = 0; i < M; i++) {
        int from, to;
        cin >> from >> to;
        pair<int, int> p = find(1, from, to, 1, N);
        cout << p.first << " " << p.second << "\n";
    }
    return 0;
}