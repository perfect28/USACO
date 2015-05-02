 /*
ID:perfect13
LANG:C++
TASK:stamps
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXN 2000000
using namespace std;

int dp[MAXN];
int value[100];

int main()
{
    FILE *fin=fopen("stamps.in","r");
    FILE *fout=fopen("stamps.out","w");
    int k,n;
    fscanf(fin,"%d%d",&k,&n);
    for(int i=1;i<=n;i++)
        fscanf(fin,"%d",&value[i]);

    //dp[k][x]:表示k张是否能表示x
    //dp[k][x]=dp[k-1][x-value[i]]
    /*
    memset(dp,false,sizeof(dp));
    dp[0]=true;
    for(int t=1;t<=k;t++)
    {
        for(int v=MAXN;v>=1;v--)
            for(int i=1;i<=n;i++)
                if (v-value[i]>=0)
                if (dp[v-value[i]]||dp[v])
                dp[v]=true;
    }
    */

    //dp[i]:表示达到i值所用的最少邮票数
    //dp[i]=dp[i-value[j]]+1;
    memset(dp,0x1f,sizeof(dp));
    dp[0]=0;
    for(int i=1;i<=MAXN;i++)
        for(int j=1;j<=n;j++)
        if (i-value[j]>=0)
        dp[i]=min(dp[i],dp[i-value[j]]+1);

    for(int i=1;i<=MAXN;i++)
        if (dp[i]>k)
        {
            fprintf(fout,"%d\n",i-1);
            break;
        }
    return 0;
}
