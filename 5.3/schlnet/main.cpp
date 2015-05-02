/*
ID:perfect13
LANG:C++
TASK:schlnet
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

int dfn[MAXN],low[MAXN];
int a[MAXN][MAXN];
int nindex;
int cnt;
int top;
bool instack[MAXN];
int stap[MAXN];
int indegree[MAXN],outdegree[MAXN];
int mat[MAXN][MAXN];
int belong[MAXN];

void tarjan(int u)
{
    int i,v;
    dfn[u]=low[u]=++nindex;
    instack[u]=true;
    stap[++top]=u;
    for(i=1;i<=a[u][0];i++)
    {
        v=a[u][i];
        if (!dfn[v])
        {
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if (instack[v]){
            low[u]=min(low[u],dfn[v]);
        }
    }
    if (dfn[u]==low[u])
    {
        cnt++;
        do
        {
            i=stap[top--];
            instack[i]=false;
            belong[i]=cnt;
        }
        while(i!=u);
    }
}
int main()
{
    FILE *fin=fopen("schlnet.in","r");
    FILE *fout=fopen("schlnet.out","w");
    int n;
    fscanf(fin,"%d",&n);
    memset(a,0,sizeof(a));
    for(int i=1;i<=n;i++)
    {
        int num=0,tmp;
        while(fscanf(fin,"%d",&tmp)&&tmp)
            a[i][++num]=tmp;
        a[i][0]=num;
    }

    top=0;
    cnt=0;
    nindex=0;
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    memset(belong,0,sizeof(belong));
    memset(instack,false,sizeof(instack));


    for(int i=1;i<=n;i++)
    {
        if (!dfn[i])
            tarjan(i);
    }

    memset(indegree,0,sizeof(indegree));
    memset(outdegree,0,sizeof(outdegree));
    memset(mat,0,sizeof(mat));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=a[i][0];j++)
    {
        int x=a[i][j];
        int u=belong[i];
        int v=belong[x];
        if (u!=v)
        {
            if (!mat[u][v])
            {
                mat[u][v]=1;
                indegree[v]++;
                outdegree[u]++;
            }
        }
    }

    int in_num=0,out_num=0;
    for(int i=1;i<=cnt;i++)
    {
        if (!indegree[i])
            in_num++;
        if (!outdegree[i])
            out_num++;
    }

    int a_ans=in_num;
    int b_ans;
    if (cnt==1)
        b_ans=0;
    else
        b_ans=in_num>out_num?in_num:out_num;

    fprintf(fout,"%d\n",a_ans);
    fprintf(fout,"%d\n",b_ans);
    return 0;
}
