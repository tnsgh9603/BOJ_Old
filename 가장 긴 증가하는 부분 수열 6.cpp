#include <iostream>
#include <algorithm>
using namespace std;

struct poi {
    long long idx, val;
};
poi arr[1000001];
poi tree[4000001];

bool sf(poi a, poi b) { // val순으로 정렬하고 val값이 같으면 index순으로 내림차순 정렬
    if (a.val == b.val) {
        return a.idx > b.idx;
    }
    return a.val < b.val;
}

bool sf2(poi a, poi b) { // idx순으로 정렬하고 idx값이 다르면 val순으로 오름차순 정렬
    if (a.idx != b.idx) return a.idx < b.idx;
    return a.val < b.val;
}

poi mergee(poi a, poi b) { // val값이 큰 것을 받아오고 val 값이 같으면 두 index값을 더해서 넣어줌
    poi ret;
    if (a.val > b.val) {
        ret = a;
    }
    else if (a.val < b.val) {
        ret = b;
    }
    else {
        ret.val = a.val;
        ret.idx = a.idx + b.idx;
    }
    return ret;
}

poi upt(long long idx, poi k, long long start, long long end, long long node) {
    if (idx<start || idx>end) { // start와 end 구간 사이에 index가 아니면 갱신없이 현재 노드를 반환해준다. 
        return tree[node];
    }
    if (start == end) { // 리프노드를 만날시 리프 노드에 k값을 넣어줌
        return tree[node] = k;
    }
    poi a = upt(idx, k, start, (start + end) / 2, node * 2); // 왼쪽노드
    poi b = upt(idx, k, (start + end) / 2 + 1, end, node * 2 + 1); // 오른쪽 노드
    if (a.val > b.val) { // 자식노드 중 val값이 큰것을 넣어줌
        tree[node] = a;
    }
    else if (a.val < b.val) { // 자식노드 중 val 값이 큰것을 넣어줌
        tree[node] = b;
    }
    else { // val값이 같으면 둘의 index값을 더해서 넣어줌
        tree[node].val = a.val;
        tree[node].idx = a.idx + b.idx;
    }
    return tree[node];
}

poi sol(long long left, long long right, long long start, long long end, long long node) {
    poi x = { 0,0 };
    if (right < start || end < left) { // 범위 벗어나는 경우
        return x; 
    }
    if (left <= start && end <= right) { // 범위에 있을경우
        return tree[node];
    }

    // 애매하게 겹쳐있을 경우

    poi a = sol(left, right, start, (start + end) / 2, node * 2);
    poi b = sol(left, right, (start + end) / 2 + 1, end, node * 2 + 1);
    if (a.val > b.val) {
        x = a;
    }
    else if (a.val < b.val) {
        x = b;
    }
    else {
        x.val = a.val;
        x.idx = a.idx + b.idx;
    }
    return x;
}

int main() {
    long long i, j, k, l, m, n;
    cin >> n;  
    for (i = 1; i <= n; i++) {
        cin >> arr[i].val;
        arr[i].idx = i;
    }

    sort(arr + 1, arr + 1 + n, sf);  // val순으로 정렬하고 val값이 같으면 index순으로 내림차순 정렬
  
    for (i = 1; i <= n; i++) {
        arr[i].val = i;
    }
   
    sort(arr + 1, arr + 1 + n, sf2); // val값이 큰 것을 받아오고 val 값이 같으면 두 index값을 더해서 넣어줌

    poi ans = { 0,0 };
    poi x = { 1,0 };
    
    // val = 0 , idx = 1 로 초기화
    upt(0, x, 0, n, 1); // poi upt(long long idx, poi k, long long start, long long end, long long node){}

    for (i = 1; i <= n; i++) {
        // 0부터 i번째에서 구간 최댓값을 구함
        poi x = sol(0, arr[i].val, 0, n, 1); // poi sol(long long left, long long right, long long start, long long end, long long node) {}
          
        // 최댓값은 구한값 + 1
        x.val++; 
        
        x.idx %= 1000000007;
        
        // poi mergee(poi a, poi b) {} -> val값이 큰 것을 받아오고 val 값이 같으면 두 index값을 더해서 넣어줌
        ans = mergee(ans, x);

        ans.idx %= 1000000007;
   
        // 업데이트
        upt(arr[i].val, x, 0, n, 1); // poi upt(long long idx, poi k, long long start, long long end, long long node){}
    }
    cout << ans.val << " " << ans.idx;
}