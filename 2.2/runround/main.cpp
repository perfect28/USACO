/*
ID:perfect13
LANG:C++
TASK:runround
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 30
using namespace std;

bool flag[MAXN];

bool check(char str[])
{
    int len=strlen(str);
    for(int i=0;i<len;i++)
    {
        int cnt=len;
        int st=i;
        memset(flag,false,sizeof(flag));
        int pos=i;
        int value;
        flag[pos]=true;
        while(cnt){
            cnt--;
            value=str[pos]-'0';
            pos=(pos+value)%len;
            if (flag[pos]) break;
            else{
                flag[pos]=true;
            }
        }
        if (cnt==0&&pos==st)
            return true;
    }
    return false;
}

bool no_same_num(int k)
{
    bool f[10];
    memset(f,false,sizeof(f));
    while(k)
    {
        int now=k%10;
        if (!f[now])
            f[now]=true;
        else return false;
        k=k/10;
    }
    return true;
}

int main()
{
    FILE *fin=fopen("runround.in","r");
    FILE *fout=fopen("runround.out","w");
    int m;
    char str[MAXN];
    fscanf(fin,"%d",&m);
    for(int i=m+1;;i++)
        if (no_same_num(i))
    {
        sprintf(str,"%d",i);
        if (check(str))
        {
            fprintf(fout,"%d\n",i);
            break;
        }
    }
    return 0;
}
