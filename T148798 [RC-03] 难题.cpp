#include<bits/stdc++.h>
using namespace std;
unsigned long long n, ans;
int main(){
	cin >> n;
	ans = 1;
	while(ans <= n) ans <<= 1;
	ans = (ans - 1) * 2;
	cout << ans; 
	return 0;
}
