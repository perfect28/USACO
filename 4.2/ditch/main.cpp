 /*
ID:perfect13
LANG:C++
TASK:ditch
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#define INF 0x7FFFFFFF
#define MAXN 250
using namespace std;

int tab[MAXN][MAXN];
int dis[MAXN];
int q[1000];
int n,m;

bool bfs()
{
    int h=0,t=1;
    int now;
    memset(dis,-1,sizeof(dis));
    dis[1]=0;
    q[t]=1;
    while(h!=t)
    {
        h=(h+1)%1000;
        now=q[h];
        for(int x=1;x<=n;x++)
            if (dis[x]<0&&tab[now][x])
            {
                t=(t+1)%1000;
                q[t]=x;
                dis[x]=dis[now]+1;
            }
    }
    if (dis[n]>0)
        return true;
    else
        return false;
}


//Find代表一次增广,函数返回本次增广的流量
//返回0表示无法增广
int find(int x,int low)
//Low是源点到现在最窄的(剩余流量最小)的边的剩余流量
{
    int tmp;
    if (x==n) return low;
    for(int i=1;i<=n;i++)
        if (tab[x][i])
        if (dis[i]==dis[x]+1)
        if (tmp=find(i,min(low,tab[x][i])))
        {
            tab[x][i]-=tmp;
            tab[i][x]+=tmp;
            return tmp;
        }
    return 0;
}

int main()
{
    FILE *fin=fopen("ditch.in","r");
    FILE *fout=fopen("ditch.out","w");
    fscanf(fin,"%d%d",&m,&n);
    memset(tab,0,sizeof(tab));
    for(int i=1;i<=m;i++)
    {
        int u,v,flow;
        fscanf(fin,"%d%d%d",&u,&v,&flow);
        tab[u][v]+=flow;
    }
    int ans=0;
    while(bfs())
    {
        int tmp;
        while(tmp=find(1,INF))
            ans+=tmp;
    }
    fprintf(fout,"%d\n",ans);
    return 0;
}
