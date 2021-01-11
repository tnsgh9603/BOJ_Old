#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

long long init(vector<long long>& arr, vector<long long>& tree, int node, int start, int end) {

    if (start == end) { // 맨 마지막 노드(리프 노드)까지 왔을 때
        return tree[node] = arr[start]; // 값을 넣어줌
    }
    
    int mid = (start + end) / 2;

    /* << 현재 노드의 번호가 node 일 때 >>
    노드의 왼쪽 자식 배열 번호 :: node * 2
    노드의 오른쪽 자식 배열 번호 :: node * 2  + 1 */

    return tree[node] = init(arr, tree, node * 2, start, mid) + init(arr, tree, node * 2 + 1, mid + 1, end);
}

void update_lazy(vector<long long>& tree, vector<long long>& lazy, int node, int start, int end) {
    
    // lazy가 0이면 return;
    if (lazy[node] == 0) {
        return;
    }
   
    // 자식 노드가 있는 수 만큼 lazy값에 곱하여 더한다.
    // 자식에게 lazy를 분배하니 자식이 return으로 더해주지 못한 값을 직접 더한다.
    tree[node] += (end - start + 1) * lazy[node];

    // leaf가 아니면
    // 자식에게 lazy를 물려준다.
    if (start != end) {
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
    }

    // 물려준 후 lazy는 초기화
    lazy[node] = 0;
}

void update_range(vector<long long>& tree, vector<long long>& lazy, int node, int start, int end, int left, int right, long long val) {

    /*
        순서 ::
        1. lazy가 존재하면 업데이트 해준다.(tree[node] 변화)
        2. val을 더해준다.(자식수가 있는 만큼)
        2에서 자식 수만큼 더해주는 이유는 자식들은 아직 lazy가 업데이트 되지 않았기 때문
    */

    // 현재 노드에 lazy가 있는지 확인 후, lazy가 있다면 node를 업데이트 해준다.
    update_lazy(tree, lazy, node, start, end);

    // 구간이 하나도 속하지 않는다면 return;
    if (left > end || right < start) {
        return;
    }

    // 원하는 구간 내에 있는 노드에 왔을 경우
    if (left <= start && end <= right) {
        // 자식 노드가 있는 수 만큼 val을 곱해서 더해준다.
        // 자식이 return으로 더해주는 형태가 아니니 직접 더한다.
        tree[node] += (end - start + 1) * val;
        
        // 리프노드가 아니라면 lazy값을 자식 노드에게 물려줌
        if (start != end) {
            lazy[node * 2] += val;
            lazy[node * 2 + 1] += val;
        }
        return;
    }

    // 구간이 애매하게 겹치는 경우
    int mid = (start + end) / 2;
    update_range(tree, lazy, node * 2, start, mid, left, right, val);
    update_range(tree, lazy, node * 2 + 1, mid + 1, end, left, right, val);

    // 구간이 걸쳐서 속해 있다면 자식 노드를 이용하여 부모 노드를 업데이트 한다.
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

long long sum(vector<long long>& tree, vector<long long>& lazy, int node, int start, int end, int left, int right) {

    // 아예 벗어나있을때 고려x
    if (left > end || right < start) {
        return 0;
    }
    // update이후 남은 lazy를 해당하는 구간을 sum 할 때 업데이트 해준다.
    update_lazy(tree, lazy, node, start, end);


    // 구하는 구간이 노드의 구간을 포함할 때
    if (left <= start && end <= right) {
        return tree[node];
    }

    //어중간하게 겹칠때
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