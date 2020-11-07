#include <iostream>
#include <cstring>
#include <algorithm>
#define INT_MAX 2000000000;
using namespace std;
int N, Answer_Bit;
int MAP[16][16];
int Cost[16][1 << 16];

int DFS(int Cur_Node, int Cur_Bit) {  // 0,1
    if (Cur_Bit == Answer_Bit && MAP[Cur_Node][0] != 0) { // 도시들을 다 방문했고 다시 출발점으로 돌아올 수 있다면
        return MAP[Cur_Node][0];
    }
    if (Cost[Cur_Node][Cur_Bit] != -1) { // 이미 계산한거면 바로 return
        return Cost[Cur_Node][Cur_Bit];
    }

    Cost[Cur_Node][Cur_Bit] = INT_MAX;

    for (int i = 0; i < N; i++) {
        if (MAP[Cur_Node][i] == 0) {
            continue;
        }
        if ((Cur_Bit & (1 << i)) == (1 << i)) {
            continue;
        }
        Cost[Cur_Node][Cur_Bit] = min(Cost[Cur_Node][Cur_Bit], MAP[Cur_Node][i] + DFS(i, Cur_Bit | 1 << i));
    }
    return Cost[Cur_Node][Cur_Bit];
}
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> MAP[i][j];
        }
    }
    Answer_Bit = (1 << N) - 1;
    
    memset(Cost, -1, sizeof(Cost));
    cout << DFS(0, 1) << "\n"; 

    return 0;
}