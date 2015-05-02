 /*
ID:perfect13
LANG:C++
TASK:job
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 0x7FFFFFFF
#define MAXN 105
using namespace std;

int a[40],b[40];
int cost_a[40],cost_b[40];
int min_a[1050],min_b[1050];
int n,m1,m2;

int main()
{
    FILE *fin=fopen("job.in","r");
    FILE *fout=fopen("job.out","w");
    fscanf(fin,"%d%d%d",&n,&m1,&m2);
    for(int i=1;i<=m1;i++)
        fscanf(fin,"%d",&a[i]);
    sort(a+1,a+1+m1);
    for(int i=1;i<=m2;i++)
        fscanf(fin,"%d",&b[i]);
    sort(b+1,b+1+m2);

    int time_a=0,time_b=0;

    for(int i=1;i<=n;i++)
    {
        int minn=INF,k;
        for(int j=1;j<=m1;j++)
        {
            if (minn>cost_a[j]+a[j])
            {
                minn=cost_a[j]+a[j];
                k=j;
            }
        }
        cost_a[k]+=a[k];
        if (time_a<cost_a[k])
            time_a=cost_a[k];
        min_a[i]=cost_a[k];
    }

    for(int i=1;i<=n;i++)
    {
        int minn=INF,k;
        for(int j=1;j<=m2;j++)
        {
            if (minn>cost_b[j]+b[j])
            {
                minn=cost_b[j]+b[j];
                k=j;
            }
        }
        cost_b[k]+=b[k];
        min_b[i]=cost_b[k];
    }


    for(int i=1;i<=n;i++)
    {
        if (time_b<min_a[i]+min_b[n+1-i])
            time_b=min_a[i]+min_b[n+1-i];
    }

    fprintf(fout,"%d %d\n",time_a,time_b);
    return 0;
}
