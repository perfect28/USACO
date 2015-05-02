 /*
ID:perfect13
LANG:C++
TASK:game1
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#define INF 0x7FFFFFFF
#define MAXN 105
using namespace std;

int num[MAXN];
int sum[MAXN][MAXN];
int dp[MAXN][MAXN];

int main()
{
    FILE *fin=fopen("game1.in","r");
    FILE *fout=fopen("game1.out","w");
    int n;
    int left,right,flag;
    fscanf(fin,"%d",&n);
    for(int i=1;i<=n;i++)
        fscanf(fin,"%d",&num[i]);

    //sum[i][j]表示从i到j的所有数字和
    //dp[i][j]表示从i到j这部分的先取者能获得的最大数字和
    //dp[i][j]=sum[i][j]-min(dp[i][j-1],dp[i+1][j]);

    memset(sum,0,sizeof(sum));
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if (i<=j)
            for(int k=i;k<=j;k++)
            sum[i][j]+=num[k];

    for(int len=1;len<=n;len++)
        for(int st=1;st<=n;st++)
        {
            int ed=st+len-1;
            if (ed>n) continue;
            dp[st][ed]=sum[st][ed]-min(dp[st][ed-1],dp[st+1][ed]);
        }

    fprintf(fout,"%d %d\n",dp[1][n],sum[1][n]-dp[1][n]);
    return 0;
}
