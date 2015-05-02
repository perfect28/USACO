 /*
ID:perfect13
LANG:C++
TASK:kimbits
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#define INF 0x7FFFFFFF
#define MAXN 105000
using namespace std;

long long len,n,num;
int ans[40];
long long f[40][40];

int main()
{
    FILE *fin=fopen("kimbits.in","r");
    FILE *fout=fopen("kimbits.out","w");
    fscanf(fin,"%d%d%lld",&len,&n,&num);

    //f[i,j]:长度为i至多j个1的集合数
    //f[i,j]=f[i-1][j]+f[i-1][j-1];
    for(int j=0;j<=n;j++)
        f[0][j]=1;
    for(int i=0;i<=len;i++)
        f[i][0]=1;

    for(int i=1;i<=len;i++)
        for(int j=1;j<=n;j++)
        if (i>=j)
            f[i][j]=f[i-1][j-1]+f[i-1][j];
        else
            f[i][j]=f[i][i];

    int k=0;
    memset(ans,0,sizeof(ans));

    for(int i=len;i>=1;i--)
    {
        if (f[i-1][n]<num)
        {
            ans[++k]=1;
            num-=(f[i-1][n]);
            n--;
        }
        else{
            ans[++k]=0;
        }
    }

    for(int i=1;i<=len;i++)
        fprintf(fout,"%d",ans[i]);
    fprintf(fout,"\n");
    return 0;
}
