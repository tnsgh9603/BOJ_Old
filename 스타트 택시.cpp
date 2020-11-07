#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <memory.h>
using namespace std;

/* 손님을 관리하기 위한 구조체 */
/* 알아야할 정보 = [ 손님의 좌표 , 손님의 목적지 좌표 ] */
struct CUSTOMER {
    int x;
    int y;
    int Dest_x;
    int Dest_y;
};

/* 조건에 맞는 손님을 찾기 위한 정보를 관리하는 구조체 */
/* 알아야할 정보 = [ x좌표 , y좌표 , 거리 , 손님의 번호 ] */
struct INFO {
    int x;
    int y;
    int Dist;
    int Num;
};

int N, M, Fuel;
int Taxi_x, Taxi_y;
int MAP[25][25];
bool Visit[25][25];
CUSTOMER Customer[25 * 25];
bool Info_Cmp(INFO A, INFO B) {
    /* 조건에 맞는 손님을 찾기 위해서 Vector를 정렬하기 위한 기준 설정. */
    if (A.Dist <= B.Dist) {
        if (A.Dist == B.Dist) {
            if (A.x <= B.x) {
                if (A.x == B.x) {
                    if (A.y < B.y) {
                        return true;
                    }
                    return false;
                }
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}

bool BFS(int a, int b, int c, int d, int Num){
    /* 손님을 최단 거리로 목적지까지 이동시키기 위한 BFS 탐색 함수. */
    memset(Visit, false, sizeof(Visit));
    queue<pair<pair<int, int>, pair<int, int>>> Q;
    Q.push(make_pair(make_pair(a, b), make_pair(0, Fuel)));
    Visit[a][b] = true;

    while (Q.empty() == 0) {
        int x = Q.front().first.first;
        int y = Q.front().first.second;
        int Distance = Q.front().second.first;
        int Spare_Fuel = Q.front().second.second;
        Q.pop();

        /* 목적지에 도달한다면 ? */
        /* 연료의 양을 문제의 조건에 맞게 재설정. */
        /* 택시의 위치를, 현재 이동시킨 손님의 목적지 위치로 재설정. */
        if (x == c && y == d) {
            Fuel = Fuel - Distance;
            Fuel = Fuel + (Distance * 2);
            Taxi_x = x;
            Taxi_y = y;
            return true;
        }
        /* 더 이상 연료가 없다면 ? = 손님을 더 이상 이동시킬 수 없다. */
        if (Spare_Fuel == 0) {
            return false;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + "1120"[i]-'1';
            int ny = y + "2011"[i]-'1';
            if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
                if (MAP[nx][ny] != -1 && Visit[nx][ny] == false) {
                    Visit[nx][ny] = true;
                    Q.push(make_pair(make_pair(nx, ny), make_pair(Distance + 1, Spare_Fuel - 1)));
                }
            }
        }
    }
    return false;
}

int Find_Shortest_Customer() {
    /* 현재 택시 위치에서 가장 가까운 손님을 찾기 위한 BFS함수. */
    memset(Visit, false, sizeof(Visit));
    queue<pair<pair<int, int>, pair<int, int>>> Q;
    Q.push(make_pair(make_pair(Taxi_x, Taxi_y), make_pair(0, Fuel)));
    Visit[Taxi_x][Taxi_y] = true;
    vector<INFO> V;
    /* 위의 벡터가 "현재 연료의 양으로 찾아갈 수 있는 모든 손님에 대한 정보"를 저장. */
    while (Q.empty() == 0) {
        int x = Q.front().first.first;
        int y = Q.front().first.second;
        int Distance = Q.front().second.first;
        int Spare_Fuel = Q.front().second.second;
        Q.pop();

        /* 맵이 1 이상이라는 것은 해당 좌표에 손님이 있음을 의미. */
        /* 따라서, 해당 좌표에 있는 손님에 대한 정보를 Vector에 저장. */
        if (MAP[x][y] >= 1) {
            V.push_back({ x, y, Distance, MAP[x][y] });
        }
        if (Spare_Fuel == 0) {
            continue;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + "1120"[i] - '1';
            int ny = y + "2011"[i] - '1';
            if (nx >= 0 && ny >= 0 && nx < N && ny < N) {            
                if (MAP[nx][ny] != -1 && Visit[nx][ny] == false) {
                    Visit[nx][ny] = true;
                    Q.push(make_pair(make_pair(nx, ny), make_pair(Distance + 1, Spare_Fuel - 1)));
                }
            }
        }
    }

    /* Vector의 Size = 0 이라는 것은 찾아갈 수 있는 손님이 없음을 의미. */
    if (V.size() == 0) {
        return -1;
    }

    /* 그게 아니라면, 우리가 찾는 딱 한명의 손님을 찾기 위해서 Vector를 정렬. */
    /* 해당 손님은 이제 더 이상 해당 좌표에 없으므로 맵에서 값 변경. */
    /* 현재 택시 위치에서 해당 손님까지 가는데 든 연료만큼 연료의 양 또한 변경. */
    sort(V.begin(), V.end(), Info_Cmp);
    MAP[V[0].x][V[0].y] = 0;
    Fuel = Fuel - V[0].Dist;
    return V[0].Num;
}

int main() {

    cin >> N >> M >> Fuel;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> MAP[i][j];
            if (MAP[i][j] == 1) {
                MAP[i][j] = -1;
            }
            // 맵에서 벽으로 표시되는 1을 -1로 변경.
        }
    }

    cin >> Taxi_x >> Taxi_y;
    // MAP배열 좌측 최상단이 (0,0)이므로 맞춰줌
    Taxi_x--;
    Taxi_y--;
    
    for (int i = 1; i <= M; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--; b--; c--; d--;
        Customer[i] = { a, b, c, d };
        MAP[a][b] = i;
        // 손님이 있는 위치를 각 손님의 번호로 변경
    }
    
    /* 아무리 많아도 손님의 수 만큼만 움직이면 된다. */
    /* 따라서, 0 ~ M번까지만 반복. */
    for (int i = 0; i < M; i++) {
        int Num = Find_Shortest_Customer();

        // 연료내에 갈 수 있는 손님이 없다면
        if (Num == -1) {
            cout << -1 << "\n";
            return 0;
        }

        bool Move = BFS(Customer[Num].x, Customer[Num].y, Customer[Num].Dest_x, Customer[Num].Dest_y, Num);
        
        if (Move == false) {
            cout << -1 << "\n";
            return 0;
        }
    }
    cout << Fuel << "\n";
    return 0;
}