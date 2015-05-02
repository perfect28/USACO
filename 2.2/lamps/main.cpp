/*
ID:perfect13
LANG:C++
TASK:lamps
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int light,unlight;

int bt[4]={0b111111,
           0b101010,
           0b010101,
           0b100100};
int n,c;

bool vis[4];

FILE *fin=fopen("lamps.in","r");
FILE *fout=fopen("lamps.out","w");

void print(int num)
{
    int ans[6];
    int cnt=5;
    while(cnt>=0)
    {
        ans[cnt]=num%2;
        num=num/2;
        cnt--;
    }
    for(int i=1;i<=n;i++)
        fprintf(fout,"%d",ans[(i-1)%6]);
    fprintf(fout,"\n");
}

bool flag[1000];

void dfs(int k,int status)
{
    if (k>c)
    {
        if ((unlight&status)==light)
            flag[status]=true;
        return;
    }
    for(int i=0;i<4;i++)
        if (!vis[i])
    {
        vis[i]=true;
        dfs(k+1,status^bt[i]);
        vis[i]=false;
    }
}

int main()
{
    int x;
    fscanf(fin,"%d%d",&n,&c);
    while(fscanf(fin,"%d",&x)&&x!=-1){
        int tmp=1<<(5-(x-1)%6);
        light=light|tmp;
        unlight=unlight|tmp;
    }
    while(fscanf(fin,"%d",&x)&&x!=-1){
        int tmp=1<<(5-(x-1)%6);
        unlight=unlight|tmp;
    }


    int now=0b111111;

    if (c>4)
        if (c%2==0) c=4;
        else c=3;

    for(;c>=0;c-=2)
    {
        memset(vis,false,sizeof(vis));
        dfs(1,now);
    }

    bool ok=false;
    for(int i=0;i<=(1<<6)-1;i++)
        if (flag[i])
        {
            print(i);
            ok=true;
        }

    if (!ok) fprintf(fout,"IMPOSSIBLE\n");
    return 0;
}
