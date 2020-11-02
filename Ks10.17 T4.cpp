#include<bits/stdc++.h>
using namespace std;
struct node{
	int x, y, times;
	bool flag;
	node(int x, int y, int times, bool flag): x(x), y(y), times(times), flag(flag) {}
};
int n, m, sx, sy, ans;
int mv1[4] = {1, -1, 0, 0}, mv2[4] = {0, 0, 1, -1}; 
char mp[1005][1005];
bool vis[1005][1005];
queue<node>q;
int main(){
	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){
		cin >> mp[i][j];
		if(mp[i][j] == 'O') sx = i, sy = j;
	}
	vis[sx][sy] = true;
	q.push(node(sx, sy, 0, false));
	while(!q.empty()){
		node t = q.front();
		q.pop();
		if(mp[t.x][t.y] == 'X'){
			cout << t.times;
			return 0;
		}
		if(t.flag){
			q.push(node(t.x, t.y, t.times+1, false));
			continue;
		}
		for(int i = 0; i < 4; i++){
			int nx = t.x + mv1[i], ny = t.y + mv2[i];
			if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if(mp[nx][ny] == '#') continue;
			if(vis[nx][ny]) continue;
			if(mp[nx][ny] == '*') q.push(node(nx, ny, t.times+1, true));
			else q.push(node(nx, ny, t.times+1, false));
			vis[nx][ny] = true;
		}
	}
	cout << "T_T";
	return 0;
}
