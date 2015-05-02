/*
ID:perfect13
LANG:C++
TASK:hamming
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,b,d;
int ans[100];

bool satisfy(int u,int v)
{
    int num=b;
    int cnt=0;
    while(num){
        if (u%2!=v%2) cnt++;
        if (cnt>=d) return true;
        u/=2;
        v/=2;
        num--;
    }
    return false;
}

int main()
{
    FILE *fin=fopen("hamming.in","r");
    FILE *fout=fopen("hamming.out","w");
    fscanf(fin,"%d%d%d",&n,&b,&d);
    int i;
    int cnt=1;
    int test=0;
    ans[cnt]=test;
    while(cnt<n){
        test++;
        for(i=1;i<=cnt;i++)
            if (satisfy(test,ans[i])) continue;
            else break;
        if (i>cnt)
            ans[++cnt]=test;
    }
    for(int i=1;i<cnt;i++)
    if (i%10==0)
        fprintf(fout,"%d\n",ans[i]);
    else
        fprintf(fout,"%d ",ans[i]);
    fprintf(fout,"%d\n",ans[cnt]);
    return 0;
}
