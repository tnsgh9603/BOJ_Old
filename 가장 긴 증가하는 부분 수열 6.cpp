#include <iostream>
#include <algorithm>
using namespace std;

struct poi {
    long long idx, val;
};
poi arr[1000001];
poi tree[4000001];

bool sf(poi a, poi b) { // val������ �����ϰ� val���� ������ index������ �������� ����
    if (a.val == b.val) {
        return a.idx > b.idx;
    }
    return a.val < b.val;
}

bool sf2(poi a, poi b) { // idx������ �����ϰ� idx���� �ٸ��� val������ �������� ����
    if (a.idx != b.idx) return a.idx < b.idx;
    return a.val < b.val;
}

poi mergee(poi a, poi b) { // val���� ū ���� �޾ƿ��� val ���� ������ �� index���� ���ؼ� �־���
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
    if (idx<start || idx>end) { // start�� end ���� ���̿� index�� �ƴϸ� ���ž��� ���� ��带 ��ȯ���ش�. 
        return tree[node];
    }
    if (start == end) { // ������带 ������ ���� ��忡 k���� �־���
        return tree[node] = k;
    }
    poi a = upt(idx, k, start, (start + end) / 2, node * 2); // ���ʳ��
    poi b = upt(idx, k, (start + end) / 2 + 1, end, node * 2 + 1); // ������ ���
    if (a.val > b.val) { // �ڽĳ�� �� val���� ū���� �־���
        tree[node] = a;
    }
    else if (a.val < b.val) { // �ڽĳ�� �� val ���� ū���� �־���
        tree[node] = b;
    }
    else { // val���� ������ ���� index���� ���ؼ� �־���
        tree[node].val = a.val;
        tree[node].idx = a.idx + b.idx;
    }
    return tree[node];
}

poi sol(long long left, long long right, long long start, long long end, long long node) {
    poi x = { 0,0 };
    if (right < start || end < left) { // ���� ����� ���
        return x; 
    }
    if (left <= start && end <= right) { // ������ �������
        return tree[node];
    }

    // �ָ��ϰ� �������� ���

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

    sort(arr + 1, arr + 1 + n, sf);  // val������ �����ϰ� val���� ������ index������ �������� ����
  
    for (i = 1; i <= n; i++) {
        arr[i].val = i;
    }
   
    sort(arr + 1, arr + 1 + n, sf2); // val���� ū ���� �޾ƿ��� val ���� ������ �� index���� ���ؼ� �־���

    poi ans = { 0,0 };
    poi x = { 1,0 };
    
    // val = 0 , idx = 1 �� �ʱ�ȭ
    upt(0, x, 0, n, 1); // poi upt(long long idx, poi k, long long start, long long end, long long node){}

    for (i = 1; i <= n; i++) {
        // 0���� i��°���� ���� �ִ��� ����
        poi x = sol(0, arr[i].val, 0, n, 1); // poi sol(long long left, long long right, long long start, long long end, long long node) {}
          
        // �ִ��� ���Ѱ� + 1
        x.val++; 
        
        x.idx %= 1000000007;
        
        // poi mergee(poi a, poi b) {} -> val���� ū ���� �޾ƿ��� val ���� ������ �� index���� ���ؼ� �־���
        ans = mergee(ans, x);

        ans.idx %= 1000000007;
   
        // ������Ʈ
        upt(arr[i].val, x, 0, n, 1); // poi upt(long long idx, poi k, long long start, long long end, long long node){}
    }
    cout << ans.val << " " << ans.idx;
}