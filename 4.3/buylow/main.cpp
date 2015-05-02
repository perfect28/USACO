 /*
ID:perfect13
LANG:C++
TASK:buylow
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#define INF 0x7FFFFFFF
#define MAXN 5050
using namespace std;

long stock[MAXN];
long tmp[MAXN];
long flag[MAXN];

int dp[MAXN];

struct BigNum
{
    int num[100];
    int len;
};

BigNum Add(BigNum &a,BigNum &b)
{
    BigNum c;
    int i,len;
    len=(a.len>b.len)?a.len:b.len;
    memset(c.num,0,sizeof(c.num));
    for(i=0;i<len;i++)
    {
        c.num[i]+=(a.num[i]+b.num[i]);
        if (c.num[i]>=10)
        {
            c.num[i+1]++;
            c.num[i]-=10;
        }
    }
    if (c.num[len]) len++;
    c.len=len;
    return c;
}



int main()
{
    FILE *fin=fopen("buylow.in","r");
    FILE *fout=fopen("buylow.out","w");
    int n;
    BigNum cnt[MAXN];
    fscanf(fin,"%d",&n);
    for(int i=1;i<=n;i++)
        fscanf(fin,"%ld",&stock[i]);
    stock[n+1]=0;
    memset(cnt,0,sizeof(cnt));
    for(int i=1;i<=n+1;i++)
    {
        dp[i]=1;
        cnt[i].len=1;
    }


    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
            if (stock[i]==stock[j])
            {
                flag[i]=j;
                break;
            }
    }


    for(int i=2;i<=n+1;i++)
    {
        int maxn=0;
        for(int j=1;j<i;j++)
            if (stock[i]<stock[j])
            {
                if (maxn<dp[j]+1)
                    maxn=dp[j]+1;
            }
        if (maxn) dp[i]=maxn;
    }

    for(int i=2;i<=n+1;i++)
    {
        for(int j=1;j<i;j++)
        if (flag[j]==0||flag[j]>i)
            if (dp[i]==dp[j]+1&&stock[i]<stock[j])
            {
                if (cnt[j].len==1&&cnt[j].num[0]==0)
                    cnt[i].num[0]++;
                else cnt[i]=Add(cnt[i],cnt[j]);
            }
    }

    fprintf(fout,"%d ",dp[n+1]-1);

    for(int i=cnt[n+1].len-1;i>=0;i--)
        fprintf(fout,"%d",cnt[n+1].num[i]);
    fprintf(fout,"\n");
    return 0;
}
