/*
ID:perfect13
LANG:C++
TASK:bigbrn
*/
#include <cstdio>
#include <cstring>
#define MAXN 1050
#define INF 0x7fffffff
using namespace std;

int n,t;
int mat[MAXN][MAXN];
int f[MAXN][MAXN];
int ans;

int min(int u,int v,int t)
{
    int tmp=INF;
    if (tmp>u) tmp=u;
    if (tmp>v) tmp=v;
    if (tmp>t) tmp=t;
    return tmp;
}
int main()
{
    FILE *fin=fopen("bigbrn.in","r");
    FILE *fout=fopen("bigbrn.out","w");
    fscanf(fin,"%d%d",&n,&t);
    memset(mat,0,sizeof(mat));
    int x,y;
    for(int i=1;i<=t;i++)
    {
        fscanf(fin,"%d%d",&x,&y);
        mat[x][y]=1;
    }
    memset(f,0,sizeof(f));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        if (!mat[i][j])
        f[i][j]=1;
    ans=0;
    for(int i=1;i<=n;i++)
        for(int l=2*1;l<=2*n;l++)
    {
        int j=l-i;
        if (j<=0||j>n)
            continue;
        if (mat[i][j])
            continue;
        int minn=min(f[i-1][j-1],f[i-1][j],f[i][j-1]);
        f[i][j]=minn+1;
        if (ans<f[i][j])
            ans=f[i][j];
    }
    fprintf(fout,"%d\n",ans);
    return 0;
}
