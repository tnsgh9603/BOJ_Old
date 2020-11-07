#include <iostream>
using namespace std;

long long tree[3000000];
long long num[1000001];
long long mod = 1000000007;

long long update(int node, int start, int end, int b, int c) {
    // start와 end 구간 사이에 index가 아니면 갱신없이 현재 노드를 반환해준다. 
    if (!(start <= b && b <= end)) {
        return tree[node];
    }
    // 리프 노드 업데이트
    if (start == end) {
        return tree[node] = c;
    }

    int mid = (start + end) / 2;

    /* << 현재 노드의 번호가 node 일 때 >>
    노드의 왼쪽 자식 배열 번호 :: node * 2
    노드의 오른쪽 자식 배열 번호 :: node * 2  + 1 */

    return tree[node] = ((update(node * 2, start, mid, b, c) % mod) * (update(node * 2 + 1, mid + 1, end, b, c) % mod)) % mod;
}
long long mul(int left, int right, int node, int start, int end) {
    
    if (right < start || end < left) { // 아예 벗어나있을때 고려x (곱이므로 0대신 1 return)
        return 1;
    }
    if (left <= start && end <= right) { // 구하는 구간이 노드의 구간을 포함할 때
        return tree[node];
    }
    //어중간하게 겹칠때
    int mid = (start + end) / 2;
    return ((mul(left, right, node * 2, start, mid) % mod) * (mul(left, right, node * 2 + 1, mid + 1, end) % mod)) % mod;
}
long long init(int node, int start, int end) { // n번 노드는 start ~ end를 맡는다

    if (start == end) { // 맨 마지막 노드(리프 노드)까지 왔을 때
        return tree[node] = num[start]; // 값을 넣어줌
    }
    int mid = (start + end) / 2;

    /* << 현재 노드의 번호가 node 일 때 >>
    노드의 왼쪽 자식 배열 번호 :: node * 2
    노드의 오른쪽 자식 배열 번호 :: node * 2  + 1 */

    // 각 노드의 자식 노드에서 타고 올라온 return 값을 곱해주어 자신의 노드에 값을 넣는다.
    tree[node] = ((init(node * 2, start, mid) % mod) * (init(node * 2 + 1, mid + 1, end) % mod)) % mod;
    return tree[node];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        cin >> num[i];
    }
    init(1, 1, N); // 초기화

    for (int i = 1; i <= M + K; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) { // b번째 수를 c로 바꾼다.
            update(1, 1, N, b, c); // void update(int node, int start, int end, int t, int diff){}
        }
        else {
            cout << mul(b, c, 1, 1, N) % mod << "\n";
        }
    }
    return 0;
}