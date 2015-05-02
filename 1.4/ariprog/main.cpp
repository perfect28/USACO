/*
ID:perfect13
LANG:C++
TASK:ariprog
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAXN 150000
using namespace std;

bool isDouble[MAXN];
int dNum[MAXN];
typedef struct{
    int a,b;
}Ans;
Ans ans[10*MAXN];
int cmp(Ans u,Ans v)
{
    if (u.b==v.b) return u.a<v.a;
    else return u.b<v.b;
}
int main()
{
    FILE *fin=fopen("ariprog.in","r");
    FILE *fout=fopen("ariprog.out","w");
    int n,m;
    int a,b;
    fscanf(fin,"%d%d",&n,&m);
    memset(isDouble,false,sizeof(isDouble));
    for(int i=0;i<=m;i++)
        for(int j=0;j<=m;j++)
            isDouble[i*i+j*j]=true;
    int num=0;
    int maxn=m*m*2;
    for(int i=0;i<=maxn;i++)
            if (isDouble[i])
                dNum[++num]=i;
    int t=0;
    for(int i=1;i<num;i++)
    {
        for(int j=i+1;j<num;j++)

        {
            int k;
            a=dNum[i];
            b=dNum[j]-dNum[i];
            if (a+(n-1)*b>maxn) break;
            for(k=1;k<n;k++)
                if (!isDouble[a+k*b])
                    break;
            if(k>=n)
            {
                t++;
                ans[t].a=a;
                ans[t].b=b;
            }
        }
    }
    sort(ans+1,ans+1+t,cmp);
    for(int i=1;i<=t;i++)
        fprintf(fout,"%d %d\n",ans[i].a,ans[i].b);
    if (!t) fprintf(fout,"NONE\n");
    return 0;
}
