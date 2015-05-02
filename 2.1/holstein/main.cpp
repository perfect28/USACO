/*
ID:perfect13
LANG:C++
TASK:holstein
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#define INF 100
using namespace std;

int n,m;
int sum[30];
int vitamins[20][30];
bool flag[20];

int p,minn;
int ans[30];

bool satisfy(int now[])
{
    for(int i=1;i<=n;i++)
        if (now[i]<sum[i]) return false;
    return true;
}

void dfs(int k,int now[])
{
    if (satisfy(now)){
        if (minn>p){
            int num=0;
            for(int i=1;i<=m;i++)
                if (flag[i])
                ans[++num]=i;
            minn=p;
            return;
        }
    }
    if (k>m) return;
    if (!flag[k])
    {
        p++;
        flag[k]=true;
        for(int j=1;j<=n;j++)
            now[j]+=vitamins[k][j];
        dfs(k+1,now);
        p--;
        flag[k]=false;
        for(int j=1;j<=n;j++)
            now[j]-=vitamins[k][j];
    }
    if (k<=m) dfs(k+1,now);
}

int main()
{
    FILE *fin=fopen("holstein.in","r");
    FILE *fout=fopen("holstein.out","w");

    fscanf(fin,"%d",&n);
    for(int i=1;i<=n;i++)
        fscanf(fin,"%d",&sum[i]);
    fscanf(fin,"%d",&m);
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
        fscanf(fin,"%d",&vitamins[i][j]);
    int now[30];
    memset(now,0,sizeof(now));
    memset(flag,false,sizeof(flag));
    minn=INF;
    dfs(1,now);
    fprintf(fout,"%d",minn);
    for(int i=1;i<=minn;i++)
        fprintf(fout," %d",ans[i]);
    fprintf(fout,"\n");
    return 0;
}
