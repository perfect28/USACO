#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 1050
using namespace std;

int a,b;
int lx[MAXN],ly[MAXN],rx[MAXN],ry[MAXN];
int area[MAXN],color[MAXN];
int n;

void cover(int l,int r,int b,int t,int k,int c)
{
    while(k<=n+1&&(l>rx[k]||r<lx[k]||b>ry[k]||t<ly[k]))
        k++;
    if (k>n+1)
    {
        area[c]+=(r-l)*(t-b);
        return;
    }
    if (l<lx[k])
    {
        cover(l,lx[k],b,t,k+1,c);
        l=lx[k];
    }
    if (r>rx[k])
    {
        cover(rx[k],r,b,t,k+1,c);
        r=rx[k];
    }
    if (b<ly[k])
    {
        cover(l,r,b,ly[k],k+1,c);
        b=ly[k];
    }
    if (t>ry[k])
    {
        cover(l,r,ry[k],t,k+1,c);
        t=ry[k];
    }
}
int main()
{
    FILE *fin=fopen("rect1.in","r");
    FILE *fout=fopen("rect1.out","w");
    fscanf(fin,"%d%d%d",&a,&b,&n);
    for(int i=2;i<=n+1;i++)
        fscanf(fin,"%d%d%d%d%d",&lx[i],&ly[i],&rx[i],&ry[i],&color[i]);

    lx[1]=0;ly[1]=0;
    rx[1]=a;ry[1]=b;
    color[1]=1;

    memset(area,0,sizeof(area));
    for(int i=1;i<=n+1;i++)
        cover(lx[i],rx[i],ly[i],ry[i],i+1,color[i]);

    for(int i=1;i<=n+1;i++)
        if (area[i])
        printf("%d %d\n",i,area[i]);
    return 0;
}
