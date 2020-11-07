#include <iostream>
#include <queue>
using namespace std;

int N;
int MAP[50][50];
int visited[50][50];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void bfs(){

    queue<pair<int, int>> Q;
    Q.push(make_pair(0, 0));
    visited[0][0] = 0;

    while (!Q.empty())
    {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + "1120"[i]-'1';
            int ny = y + "2011"[i]-'1';
            if (nx >= 0 && ny >= 0 && nx < N && ny < N)
            {
                if (MAP[nx][ny] == 1)
                {
                    if (visited[nx][ny] > visited[x][y])
                    {
                        visited[nx][ny] = visited[x][y];
                        Q.push(make_pair(nx, ny));
                    }
                }
                else{
                    if (visited[nx][ny] > visited[x][y] + 1)
                    {
                        visited[nx][ny] = visited[x][y] + 1;
                        Q.push(make_pair(nx, ny));
                    }
                }
            }
        }
    }
}

int main(){

    string input;

    cin >> N;

    for (int i = 0; i < N; i++){
        cin >> input;
        for (int k = 0; k < N; k++){
            MAP[i][k] = input[k] - '0';
        }
    }

    fill(&visited[0][0], &visited[49][50], 987654321);

    bfs();

    cout << visited[N - 1][N - 1] << "\n";

    return 0;
}