#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


long long tree[400001];
long long num[400001];

void update(int node, int start, int end, int b, long long diff) {
    if (start <= b && b <= end) {
        tree[node] += diff; // 범위 내에 있을 경우 차이만큼 + 해줌
    }
    else {
        return; // 범위 밖인 경우 고려 x
    }
    if (start == end) {  // 맨 마지막 노드(리프 노드)까지 왔으면 그만 함.
        return;
    }

    int mid = (start + end) / 2;

    /* << 현재 노드의 번호가 node 일 때 >>
    노드의 왼쪽 자식 배열 번호 :: node * 2
    노드의 오른쪽 자식 배열 번호 :: node * 2  + 1 */

    update(node * 2, start, mid, b, diff);
    update(node * 2 + 1, mid + 1, end, b, diff);
}
long long sum(int left, int right, int node, int start, int end) {
    if (left <= start && end <= right) { // 구하는 구간이 노드의 구간을 포함할 때
        return tree[node];
    }
    if (right < start || end < left) { // 아예 벗어나있을때 고려x
        return 0;
    }

    //어중간하게 겹칠때
    long long mid = (start + end) / 2;
    return sum(left, right, node * 2, start, mid) + sum(left, right, node * 2 + 1, mid + 1, end);
}
long long init(int node, int start, int end) { // n번 노드는 start ~ end를 맡는다

    if (start == end) { // 맨 마지막 노드(리프 노드)까지 왔을 때
        return tree[node] = num[start]; // 값을 넣어줌
    }
    int mid = (start + end) / 2;

    /* << 현재 노드의 번호가 node 일 때 >>
    노드의 왼쪽 자식 배열 번호 :: node * 2
    노드의 오른쪽 자식 배열 번호 :: node * 2  + 1 */

    tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
    return tree[node];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> num[i];
    }

    init(1, 1, N); // 초기화

    for (int i = 0; i < M; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a > b) {
            swap(a, b);
        }
        cout << sum(a, b, 1, 1, N) << "\n";
        long long diff = d - num[c];
        // c번째 수를 d로 바꾼다.
        num[c] = d;
        update(1, 1, N, c, diff); 
    }
}
