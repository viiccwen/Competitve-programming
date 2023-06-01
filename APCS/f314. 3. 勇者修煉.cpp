#include <iostream>
#include <vector>
#include <algorithm>

int m,n,ans;
int dp[51][10001]={{0}};

using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> m >> n;

    for(int i=1;i<=m;i++){
        int LtoR[10001]={0}, RtoL[10001]={0}, matrix[10001]={0};

        for(int j=1;j<=n;j++) cin >> matrix[j];

        for(int j=1;j<=n;j++){   // O1------->On
            if(j == 1) LtoR[j] = dp[i-1][j] + matrix[j];
            else LtoR[j] = max(LtoR[j-1], dp[i-1][j]) + matrix[j];
        }

        for(int j=n;j>=1;j--){   // O1<-------On
            if(j == n) RtoL[j] = dp[i-1][j] + matrix[j];
            else RtoL[j] = max(RtoL[j+1], dp[i-1][j]) + matrix[j];
        }

        for(int j=1;j<=n;j++) dp[i][j] = max(LtoR[j], RtoL[j]);
    }

    for(int j=1;j<=n;j++) ans = max(ans, dp[m][j]);

    cout << ans;
    return 0;
}
/*
2 5
2 1 4 -7 4
8 9 -5 -10 -3

24

** 19
*/
