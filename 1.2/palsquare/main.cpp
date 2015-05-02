/*
ID:perfect13
LANG:C++
TASK:palsquare
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char num[20],ans[20];
int b;

void transfer(int k)
{
    int cnt=0;
    while(k>0){
        if (k%b<10)
            num[cnt++]=k%b+'0';
        else{
            num[cnt++]=k%b-10+'A';
        }
        k=k/b;
    }
}

bool isPalSquare(char s[]){
    int len=strlen(s);
    for(int i=0;i<len/2;i++)
        if (s[i]==s[len-1-i]) continue;
        else return false;
    return true;
}
int main()
{
    FILE *fin=fopen("palsquare.in","r");
    FILE *fout=fopen("palsquare.out","w");

    fscanf(fin,"%d",&b);

    for(int i=1;i<=300;i++)
    {
        transfer(i*i);
        if (isPalSquare(num))
        {
            strcpy(ans,num);
            memset(num,0,sizeof(num));
            transfer(i);
            for(int j=strlen(num)-1;j>=0;j--)
                fprintf(fout,"%c",num[j]);
            fprintf(fout," %s\n",ans);
        }
    }
    return 0;
}
