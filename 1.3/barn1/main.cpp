/*
ID:perfect13
LANG:C++
TASK:barn1
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int stall_number[300],dist[300];
int cmp(int u,int v){
    return u>v;
}
int main()
{
    FILE *fin=fopen("barn1.in","r");
    FILE *fout=fopen("barn1.out","w");
    int m,s,c;
    int st,ed;
    int ans;
    fscanf(fin,"%d%d%d",&m,&s,&c);
    for(int i=1;i<=c;i++)
         fscanf(fin,"%d",&stall_number[i]);
    sort(stall_number+1,stall_number+1+c,cmp);
    for(int i=1;i<c;i++)
        dist[i]=stall_number[i]-stall_number[i+1]-1;
    st=stall_number[c];
    ed=stall_number[1];
    sort(dist+1,dist+c,cmp);
    ans=ed+1-st;
    for(int i=1;i<m;i++)
        ans-=dist[i];
    fprintf(fout,"%d\n",ans);
    return 0;
}
