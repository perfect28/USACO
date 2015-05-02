 /*
ID:perfect13
LANG:C++
TASK:race3
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#define INF 0x7FFFFFFF
#define MAXN 105
using namespace std;

struct node
{
    int x,next;
}f[MAXN];

int st[MAXN];
int ans[MAXN],ans2[MAXN];
bool flag[MAXN],vis[MAXN];
int ed;
bool ok;

void dfs(int s)
{
    if (ok) return;
    int tmp=st[s];
    while(tmp!=-1)
    {
        int x=f[tmp].x;
        if (!flag[x]&&!vis[x])
        {
            if (x==ed)
            {
                ok=true;
                return;
            }
            vis[x]=true;
            dfs(x);
        }
        tmp=f[tmp].next;
    }
}

void dfs2(int s)
{
    if (ok) return;
    int tmp=st[s];
    while(tmp!=-1)
    {
        int x=f[tmp].x;
        if (!flag[x]&&!vis[x])
        {
            if (x<ed)
            {
                ok=true;
                return;
            }
            vis[x]=true;
            dfs2(x);
        }
        tmp=f[tmp].next;
    }
}

int main()
{
    FILE *fin=fopen("race3.in","r");
    FILE *fout=fopen("race3.out","w");
    int u,v,i;
    u=0;i=0;
    memset(st,-1,sizeof(st));
    while(fscanf(fin,"%d",&v)&&v!=-1)
    {
        ed++;
        if (v==-2) continue;
        i++;
        f[i].x=v;
        f[i].next=st[u];
        st[u]=i;
        while(fscanf(fin,"%d",&v)&&v!=-2)
        {
            i++;
            f[i].x=v;
            f[i].next=st[u];
            st[u]=i;
        }
        u++;
    }
    ed=ed-1;
    int num=0;
    for(int i=1;i<ed;i++)
    {
        memset(flag,false,sizeof(flag));
        memset(vis,false,sizeof(vis));
        flag[i]=true;
        ok=false;
        dfs(0);
        if (!ok)
            ans[++num]=i;
    }

    if (num==0)
        fprintf(fout,"0\n");
    else{
        fprintf(fout,"%d ",num);
        for(int i=1;i<=num;i++)
            if (i==num)
                fprintf(fout,"%d\n",ans[i]);
            else
                fprintf(fout,"%d ",ans[i]);
    }


    int cnt=0;
    for(int i=1;i<=num;i++)
    {
        memset(flag,false,sizeof(flag));
        memset(vis,false,sizeof(vis));
        ed=ans[i];
        ok=false;
        dfs2(ans[i]);
        if (!ok)
            ans2[++cnt]=ans[i];
    }

    if (cnt==0)
        fprintf(fout,"0\n");
    else{
        fprintf(fout,"%d ",cnt);
        for(int i=1;i<=cnt;i++)
            if (i==cnt)
                fprintf(fout,"%d\n",ans2[i]);
            else
                fprintf(fout,"%d ",ans2[i]);
    }


    return 0;
}
