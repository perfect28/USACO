 /*
ID:perfect13
LANG:C++
TASK:nuggets
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#define INF 0x7FFFFFFF
#define MAXN 10000000
using namespace std;

int gcd(int x,int y)
{
    if (x>y) swap(x,y);
    if (x==0) return y;
    return gcd(y%x,x);
}

/*
��������p,q,��gcd(q,p)=1,
������޷���ʾ��px+qy��x>=0,y>=0)������pq-q-p
������n>pq-q-p,�����Ա�ʾ��px+qy����pq-q-p,���޷���ʾ��px+qy����
������Խ�࣬���ֵֻ��ԽС��
*/

bool flag[MAXN];
int num[20];

int main()
{
    FILE *fin=fopen("nuggets.in","r");
    FILE *fout=fopen("nuggets.out","w");
    int n;
    fscanf(fin,"%d",&n);
    memset(flag,false,sizeof(flag));
    flag[0]=true;
    for(int i=1;i<=n;i++)
        fscanf(fin,"%d",&num[i]);
    int ans=0;
    int cnt=0;
    for(int i=1;i<MAXN;i++)
    {
        for(int j=1;j<=n;j++)
        if (i>=num[j]&&flag[i-num[j]])
            flag[i]=true;
        if (flag[i])
        {
            cnt++;
            if (cnt>=256)
                break;
        }
        else{
            cnt=0;
            ans=i;
        }
    }
    if (ans==MAXN-1) ans=0;
    fprintf(fout,"%d\n",ans);
    return 0;
}
