 /*
ID:perfect13
LANG:C++
TASK:humble
*/
#include <iostream>
#include <cstdio>
#define INF 0x7FFFFFFF
#define MAXN 105000
using namespace std;

int num[150];
int flag[150];
int k,n;
int hum[MAXN];

int main()
{
    FILE *fin=fopen("humble.in","r");
    FILE *fout=fopen("humble.out","w");
    fscanf(fin,"%d%d",&k,&n);
    for(int i=1;i<=k;i++)
    {
        fscanf(fin,"%d",&num[i]);
        flag[i]=1;
    }

    int cnt=0;
    hum[++cnt]=1;
    while(cnt!=n+1)
    {
        int minn=INF;
        for(int i=1;i<=k;i++)
        {
            while(num[i]*hum[flag[i]]<=hum[cnt])
                flag[i]++;
            if (minn>num[i]*hum[flag[i]])
                minn=num[i]*hum[flag[i]];
        }
        hum[++cnt]=minn;
    }
    fprintf(fout,"%d\n",hum[cnt]);
    return 0;
}
