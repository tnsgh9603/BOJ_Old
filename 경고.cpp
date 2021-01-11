#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int s[3], e[3], ret[3];
    scanf("%d:%d:%d", &s[0], &s[1], &s[2]);
    scanf("%d:%d:%d", &e[0], &e[1], &e[2]);
    if (e[2] >= s[2]) {
        ret[2] = e[2] - s[2];
    }
    else {
        ret[2] = 60 + e[2] - s[2]; e[1]--; 
    }
    if (e[1] >= s[1]) {
        ret[1] = e[1] - s[1];
    }
    else {
        ret[1] = 60 + e[1] - s[1]; e[0]--; 
    }
    if (e[0] >= s[0]) {
        ret[0] = e[0] - s[0];
    }
    else {
        ret[0] = 24 + e[0] - s[0];
    }
    if (ret[0] == 0 && ret[1] == 0 && ret[2] == 0) {
        ret[0] = 24;
    }
    printf("%02d:%02d:%02d\n", ret[0], ret[1], ret[2]);
    return 0;
}