 /*
ID:perfect13
LANG:C++
TASK:fence9
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#define INF 0x7FFFFFFF
#define MAXN 105
using namespace std;

//皮克定理
//S=a+b÷2-1
//a表示多边形内部的点数
//b表示多边形边界上的点数
//s表示多边形的面积

int n,m,p;

int gcd(int x,int y)
{
    if (x>y) swap(x,y);
    if (x==0) return y;
    return gcd(y%x,x);
}


int main()
{
    FILE *fin=fopen("fence9.in","r");
    FILE *fout=fopen("fence9.out","w");
    fscanf(fin,"%d%d%d",&n,&m,&p);
    int s=(m*p)/2;
    int b=0;
    b+=gcd(n,m);
    b+=gcd(abs(n-p),m);
    b+=p;
    int ans=s+1-b/2;
    fprintf(fout,"%d\n",ans);
    return 0;
}
