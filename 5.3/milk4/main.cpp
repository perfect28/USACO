/*
ID:perfect13
LANG:C++
TASK:milk4
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <fstream>
#define INF 0x7FFFFFFF
#define MAXN 150
using namespace std;

int Q,n;
int vol[MAXN];
int depth;
int now[MAXN];
bool flag[MAXN];
bool f[20500],vis[20500];
bool ok;
FILE *fin=fopen("milk4.in","r");
FILE *fout=fopen("milk4.out","w");

bool find(int x)
{
    if (vis[x]) return f[x];
    vis[x]=true;
    for(int i=1;i<=depth;i++)
        if (x>=now[i]&&find(x-now[i]))
            return f[x]=true;
    return f[x]=false;
}

void id_dfs(int k,int s)
{
    if (k>depth)
    {
        int st=0;
        memset(f,false,sizeof(f));
        f[st]=true;
        memset(vis,false,sizeof(vis));
        vis[st]=true;
        if (find(Q))
        {
            fprintf(fout,"%d",depth);
            for(int i=1;i<=depth;i++)
                fprintf(fout," %d",now[i]);
            fprintf(fout,"\n");
            exit(0);
        }
        return;
    }
    for(int i=s+1; i<=n; i++)
        if (!flag[i])
        {
            now[k]=vol[i];
            flag[i]=true;
            id_dfs(k+1,i);
            flag[i]=false;
        }
}
int main()
{
    fscanf(fin,"%d%d",&Q,&n);
    for(int i=1; i<=n; i++)
        fscanf(fin,"%d",&vol[i]);

    sort(vol+1,vol+1+n);

    depth=0;
    ok=false;
    int i;
    for(i=1; i<=n; i++)
    {
        memset(flag,false,sizeof(flag));
        depth++;
        id_dfs(1,0);
    }
    return 0;
}
