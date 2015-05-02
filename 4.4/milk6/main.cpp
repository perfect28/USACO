/*
ID:perfect13
LANG:C++
TASK:milk6
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <fstream>
#define INF 0x7FFFFFFF
#define MAXN 0x7FFFFFFF
using namespace std;

int cap[50][50];
int now_cap[50][50];
int a[50],p[50];
int flow[50][50];
int n,m;
int max_flow;
int ans[1050];

struct Edge
{
    int index;
    int u,v;
    long w;
}edge[1050];


int cmp(Edge u,Edge v)
{
    if (u.w==v.w)
        return u.index<v.index;
    else
        return u.w>v.w;
}

void EdmondKarp(int s,int t)
{
    queue<int> q;
    memset(flow,0,sizeof(flow));
    memset(p,0,sizeof(p));
    max_flow=0;
    while(1)
    {
        memset(a,0,sizeof(a));
        a[s]=INF;
        q.push(s);
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            for(int v=1;v<=n;v++)
            {
                if (!a[v]&&cap[u][v]-flow[u][v]>0)
                {
                    p[v]=u;
                    a[v]=(cap[u][v]-flow[u][v]<a[u])?cap[u][v]-flow[u][v]:a[u];
                    q.push(v);
                }
            }
        }
        if (!a[t])
            break;
        for(int u=t;u!=s;u=p[u])
        {
            flow[p[u]][u]+=a[t];
            flow[u][p[u]]-=a[t];
        }
        max_flow+=a[t];
    }
}
int main()
{
    //FILE *fin=fopen("milk6.in","r");
    //FILE *fout=fopen("milk6.out","w");

    ifstream fin ("milk6.in");
    ofstream fout ("milk6.out");
    //fscanf(fin,"%d%d",&n,&m);
    fin>>n>>m;
    int u,v,w;
    memset(cap,0,sizeof(cap));
    for(int i=1;i<=m;i++)
    {
        //fscanf(fin,"%d%d%d",&u,&v,&w);
        fin>>u>>v>>w;
        edge[i].index=i;
        edge[i].u=u;
        edge[i].v=v;
        edge[i].w=w;
        cap[u][v]+=w;
    }
    EdmondKarp(1,n);
    sort(edge+1,edge+1+m,cmp);
    /*
    for(int i=1;i<=m;i++)
    {
        cout<<i<<":"<<edge[i].index
        <<' '<<edge[i].u<<' '<<edge[i].v
        <<' '<<edge[i].w<<endl;
    }
    */
    int flow;
    int num=0;
    //printf("%d\n",max_flow);
    fout<<max_flow<<' ';
    memcpy(now_cap,cap,sizeof(cap));
    flow=max_flow;
    for(int i=1;i<=m;i++)
    {
        memcpy(cap,now_cap,sizeof(cap));
        cap[edge[i].u][edge[i].v]-=edge[i].w;
        EdmondKarp(1,n);
        if (flow==max_flow+edge[i].w)
        {
            flow=max_flow;
            ans[++num]=edge[i].index;
            now_cap[edge[i].u][edge[i].v]-=edge[i].w;
        }
    }

    fout<<num<<endl;

    sort(ans+1,ans+1+num);
    for(int i=1;i<=num;i++)
    {
        fout<<ans[i]<<endl;
    }
    return 0;
}


