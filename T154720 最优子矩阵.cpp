#include<iostream>
//#define debug 1
using namespace std;
int n, ans, g[405][405], sum[2][405][405];
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++){
        cin >> g[i][j];
        sum[0][i][j] = sum[0][i-1][j-1] + g[i][j];
        sum[1][i][j] = sum[1][i-1][j+1] + g[i][j];
    }
    #ifdef debug
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
            cout << sum[1][i][j] << " ";
        cout << endl;
    }
    #endif // ifdef debug
    for(int k = 0; k <= n; k++)
        for(int i = 1; i <= n-k; i++) for(int j = 1; j <= n-k; j++)
            ans = max(ans, sum[0][i+k][j+k] - sum[0][i-1][j-1] - sum[1][i+k][j] + sum[1][i-1][j+k+1]);
    cout << ans;
    return 0;
}