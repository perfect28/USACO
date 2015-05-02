/*
ID:perfect13
LANG:C++
TASK:milk2
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef struct {
    int st,ed;
}Line;
Line line[6000];

int cmp(Line u,Line v)
{
    if (u.st==v.st) return u.ed<v.ed;
    else return u.st<v.st;
}
int main()
{
    int n,st,ed;
    int max1,max2;
    FILE *fin=fopen("milk2.in","r");
    FILE *fout=fopen("milk2.out","w");
    fscanf(fin,"%d",&n);
    for(int i=1;i<=n;i++)
        fscanf(fin,"%d %d",&line[i].st,&line[i].ed);
    sort(line+1,line+1+n,cmp);
    st=line[1].st;
    ed=line[1].ed;
    max1=ed-st;
    max2=0;
    for(int i=2;i<=n;i++){
        if(line[i].st<=ed){
            if (ed<line[i].ed)
                ed=line[i].ed;
            if (max1<ed-st)
                max1=ed-st;
        }
        else if (line[i].st>ed){
            st=line[i].st;
            if (max2<st-ed)
                max2=st-ed;
            ed=line[i].ed;
        }
    }
    fprintf(fout,"%d %d\n",max1,max2);
    return 0;
}
