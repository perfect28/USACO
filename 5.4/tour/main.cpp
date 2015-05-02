/*
ID:perfect13
LANG:C++
TASK:tour
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <map>
#define INF 0x7FFFFFFF
#define MAXN 150
using namespace std;

map < string,int > city;
int mat[MAXN][MAXN];
int f[MAXN][MAXN];
//bool flag[MAXN][MAXN];
int ans;
int n,v;

//bool flag[MAXN];
//bool arrive;
/*
void dfs(int k,int s)
{
    if (arrive&&s==1)
        if (ans<k-1)
            ans=k-1;
    if (!arrive)
    {
        for(int i=s+1;i<=n;i++)
        if ((mat[s][i]&&!flag[i])||(mat[s][i]&&i==1))
        {
            if (i==n)
                arrive=true;
            flag[i]=true;
            dfs(k+1,i);
            if (i==n)
                arrive=false;
            flag[i]=false;
        }
    }
    else
    {
        for(int i=s-1;i>=1;i--)
        if ((mat[s][i]&&!flag[i])||(mat[s][i]&&i==1))
        {
            if (i==n)
                arrive=true;
            flag[i]=true;
            dfs(k+1,i);
            if (i==n)
                arrive=false;
            flag[i]=false;
        }
    }
}
*/

/*
DP方法：f[i][j]，A、B一起出发，A走到i，B走到j的总数
f[1][1]=1;
f[i][j]=f[i][k]+1;(k,j)有路可走并且f[i][k]>0
f[j][i]=f[i][j];
最终结果:f[i][n]中的最大值,(i,n)有路可走；
*/

int main()
{
    ifstream fin("tour.in");
    ofstream fout("tour.out");
    string uname,vname;
    fin>>n>>v;
    for(int i=1;i<=n;i++)
    {
        fin>>uname;
        city[uname]=i;
    }
    for(int i=1;i<=v;i++)
    {
        fin>>uname>>vname;
        mat[city[uname]][city[vname]]=1;
        mat[city[vname]][city[uname]]=1;
    }

    f[1][1]=1;
    //memset(flag,false,sizeof(flag));
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
        {
            for(int k=1;k<j;k++)
                if (mat[k][j]&&f[i][k])
                {
                    f[i][j]=max(f[i][j],f[i][k]+1);
                    f[j][i]=f[i][j];
                }
        }

    for(int i=1;i<=n;i++)
        if (mat[i][n]&&ans<f[i][n])
            ans=f[i][n];

    //arrive=false;
    //dfs(1,1);

    if (ans==0)
        ans=1;
    fout<<ans<<endl;
    /*
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        if (mat[i][j])
            printf("#");
        else
            printf(".");
        printf("\n");
    }
    */
    return 0;
}
