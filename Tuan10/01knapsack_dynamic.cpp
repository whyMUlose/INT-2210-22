
#include <bits/stdc++.h>
using namespace std;

int main() {
int n,S;
cin >> n >>S;
int W[n + 1], v[n+1];
for(int i = 1;i <= n;i++) cin >> W[i];
for(int i = 1 ; i <= n; i++) cin >> v[i];
int dp[n+1][S+1];
memset(dp, 0, sizeof(dp));
for(int i =1; i<=n;i++)
for(int j =1;j <=S;j++) {
    dp[i][j]= dp[i-1][j];
    if(j >= W[i]){
        dp[i][j] = max(dp[i][j], dp[i-1][j-W[i]] + v[i]);
    }
}
    cout << dp[n][S];
return 0;
}
