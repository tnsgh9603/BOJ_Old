#include <iostream>
#include <queue>
#include <string>
#include <map>
using namespace std;
int main(){
    int start = 0;
    for (int i = 1; i <= 3; i++){      // 퍼즐 숫자 입력받기
        for (int j = 1; j <= 3; j++){
            int temp;
            cin >> temp; // 배열을 사용하지 않고 숫자를 쭉 늘려서 표현
            if (temp == 0){
                temp = 9; // 빈칸을 0으로 처리하면 맨 앞에 0이 위치할 때, 없어질 수 있으므로 9로 바꾼다.
            }
            start = start * 10 + temp;    //퍼즐 숫자를 int형 숫자로 저장
        }
    }
    queue <int> q;
    map <int, int> dist;        // 배열 대신 map을 사용한다.
    dist[start] = 0; // map<key, value> -> 사용할 때는 list처럼 map[key] = value;로 사용할 수 있다.
    q.push(start); // 문자열 넣기
    while (!q.empty()){
        int now_num = q.front();
        string now = to_string(now_num);        // now_num는 int형이므로 string형으로 바꾼다
        q.pop();

        int nn = now.find('9');        // 9의 위치
        int x = nn / 3;                // 9의 위치의 행값
        int y = nn % 3;                // 9의 위치의 열값

        for (int k = 0; k < 4; k++){    // 4방향으로 이동
        
            int nx = x + "1120"[k] - '1'; // 0 0 1 -1
            int ny = y + "2011"[k] - '1'; // 1 -1 0 0

            if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3){        // 경계를 넘어가면 고려 x
                string next = now;
                swap(next[3 * x + y], next[3 * nx + ny]);        //일자로 펼쳐진 숫자에서 퍼즐의 4방향에 위치한 숫자와 바꾼다 (실제로 이동하는 작업을 수행하는 부분!)
                int num = stoi(next);                        //다시 int형으로 바꾼다.
                if (dist.count(num) == 0) {                    //dist.count(a)는 a라는%$% key값이 있을 때 1을 return 하고, 없을 때 0을 return한다.
                                                               //즉, 나오지 않았던 퍼즐(방문하지 않았던 것)만 카운트한다.
                    dist[num] = dist[now_num] + 1;
                    q.push(num);
                }
            }
        }
    }
    if (dist.count(123456789) == 0){
        cout << -1 << endl;
    }
    else{
        cout << dist[123456789] << endl;
    }
    return 0;
}