/*
ID:perfect13
LANG:C++
TASK:preface
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char *num[4][10]={{"","I","II","III","IV","V","VI","VII","VIII","IX"},
                  {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
                  {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
                  {"","M","MM","MMM","","","","","",""}};

int count[128];

char* work(int k)
{
    char ans[30];
    int tmp[30];
    int cnt=0;
    memset(ans,0,sizeof(ans));
    memset(tmp,0,sizeof(tmp));
    while(k)
    {
        tmp[++cnt]=k%10;
        k=k/10;
    }
    for(int i=cnt;i>=1;i--)
        strcat(ans,num[i-1][tmp[i]]);
    //printf("%s\n",ans);
    return ans;
}

int main()
{
    FILE *fin=fopen("preface.in","r");
    FILE *fout=fopen("preface.out","w");
    int n;
    fscanf(fin,"%d",&n);
    char *s;
    for(int i=1;i<=n;i++)
        for(s=work(i);*s;s++)
            count[*s]++;
    for(s="IVXLCDM";*s;s++)
        if (count[*s])
        fprintf(fout,"%c %d\n",*s,count[*s]);
    return 0;
}
