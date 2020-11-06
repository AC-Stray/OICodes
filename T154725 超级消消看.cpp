#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
//#define debug 1
using namespace std;
struct node{
    int v[5][5];
}tmp, now;
queue<node>q;
int tans, ans;
int mv1[4] = {1, -1, 0, 0}, mv2[4] = {0, 0, 1, -1};
bool vis1[5][5], vis2[5][5];
void down(int x, int y){
    if(x == 4) return;
    if(now.v[x+1][y] == 0){
        swap(now.v[x][y], now.v[x+1][y]);
        down(x+1, y);
    }
}
int dfs(int x, int y){
    if(vis1[x][y]) return 0;
    vis1[x][y] = vis2[x][y] = true;
    int res = 0;
    for(int i = 0; i < 4; i++){
        int nx = x + mv1[i], ny = y + mv2[i];
        if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
        if(now.v[x][y] == now.v[nx][ny])
            res += dfs(nx, ny);
    }
    return res+1;
}
int main(){
    freopen("input.in", "r", stdin);
    for(int i = 0; i < 5; i++) for(int j = 0; j < 5; j++) cin >> tmp.v[i][j];
    q.push(tmp);
    ans = 25;
    while(!q.empty()){
        now = q.front();
        q.pop();
        tans = 0;
        for(int i = 0; i < 5; i++) for(int j = 0; j < 5; j++)
            if(now.v[i][j] != 0) tans++;
        ans = min(ans, tans);
        #ifdef debug
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++) cout << now.v[i][j];
            cout << endl;
        }
        cout << endl;
        #endif // ifdef debug
        for(int i = 3; i >= 0; i--) for(int j = 0; j <=4; j++) down(i, j);
        #ifdef debug
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++) cout << now.v[i][j];
            cout << endl;
        }
        cout << endl << endl;
        #endif // ifdef debug
        memset(vis1, 0, sizeof(vis1));
        for(int i = 0; i < 5; i++) for(int j = 0; j < 5; j++){
            if(vis1[i][j]) continue;
            if(now.v[i][j] == 0) continue;
            memset(vis2, 0, sizeof(vis2));
            if(dfs(i, j) >= 3){
                tmp = now;
                for(int i = 0; i < 5; i++) for(int j = 0; j < 5; j++)
                    if(vis2[i][j]) tmp.v[i][j] = 0;
                q.push(tmp);
            }
        }
    }
    cout << ans;
    return 0;
}