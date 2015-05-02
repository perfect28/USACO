/*
ID:perfect13
LANG:C++
TASK:zerosum
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n;
char ans[10];

FILE *fin=fopen("zerosum.in","r");
FILE *fout=fopen("zerosum.out","w");

void print()
{
    for(int i=1;i<n;i++)
        fprintf(fout,"%d%c",i,ans[i]);
    fprintf(fout,"%d\n",n);
}

void dfs(int k,int sum,int flag)
{
    if (k==n)
    {
        sum+=flag*k;
        if (sum==0)
            print();
        return;
    }

    for(char *s=" +-";*s;s++)
    {
        int tmp;
        if (*s==' '){
            if (flag==0) continue;
            ans[k]=' ';
            tmp=sum+flag*(10*k+k+1);
            dfs(k+1,tmp,0);
        }
        else if (*s=='+')
        {
            ans[k]='+';
            tmp=sum+flag*k;
            dfs(k+1,tmp,1);
        }
        else if (*s=='-')
        {
            ans[k]='-';
            tmp=sum+flag*k;
            dfs(k+1,tmp,-1);
        }
    }

}

int main()
{
    fscanf(fin,"%d",&n);
    dfs(1,0,1);
    return 0;
}
