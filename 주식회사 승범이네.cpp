#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAX_st = 1 << 18;
int arr[MAX_st], lazy[MAX_st];

struct SegTree {
    int start = MAX_st / 2;

    SegTree() {
        // 모두 0으로 초기화
        fill(arr, arr + MAX_st, 0);
        fill(lazy, lazy + MAX_st, 0);
    }

    void propagate(int node, int ns, int ne) {

        // lazy 값이 0이 아니면
        if (lazy[node]) {
            // 리프 노드가 아니라면 
            if (node < start) {
                lazy[node * 2] += lazy[node];
                lazy[node * 2 + 1] += lazy[node];
            }
            // 부모노드 계산
            arr[node] += lazy[node] * (ne - ns + 1);
            // 초기화
            lazy[node] = 0;
        }
    }

    void add(int s, int e, int k) {
        return add(s, e, k, 1, 0, start - 1);
    }
    void add(int s, int e, int k, int node, int ns, int ne) {
        
        propagate(node, ns, ne);
        
        // 범위 벗어나면 return
        if (e < ns || ne < s) {
            return;
        }
        // 범위안에 들어오면
        if (s <= ns && ne <= e) {
            lazy[node] += k;
            propagate(node, ns, ne);
            return;
        }

        // 구간이 걸칠때
        int mid = ns + ne >> 1;
        add(s, e, k, node * 2, ns, mid);
        add(s, e, k, node * 2 + 1, mid + 1, ne);
        arr[node] = arr[node * 2] + arr[node * 2 + 1];
    }

    int query(int s, int e) { 
        return query(s, e, 1, 0, start - 1); 
    }
    int query(int s, int e, int node, int ns, int ne) {
        
        propagate(node, ns, ne);

        // 범위 밖일때
        if (e < ns || ne < s) {
            return 0;
        }
        // 범위에 들어올때
        if (s <= ns && ne <= e) {
            return arr[node];
        }
        // 범위에 걸칠때
        int mid = ns + ne >> 1;
        return query(s, e, node * 2, ns, mid) + query(s, e, node * 2 + 1, mid + 1, ne);
    }
} st;

int N, M, w, p;
const int MAX = 1e5 + 10;
vector<int> adj[MAX];
int children[MAX], visited[MAX], number[MAX], c;

// number[i]에는 노드번호가 담겨있다.
// ex) number[3] = 4 면 4번째 사원번호에 3이라는 노드번호 부여
// dfs를 통해 번호를 매겨가면서 children 배열에 자식 노드(부사수)가 몇 개 있는지 저장
int dfs(int i, int level) {
    //number[i]에 잔고 저장
    number[i] = c++;
    if (adj[i].empty()) {
        children[i] = 1;
        return 1;
    }
    else {
        int cnt = 1;
        for (auto& p : adj[i]) {
            cnt += dfs(p, level + 1);
        }
        children[i] = cnt;
        return children[i];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> p;
        // 승범이는 무시한다
        if (p == -1) {
            continue;
        }
        // i번째 사원의 사수는 p다
        adj[p].push_back(i);
    }

    dfs(1, 0);
    for (int k = 0; k < M; k++) {
        int p, i, w;
        cin >> p;

        if (p == 1) {
            cin >> i >> w;

            st.add(number[i], number[i] + children[i] - 1, w);
            // profit / deficit
        }
        else {
            cin >> i;

            cout << st.query(number[i], number[i]) << "\n";
        }
    }
}