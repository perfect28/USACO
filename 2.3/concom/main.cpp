/*
ID:perfect13
LANG:C++
TASK:concom
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int per[200][200];
bool ans[200][200];


void add_owner(int i,int j)
{
    if (ans[i][j]) return;
    ans[i][j]=true;


    //当i能控j时
    //1.i能占j控的比例
    //2.能控i的直接能控j


    for(int k=1;k<=100;k++)
    {
        per[i][k]+=per[j][k];
        if (per[i][k]>50)
            add_owner(i,k);
    }

    for(int k=1;k<=100;k++)
    if (ans[k][i])
        add_owner(k,j);
}
int main()
{
    FILE *fin=fopen("concom.in","r");
    FILE *fout=fopen("concom.out","w");
    int n;
    memset(ans,false,sizeof(ans));
    fscanf(fin,"%d",&n);

    for(int k=1;k<=n;k++)
    {
        int i,j;
        fscanf(fin,"%d%d",&i,&j);
        fscanf(fin,"%d",&per[i][j]);

        for(int t=1;t<=100;t++)
        if (ans[t][i]){
            per[t][j]+=per[i][j];
        }

        for(int t=1;t<=100;t++)
        if (per[t][j]>50)
            add_owner(t,j);
    }

    for(int i=1;i<=100;i++)
        for(int j=1;j<=100;j++)
            if (ans[i][j]&&i!=j)
            fprintf(fout,"%d %d\n",i,j);
    return 0;
}
