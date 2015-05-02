/*
ID:perfect13
LANG:C++
TASK:cowtour
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define INF 999999
using namespace std;

typedef struct
{
    int x,y;
    int id;
}Node;

Node node[200];
double dist[200][200];
double maxn_dist[200];

double get_dist(int u,int v)
{
    Node a,b;
    a=node[u];
    b=node[v];
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int main()
{
    FILE *fin=fopen("cowtour.in","r");
    FILE *fout=fopen("cowtour.out","w");
    int n;
    fscanf(fin,"%d",&n);
    for(int i=1;i<=n;i++)
        fscanf(fin,"%d%d\n",&node[i].x,&node[i].y);

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        if (i!=j)
        dist[i][j]=INF;
    char c;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            fscanf(fin,"%c",&c);
            if (c=='1')
            {
                dist[i][j]=get_dist(i,j);
            }
        }
        fscanf(fin,"\n");
    }

    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            if (dist[i][k]+dist[k][j]<dist[i][j])
            dist[i][j]=dist[i][k]+dist[k][j];

    int num=0;
    for(int i=1;i<=n;i++)
    {
        if (!node[i].id)
        {
            node[i].id=++num;
            for(int j=1;j<=n;j++)
                if (dist[i][j]>0&&dist[i][j]!=INF)
                node[j].id=num;
        }
    }

    memset(maxn_dist,0,sizeof(maxn_dist));
    for(int k=1;k<=num;k++)
    {
        for(int i=1;i<=n;i++)
            if (node[i].id==k)
            {
                for(int j=1;j<=n;j++)
                {
                    if (dist[i][j]>0&&dist[i][j]!=INF)
                        if (dist[i][j]>maxn_dist[k])
                        maxn_dist[k]=dist[i][j];
                }
            }
    }

    double ans;
    double minn=INF;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(node[i].id!=node[j].id)
            {
                double maxn1=0,maxn2=0;
                for(int k=1;k<=n;k++)
                {
                    if (dist[i][k]>maxn1&&dist[i][k]!=INF)
                        maxn1=dist[i][k];
                    if (dist[j][k]>maxn2&&dist[j][k]!=INF)
                        maxn2=dist[j][k];
                }
                ans=maxn1+maxn2+get_dist(i,j);
                if (ans<maxn_dist[node[i].id])
                    ans=maxn_dist[node[i].id];
                if (ans<maxn_dist[node[j].id])
                    ans=maxn_dist[node[j].id];
                if (minn>ans)
                    minn=ans;
            }
    fprintf(fout,"%lf\n",minn);
    return 0;
}
