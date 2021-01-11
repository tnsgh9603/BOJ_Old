#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

long long init(vector<long long>& arr, vector<long long>& tree, int node, int start, int end) {

    if (start == end) { // �� ������ ���(���� ���)���� ���� ��
        return tree[node] = arr[start]; // ���� �־���
    }
    
    int mid = (start + end) / 2;

    /* << ���� ����� ��ȣ�� node �� �� >>
    ����� ���� �ڽ� �迭 ��ȣ :: node * 2
    ����� ������ �ڽ� �迭 ��ȣ :: node * 2  + 1 */

    return tree[node] = init(arr, tree, node * 2, start, mid) + init(arr, tree, node * 2 + 1, mid + 1, end);
}

void update_lazy(vector<long long>& tree, vector<long long>& lazy, int node, int start, int end) {
    
    // lazy�� 0�̸� return;
    if (lazy[node] == 0) {
        return;
    }
   
    // �ڽ� ��尡 �ִ� �� ��ŭ lazy���� ���Ͽ� ���Ѵ�.
    // �ڽĿ��� lazy�� �й��ϴ� �ڽ��� return���� �������� ���� ���� ���� ���Ѵ�.
    tree[node] += (end - start + 1) * lazy[node];

    // leaf�� �ƴϸ�
    // �ڽĿ��� lazy�� �����ش�.
    if (start != end) {
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
    }

    // ������ �� lazy�� �ʱ�ȭ
    lazy[node] = 0;
}

void update_range(vector<long long>& tree, vector<long long>& lazy, int node, int start, int end, int left, int right, long long val) {

    /*
        ���� ::
        1. lazy�� �����ϸ� ������Ʈ ���ش�.(tree[node] ��ȭ)
        2. val�� �����ش�.(�ڽļ��� �ִ� ��ŭ)
        2���� �ڽ� ����ŭ �����ִ� ������ �ڽĵ��� ���� lazy�� ������Ʈ ���� �ʾұ� ����
    */

    // ���� ��忡 lazy�� �ִ��� Ȯ�� ��, lazy�� �ִٸ� node�� ������Ʈ ���ش�.
    update_lazy(tree, lazy, node, start, end);

    // ������ �ϳ��� ������ �ʴ´ٸ� return;
    if (left > end || right < start) {
        return;
    }

    // ���ϴ� ���� ���� �ִ� ��忡 ���� ���
    if (left <= start && end <= right) {
        // �ڽ� ��尡 �ִ� �� ��ŭ val�� ���ؼ� �����ش�.
        // �ڽ��� return���� �����ִ� ���°� �ƴϴ� ���� ���Ѵ�.
        tree[node] += (end - start + 1) * val;
        
        // ������尡 �ƴ϶�� lazy���� �ڽ� ��忡�� ������
        if (start != end) {
            lazy[node * 2] += val;
            lazy[node * 2 + 1] += val;
        }
        return;
    }

    // ������ �ָ��ϰ� ��ġ�� ���
    int mid = (start + end) / 2;
    update_range(tree, lazy, node * 2, start, mid, left, right, val);
    update_range(tree, lazy, node * 2 + 1, mid + 1, end, left, right, val);

    // ������ ���ļ� ���� �ִٸ� �ڽ� ��带 �̿��Ͽ� �θ� ��带 ������Ʈ �Ѵ�.
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

long long sum(vector<long long>& tree, vector<long long>& lazy, int node, int start, int end, int left, int right) {

    // �ƿ� ��������� ���x
    if (left > end || right < start) {
        return 0;
    }
    // update���� ���� lazy�� �ش��ϴ� ������ sum �� �� ������Ʈ ���ش�.
    update_lazy(tree, lazy, node, start, end);


    // ���ϴ� ������ ����� ������ ������ ��
    if (left <= start && end <= right) {
        return tree[node];
    }

    //���߰��ϰ� ��ĥ��
    int mid = (start + end) / 2;
    return sum(tree, lazy, node * 2, start, mid, left, right) + sum(tree, lazy, node * 2 + 1, mid + 1, end, left, right);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    int h = (int)ceil(log2(n));
    int tree_size = (1 << (1 + h));

    vector<long long> arr(n);
    vector<long long> tree(tree_size);
    vector<long long> lazy(tree_size);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    init(arr, tree, 1, 0, n - 1);
    m += k;

    while (m--) {
        int num;
        cin >> num;

        if (num == 1) {
            int left, right;
            long long val;
            cin >> left >> right >> val;
            update_range(tree, lazy, 1, 0, n - 1, left - 1, right - 1, val);
        }

        else if (num == 2) {
            int left, right;
            cin >> left >> right;
            cout << sum(tree, lazy, 1, 0, n - 1, left - 1, right - 1) << "\n";
        }
    }
    return 0;
}