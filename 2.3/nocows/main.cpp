/*
ID:perfect13
LANG:C++
TASK:nocows
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int dp[300][200];

int main()
{
    FILE *fin=fopen("nocows.in","r");
    FILE *fout=fopen("nocows.out","w");
    int n,k;
    fscanf(fin,"%d%d",&n,&k);

    memset(dp,0,sizeof(dp));
    for(int i=1;i<=k;i++)
        dp[1][i]=1;
    for(int i=1;i<=n;i+=2)
        for(int j=1;j<=k;j++)
            {
                for(int x=1;x<=i-2;x+=2)
                {
		//dp[i][j]表示高度至多为j的树含有i个结点的总数
                    dp[i][j]+=dp[x][j-1]*dp[i-1-x][j-1];
                    dp[i][j]=dp[i][j]%9901;
                }
            }
    int ans=(dp[n][k]-dp[n][k-1]+9901)%9901;
    fprintf(fout,"%d\n",ans);
    return 0;
}
