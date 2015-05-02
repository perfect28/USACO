/*
ID:perfect13
LANG:C++
TASK:combo
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int n;
int farmer[5],master[5];

bool work(int a,int b,int c)
{
    int value[4]={0,a,b,c};
    int d[4];
    for(int i=1;i<=3;i++)
        d[i]=abs(farmer[i]-value[i]);

    bool ok=true;
    for(int i=1;i<=3;i++)
        if (!(d[i]<=2||d[i]>=(n-2))) ok=false;
    if (ok) return ok;

    for(int i=1;i<=3;i++)
        d[i]=abs(master[i]-value[i]);

    ok=true;
    for(int i=1;i<=3;i++)
        if (!(d[i]<=2||d[i]>=(n-2))) ok=false;

    return ok;
}

int main()
{
    FILE *fin=fopen("combo.in","r");
    FILE *fout=fopen("combo.out","w");
    fscanf(fin,"%d",&n);
    for(int i=1;i<=3;i++)
        fscanf(fin,"%d",&farmer[i]);
    for(int i=1;i<=3;i++)
        fscanf(fin,"%d",&master[i]);

    int ans=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
    {
        if (work(i,j,k))
            ans++;
    }

    fprintf(fout,"%d\n",ans);
    return 0;
}
