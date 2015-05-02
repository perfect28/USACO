/*
ID:perfect13
LANG:C++
TASK:dualpal
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char num[200];

void transfer(int k,int b)
{
    int cnt=0;
    while(k>0){
        num[cnt++]=k%b+'0';
        k=k/b;
    }
}

bool isPalSquare(char str[]){
    int len=strlen(str);
    for(int i=0;i<len/2;i++)
        if (str[i]==str[len-1-i]) continue;
        else return false;
    return true;
}

int main()
{
    FILE *fin=fopen("dualpal.in","r");
    FILE *fout=fopen("dualpal.out","w");
    int n,s,now,flag;
    fscanf(fin,"%d%d",&n,&s);
    while(n){
        now=++s;
        flag=0;
        for(int i=2;i<=10;i++){
            memset(num,0,sizeof(num));
            transfer(now,i);
            if(isPalSquare(num))
                flag++;
            if (flag>=2){
                n--;
                fprintf(fout,"%d\n",now);
                break;
            }
        }
    }
    return 0;
}
