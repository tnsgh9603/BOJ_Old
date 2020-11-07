#include <iostream>
using namespace std;
bool visited[501] = { 0, };
int parent[501] = { 0, };
int get_root(int parent[], int x) { // 루트를 찾아 떠남

    if (parent[x] == x) { // 루트노드가 자기 자신일 때
        return x; // 루트를 찾으면 반환
    }
    else {
        return parent[x] = get_root(parent, parent[x]); // 루트를 못찾으면 찾을때까지 재귀함수 반복
    }
}
void union_root(int parent[], int a, int b) {

    a = get_root(parent, a);
    b = get_root(parent, b);
    if (a == b) // 사이클을 걸러줌
    {
        visited[a] = false;
        visited[b] = false;
        return;
    }
    else if (a < b) { // 연결할 때 숫자가 작은 노드를 부모 노드로 설정, 반대로 해도 무관
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