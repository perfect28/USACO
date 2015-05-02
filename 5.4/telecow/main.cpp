/*
ID:perfect13
LANG:C++
TASK:telecow
*/
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <fstream>
#define MAXN 120
#define INF 0x7fffffff

using namespace std;

int n,m,st,ed;

int tab[MAXN][MAXN];
int dis[MAXN];
int q[2000];
int ans;

bool bfs()
{
    int h=0,t=1;
    int x;
    memset(dis,0xff,sizeof(dis));
    dis[st]=0;
    q[t]=st;
    while(h<t)
    {
        x=q[++h];
        for(int i=1;i<=n;i++)
            if (dis[i]<0&&tab[x][i]>0)
            {
                dis[i]=dis[x]+1;
                q[++t]=i;
            }
    }
    if (dis[ed]>0)
        return true;
    else
        return false;
}

int find(int x,int low)
{
    int a=0;
    if (x==ed)
        return low;
    for(int i=1;i<=n;i++)
        if (tab[x][i]>0
            &&dis[i]==dis[x]+1
            &&(a=find(i,min(low,tab[x][i]))))
            {
                tab[x][i]-=a;
                tab[i][x]+=a;
                return a;
            }
    return 0;
}

int main(){
    ifstream fin("telecow.in");
    ofstream fout("telecow.out");
    int u,v,w;
    fin>>n>>m>>st>>ed;
    memset(tab,0,sizeof(tab));
    for(int i=1;i<=m;i++)
    {
        fin>>u>>v;
        tab[u][v+n]=INF;
        tab[u][u+n]=1;
        tab[v][v+n]=1;
    }
    ans=0;
    int tans;
    while(bfs())
    {
        while(tans=find(st,INF))
            ans+=tans;
    }
    cout<<ans<<endl;

    memcpy(ini_tab,tab,sizeof(tab));

    for(int i=1;i<=n;i++)
        if (i!=st||i!=ed)
    {
        int min_edge=INF;
        memcpy(tab,ini_tab,sizeof(tab));
        for(int j=1;j<=n;j++)
            if (tab[i][j])
            {
                if (min_edge>tab[i][j])
                    min_edge=tab[i][j];
                tab[i][j]=0;
                tab[j][i]=0;
            }

        int now_ans=0;
        while(bfs())
        {
            while(tans=find(st,INF))
                ans+=tans;
        }
        if (now_ans+min_edge==ans)
    }
    return 0;
}
