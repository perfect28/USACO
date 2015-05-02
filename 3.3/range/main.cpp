/*
ID:perfect13
LANG:C++
TASK:range
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 251
using namespace std;

int ans[MAXN][MAXN];
char matrix[MAXN][MAXN];
int cnt[MAXN];

int min(int a,int b,int c)
{
    int tmp=a;
    if (tmp>b) tmp=b;
    if (tmp>c) tmp=c;
    return tmp;
}

int main()
{
    FILE *fin=fopen("range.in","r");
    FILE *fout=fopen("range.out","w");
    int n;
    fscanf(fin,"%d",&n);
    for(int i=0;i<n;i++)
        fscanf(fin,"%s",matrix[i]);

    memset(ans,0,sizeof(ans));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            if (matrix[i][j]=='1')
                ans[i][j]=1;
        }


    memset(cnt,0,sizeof(cnt));
    //ans[i+1][j+1]=min{ans[i][j],ans[i][j+1],ans[i+1][j]}+1;

    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-1;j++)
            if (ans[i+1][j+1])
        {
            ans[i+1][j+1]=min(ans[i][j],ans[i][j+1],ans[i+1][j])+1;
            for(int k=2;k<=ans[i+1][j+1];k++)
                cnt[k]++;
        }

    int now=2;
    while(cnt[now])
    {
        fprintf(fout,"%d %d\n",now,cnt[now]);
        now++;
    }
    return 0;
}
