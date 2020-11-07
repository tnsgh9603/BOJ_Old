#include <iostream>
using namespace std;
bool visited[501] = { 0, };
int parent[501] = { 0, };
int get_root(int parent[], int x) { // ��Ʈ�� ã�� ����

    if (parent[x] == x) { // ��Ʈ��尡 �ڱ� �ڽ��� ��
        return x; // ��Ʈ�� ã���� ��ȯ
    }
    else {
        return parent[x] = get_root(parent, parent[x]); // ��Ʈ�� ��ã���� ã�������� ����Լ� �ݺ�
    }
}
void union_root(int parent[], int a, int b) {

    a = get_root(parent, a);
    b = get_root(parent, b);
    if (a == b) // ����Ŭ�� �ɷ���
    {
        visited[a] = false;
        visited[b] = false;
        return;
    }
    else if (a < b) { // ������ �� ���ڰ� ���� ��带 �θ� ���� ����, �ݴ�� �ص� ����
        if (visited[b] == false) {
            visited[a] = false;
        }
        parent[b] = a;
    }
    else {
        if (visited[a] == false) {
            visited[b] = false;
        }
        parent[a] = b;
    }
}
void init()
{
    for (int i = 0; i <= 500; i++) {
        parent[i] = i;
        visited[i] = true;
    }
}
int main() {
    int n, m, from, to, num = 1;
    while (1)
    {
        init();
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        init();
        for (int i = 0; i < m; ++i)
        {
            int a, b;
            cin >> a >> b;
            union_root(parent, a, b);
        }
        int ans = 0;
        for (int j = 1; j <= n; ++j)
        {
            if (visited[get_root(parent, j)])
            {
                visited[get_root(parent, j)] = false;
                ans++;
            }
        }
        if (ans == 0) {
            cout << "Case " << num << ": No trees.\n";
        }
        else if (ans == 1) {
            cout << "Case " << num << ": There is one tree.\n";
        }
        else {
            cout << "Case " << num << ": A forest of " << ans << " trees.\n";
        }
        num++;
    }
    return 0;
}