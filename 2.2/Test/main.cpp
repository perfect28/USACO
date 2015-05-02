/*
ID:perfect13
LANG:C++
TASK:lamps
*/
#include<stdio.h>
#include<string.h>
#define max (1<<6)-1
FILE *fin=fopen("input.txt","r");
FILE *fout=fopen("lamps.out","w");
int f[1<<6],n,c,light,unlight;
int flip[4]={max,max&0xAA,max&0x55,max&((1<<(6-1))|(1<<(6-4)))};
void work(int res,int i,int n);
void print(int k);
int main()
{
    int i,ok,a;
    fscanf(fin,"%d%d",&n,&c);
    while(1)
    {
        fscanf(fin,"%d",&a);
        if (a==-1) break;
        a=5-(a-1)%6;
        light |=1<<a;
        unlight |=1<<a;
    }
    while(1)
    {
        fscanf(fin,"%d",&a);
        if (a==-1) break;
        a=5-(a-1)%6;
        unlight |=1<<a;
    }
    if (c>4)
        if (c%2==0) c=4;
        else c=3;
    for(;c>=0;c-=2)
        work(max,0,c);
    ok=0;
    for(i=0;i<(1<<6);i++)
        if (f[i])
        {
            print(i);
            ok=1;
        }
    if (!ok) fprintf(fout,"IMPOSSIBLE\n");
    return 0;
}

void work(int res,int i,int n)
{
    if (n==0)
    {
        if ((unlight&res)==light)
            f[res]=1;
        return ;
    }
    for(;i<4;i++)
        work(res ^flip[i],i+1,n-1);
}
void print(int k)
{
    int i;
    char s[101];
    for(i=0;i<n;i++)
        s[i]=(k&(1<<(5-i%6)))?'1':'0';
    s[n]='\0';
    fprintf(fout,"%s\n",s);
}
