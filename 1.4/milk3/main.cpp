/*
ID:perfect13
LANG:C++
TASK:milk3
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef struct{
    int x[4];
}Node;

Node q[1000];
bool status[30][30][30];
bool flag[30];
void bfs(int a,int b,int c)
{
    int h=0,t=1;
    int d[4];
    d[1]=a;d[2]=b;d[3]=c;
    memset(q,0,sizeof(q));
    memset(status,false,sizeof(status));
    q[1].x[1]=0;
    q[1].x[2]=0;
    q[1].x[3]=c;
    status[0][0][c]=true;
    while(h<t){
        h++;
        for(int i=1;i<=3;i++){
            if (q[h].x[i]>0)
            for(int j=1;j<=3;j++)
            if (i!=j)
            {
                t++;
                q[t]=q[h];
                if (q[t].x[i]+q[t].x[j]>d[j]){
                    q[t].x[i]=q[t].x[i]-(d[j]-q[t].x[j]);
                    q[t].x[j]=d[j];

                }
                else{
                    q[t].x[j]=q[t].x[i]+q[t].x[j];
                    q[t].x[i]=0;
                }

                if (!status[q[t].x[1]][q[t].x[2]][q[t].x[3]]){
                    status[q[t].x[1]][q[t].x[2]][q[t].x[3]]=true;
                }
                else t--;

                if (q[t].x[1]==0)
                    flag[q[t].x[3]]=true;
            }
        }
    }
}
int main()
{
    FILE *fin=fopen("milk3.in","r");
    FILE *fout=fopen("milk3.out","w");
    int a,b,c;
    fscanf(fin,"%d%d%d",&a,&b,&c);
    memset(flag,false,sizeof(flag));
    flag[c]=true;
    bfs(a,b,c);
    int ok=1;
    for(int i=0;i<=20;i++)
        if (flag[i])
        if (ok){
            fprintf(fout,"%d",i);
            ok=0;
        }
        else
            fprintf(fout," %d",i);
    fprintf(fout,"\n");
    return 0;
}
