/*
ID:perfect13
LANG:C++
TASK:theme
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <fstream>
#define INF 0x7FFFFFFF
#define MAXN 10050
using namespace std;

int num[MAXN];
int delta[MAXN];
int n;
int next[MAXN];
int maxn=0;

int main()
{
    FILE *fin=fopen("theme.in","r");
    FILE *fout=fopen("theme.out","w");
    //ofstream out("test.txt");

    int n;
    fscanf(fin,"%d",&n);
    fscanf(fin,"%d",&num[0]);
    for(int i=1;i<n;i++)
    {
        fscanf(fin,"%d",&num[i]);
        delta[i]=num[i]-num[i-1];
    }
    n--;

    int len=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+2+len;j<=n;j++)
        {
            int k;
            maxn=j-i-1;
            if (n-j<len)
                break;
            for(k=0;k<maxn&&j+k<=n;k++)
                if (delta[i+k]==delta[j+k])
                    continue;
                else
                    break;
            if (k>=4&&len<k)
                len=k;
        }
    }

    int ans;
    if (len<4) ans=0;
    else ans=len+1;
    fprintf(fout,"%d\n",ans);
    return 0;
}
