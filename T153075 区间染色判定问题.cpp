#include<bits/stdc++.h>
using namespace std;
struct section{
	long long a, b;
	int c;
}sec[100005];
int t, n;
bool flag;
bool cmp(section s1, section s2){
	if(s1.a != s2.a) return s1.a < s2.a;
	else return s1.b < s2.b;
}
int main(){
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 0; i < n; i++)
			cin >> sec[i].a >> sec[i].b >> sec[i].c;
		sort(sec, sec+n, cmp);
		flag = true;
		for(int i = 0; i < n-1; i++){
			for(int j = i+1; j < n-1; j++){
				if(sec[j].a > sec[i].b) break;
				if(sec[i].a < sec[j].a && sec[j].a < sec[i].b && sec[i].b < sec[j].b && sec[i].c == sec[j].c){
//					cout << sec[i].a << " " << sec[i].b << " " << sec[i].c << endl;
//					cout << sec[j].a << " " << sec[j].b << " " << sec[j].c << endl;
					flag = false;
					break;
				}
			}
			if(!flag) break;
		}
		if(flag) cout << "Accept\n";
		else cout << "WA\n";
	}
	return 0;
}
