 /*
ID:perfect13
LANG:C++
TASK:stall4
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#define INF 0x7FFFFFFF
#define MAXN 250
using namespace std;

bool a[MAXN][MAXN];
int link[MAXN];
bool used[MAXN];
int n,m;

bool path(int x)
{
    for(int i=1;i<=m;i++)
        if (a[x][i]&&!used[i])
        {
            used[i]=true;
            if (!link[i]||(path(link[i])))
            {
                link[i]=x;
                return true;
            }
        }
    return false;
}

int main()
{
    FILE *fin=fopen("stall4.in","r");
    FILE *fout=fopen("stall4.out","w");
    fscanf(fin,"%d%d",&n,&m);
    int num,x;
    memset(a,false,sizeof(a));
    for(int i=1;i<=n;i++)
    {
        fscanf(fin,"%d",&num);
        for(int j=1;j<=num;j++)
        {
            fscanf(fin,"%d",&x);
            a[i][x]=true;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        memset(used,false,sizeof(used));
        if (path(i))
            ans++;
    }
    fprintf(fout,"%d\n",ans);
    return 0;
}
