 /*
ID:perfect13
LANG:C++
TASK:agrinet
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#define INF 999999
#define MAXN 150
using namespace std;

int graph[MAXN][MAXN];
int lowcase[MAXN];
bool flag[MAXN];

int main()
{
    FILE *fin=fopen("agrinet.in","r");
    FILE *fout=fopen("agrinet.out","w");
    int n;
    fscanf(fin,"%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            fscanf(fin,"%d",&graph[i][j]);

    for(int i=2;i<=n;i++)
        lowcase[i]=INF;

    for(int i=2;i<=n;i++)
        if (graph[1][i]>0)
        lowcase[i]=graph[1][i];

    int ans=0;
    memset(flag,false,sizeof(flag));
    flag[1]=true;

    for(int num=1;num<n;num++)
    {
        int minn=INF;
        int k;
        for(int i=2;i<=n;i++)
            if (!flag[i]&&minn>lowcase[i])
        {
            minn=lowcase[i];
            k=i;
        }
        ans+=minn;
        flag[k]=true;
        for(int i=2;i<=n;i++)
            if (!flag[i]&&graph[k][i]>0&&lowcase[i]>graph[k][i])
            lowcase[i]=graph[k][i];
    }
    fprintf(fout,"%d\n",ans);

    return 0;
}
