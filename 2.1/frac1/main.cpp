/*
ID:perfect13
LANG:C++
TASK:frac1
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

typedef struct
{
    int u,v;
}Fraction;
Fraction ans[40000];

int gcd(int a,int b)
{
    int r;
    while(b>0)
    {
         r=a%b;
         a=b;
         b=r;
    }
    return a;
}

int cmp(Fraction a,Fraction b)
{
    return a.u*b.v<a.v*b.u;
}
int main()
{
    FILE *fin=fopen("frac1.in","r");
    FILE *fout=fopen("frac1.out","w");
    int n;
    fscanf(fin,"%d",&n);
    int num=0;
    for(int i=0;i<=n;i++)
        for(int j=1;j<=n;j++)
        if (i<=j)
        {
            if(gcd(j,i)==1){
                num++;
                ans[num].u=i;
                ans[num].v=j;
            }
        }
    sort(ans+1,ans+1+num,cmp);
    for(int i=1;i<=num;i++)
        fprintf(fout,"%d/%d\n",ans[i].u,ans[i].v);
    return 0;
}
