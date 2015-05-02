/*
ID:perfect13
LANG:C++
TASK:wormhole
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

struct Node{
    int x,y;
}hole[15];

int n;
int ans=0;
int pair_num;
bool vis[15];
bool road[15][15];
int now[15];

bool vv[15];
bool loop_dfs(int s,int st)
{
    if (vv[s]&&s==st)
        return true;
    vv[s]=true;
    for(int i=1;i<=n;i++)
        if (road[s][i])
        {
            for(int j=1;j<=n;j++)
                if (hole[i].y==hole[j].y&&hole[i].x<hole[j].x)
                {
                    return loop_dfs(j,st);
                }
        }
    return false;
}

bool has_loop()
{
    for(int i=1;i<=n;i++)
    {
        memset(vv,false,sizeof(vv));
        if (loop_dfs(i,i))
            return true;
    }
    return false;
}

void dfs(int k)
{
    if (k>pair_num)
    {
        if (has_loop())
            ans++;
        return;
    }

    int i;
    for(i=1;i<=n;i++)
        if (!vis[i])
        {
            vis[i]=true;
            break;
        }

    for(int j=i+1;j<=n;j++)
    {
        if (!vis[j])
        {
            vis[j]=true;
            road[i][j]=true;
            road[j][i]=true;
            now[k*2-1]=i;
            now[k*2]=j;
            dfs(k+1);
            vis[j]=false;
            road[i][j]=false;
            road[j][i]=false;
        }
    }
    vis[i]=false;

}

int cmp(Node u,Node v)
{
    if (u.y==v.y)
        return u.x<v.x;
    else
        return u.y<v.y;
}

int main()
{
    FILE *fin=fopen("wormhole.in","r");
    FILE *fout=fopen("wormhole.out","w");

    fscanf(fin,"%d",&n);
    for(int i=1;i<=n;i++)
        fscanf(fin,"%d%d",&hole[i].x,&hole[i].y);
    sort(hole+1,hole+1+n,cmp);
    pair_num=n/2;

    memset(vis,false,sizeof(vis));
    dfs(1);

    fprintf(fout,"%d\n",ans);
    return 0;
}
