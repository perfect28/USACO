/*
ID:perfect13
LANG:C++
TASK:subset
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 10000
using namespace std;


//01背包 dp[i][j]表示前i个数字取得和为j的方案数
//状态转移方程：dp[i][j]=dp[i-1][j]+dp[i-1][j-i];
long long dp[MAXN];
int main()
{
    FILE *fin=fopen("subset.in","r");
    FILE *fout=fopen("subset.out","w");
    int n;
    fscanf(fin,"%d",&n);
    int sum=n*(n+1)/2;
    if (sum%2==1)
        fprintf(fout,"0\n");
    else{
        dp[0]=1;
        sum=sum/2;
        for(int i=1;i<=n;i++)
            for(int j=sum;j>=i;j--)
            dp[j]=dp[j]+dp[j-i];
        fprintf(fout,"%lld\n",dp[sum]/2);
    }
    return 0;
}
