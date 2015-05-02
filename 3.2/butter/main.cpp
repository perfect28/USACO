 /*
ID:perfect13
LANG:C++
TASK:butter
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define INF 0x7FFFFFFF
#define MAXN 105000
using namespace std;

int num[1000];
typedef struct{
    int x,value,next;
}Edge;

Edge edge[4000];
typedef pair<int,int> ele;
int dis[1000],st[1000];
bool vis[1000];
int n,p,c;

struct cmp{
    bool operator() ( ele a, ele b ){
        return a.second>b.second;
    }
};

priority_queue< ele, vector<ele>, cmp > q;

void dijkstra(int s)
{
    int now,son;
    ele u;
    memset(vis,false,sizeof(vis));
    for(int i=1;i<=p;i++)
        dis[i]=INF;
    dis[s]=0;
    q.push(make_pair(s,dis[s]));
    while(!q.empty()){
        u=q.top();
        q.pop();
        now=u.first;
        if (vis[now]) continue;
        vis[now]=true;
        for(int i=st[now];i!=-1;i=edge[i].next){
            son=edge[i].x;
            if (dis[son]-edge[i].value>dis[now])
            {
                dis[son]=dis[now]+edge[i].value;
                q.push(make_pair(son,dis[son]));
            }
        }
    }
}
int main()
{
    FILE *fin=fopen("butter.in","r");
    FILE *fout=fopen("butter.out","w");
    fscanf(fin,"%d%d%d",&n,&p,&c);
    int tmp;

    memset(num,0,sizeof(num));
    for(int i=1;i<=n;i++)
    {
        fscanf(fin,"%d",&tmp);
        num[tmp]++;
    }
    memset(st,-1,sizeof(st));
    int u,v,w;
    for(int i=1;i<=c;i++)
    {
        fscanf(fin,"%d%d%d",&u,&v,&w);
        edge[i].x=v;
        edge[i].value=w;
        edge[i].next=st[u];
        st[u]=i;

        edge[i+c].x=u;
        edge[i+c].value=w;
        edge[i+c].next=st[v];
        st[v]=i+c;
    }


    int ans=INF;
    for(int i=1;i<=p;i++)
    {
        int tmp=0;
        dijkstra(i);
        for(int j=1;j<=p;j++)
            tmp+=dis[j]*num[j];
        if (ans>tmp)
            ans=tmp;
    }

    fprintf(fout,"%d\n",ans);
    return 0;
}
