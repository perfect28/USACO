/*
ID:perfect13
LANG:C++
TASK:milk
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef struct{
    int value,amount;
}Farmer;
Farmer farmer[5050];

int cmp(Farmer u,Farmer v){
    return u.value<v.value;
}
int main()
{
    FILE *fin=fopen("milk.in","r");
    FILE *fout=fopen("milk.out","w");
    int n,m;
    fscanf(fin,"%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        fscanf(fin,"%d%d",&farmer[i].value,&farmer[i].amount);
    }
    sort(farmer+1,farmer+1+m,cmp);
    int now=1;
    int ans=0;
    while(n>0){
        if (n>farmer[now].amount){
            n-=farmer[now].amount;
            ans+=farmer[now].amount*farmer[now].value;
            now++;
        }
        else{
            ans+=n*farmer[now].value;
            n=0;
        }
    }
    fprintf(fout,"%d\n",ans);
    return 0;
}
