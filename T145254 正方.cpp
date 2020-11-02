#include<bits/stdc++.h>
using namespace std;
long long q, sum, ans, e[4];
int main(){
	cin >> q;
	while(q--){
		cin >> e[0] >> e[1] >> e[2] >> e[3];
		sort(e, e+4);
		if(e[0] + e[3] == e[1] + e[2]){
			ans = 1;
			ans *= 1 + !(e[0] == e[3]);
			ans *= 1 + !(e[1] == e[2]);
			ans *= 1 + !(e[0] == e[1]);
			cout << ans << endl;
		}
		else cout << 0 << endl;
	}
	return 0;
}
