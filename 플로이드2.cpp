#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int city, bus;
int arr[101][101] = { 0, };
int way[111][111] = { 0, };
vector <int> V;
void floyd()
{
    for (int via = 1; via <= city; via++)
    {
        for (int from = 1; from <= city; from++)
        {
            if (arr[from][via] == 0) { //시작점에서 경유점으로 갈 수 없는 경우는 제외
                continue;
            }
            for (int to = 1; to <= city; to++)
            {
                if (arr[via][to] == 0 || from == to) // 경유점에서 도착점으로 갈 수 없는 경우, 시작점 = 도착점인 경우는 고려x
                    continue;
                if (arr[from][to] == 0 || arr[from][to] > arr[from][via] + arr[via][to]) {
                    //시작점에서 도착점으로 바로가는 길이 없거나
                    //곧장 가는 것보다 경유점을 지나서 가는 것이 더 빠를 경우 업데이트
                    arr[from][to] = arr[from][via] + arr[via][to];
                    way[from][to] = via;
                }
            }
        }
    }
}
void Find_Route(int Start, int End)
{
    if (way[Start][End] == 0)
    {
        V.push_back(Start);
        V.push_back(End);
        return;
    }
    Find_Route(Start, way[Start][End]);
    V.pop_back();
    Find_Route(way[Start][End], End);
}
int main(){

    cin >> city >> bus;
    for (int i = 1; i <= bus; i++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        if (arr[from][to] == 0) {
            arr[from][to] = cost;
        }
        else // 이미 경로가 있는 경우 최소값 선택
            arr[from][to] = min(arr[from][to], cost);
    }

    floyd();

    for (int i = 1; i <= city; i++)
    {
        for (int j = 1; j <= city; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    for (int i = 1; i <= city; i++)
    {
        for (int j = 1; j <= city; j++)
        {
            if (arr[i][j] == 0) cout << 0;
            else
            {
                V.clear();
                Find_Route(i, j);
                cout << V.size() << " ";
                for (int k = 0; k < V.size(); k++) {
                    cout << V.at(k) << " ";
                }
            }
            cout << "\n";
        }
    }
    return 0;
}
