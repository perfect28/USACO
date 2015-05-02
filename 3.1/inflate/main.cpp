 /*
ID:perfect13
LANG:C++
TASK:inflate
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#define MAXN 10500
using namespace std;

int value[MAXN],cost[MAXN];
int dp[MAXN];

int main()
{
    FILE *fin=fopen("inflate.in","r");
    FILE *fout=fopen("inflate.out","w");
    int m,n;
    fscanf(fin,"%d%d",&m,&n);
    for(int i=1;i<=n;i++)
        fscanf(fin,"%d%d",&value[i],&cost[i]);
    for(int i=1;i<=n;i++)
        for(int v=cost[i];v<=m;v++)
        dp[v]=max(dp[v],dp[v-cost[i]]+value[i]);

    fprintf(fout,"%d\n",dp[m]);
    return 0;
}
