/*
ID:perfect13
LANG:C++
TASK:money
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

long long ans[10500];
int num[30];

int main()
{
    FILE *fin=fopen("money.in","r");
    FILE *fout=fopen("money.out","w");
    int v,n;
    fscanf(fin,"%d%d",&v,&n);
    for(int i=1;i<=v;i++)
        fscanf(fin,"%d",&num[i]);
    ans[0]=1;
    for(int j=1;j<=v;j++)
        for(int i=1;i<=n;i++)
        {
            if (i>=num[j])
            {
                ans[i]+=ans[i-num[j]];
            }
        }
    fprintf(fout,"%lld\n",ans[n]);
    return 0;
}
