/*
ID:perfect13
LANG:C++
TASK:prefix
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 30
using namespace std;

char words[300][20];
char str[250000];
bool flag[250000];
char tmp[100];

int main()
{
    FILE *fin=fopen("prefix.in","r");
    FILE *fout=fopen("prefix.out","w");
    int num=0;
    while(1)
    {
        fscanf(fin,"%s",words[++num]);
        if (words[num][0]=='.') break;
    }
    while(fscanf(fin,"%s",tmp)!=EOF)
    {
        strcat(str,tmp);
    }
    int len=strlen(str);
    memset(flag,false,sizeof(flag));
    int maxn=0;
    for(int i=0;i<len;i++)
    {
        for(int j=1;j<=num;j++)
        if (i==0||flag[i-1])
        if (str[i]==words[j][0])
        {
            int k;
            int l=strlen(words[j]);
            for(k=1;k<l;k++)
                if (str[i+k]!=words[j][k]) break;
            if (k>=l)
            {
                int ed=i+l-1;
                flag[ed]=true;
                if (flag[ed]&&ed+1>maxn) maxn=ed+1;
            }
        }
    }
    fprintf(fout,"%d\n",maxn);
    return 0;
}
