/*
ID:perfect13
LANG:C++
TASK:snail
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <fstream>
#define INF 0x7FFFFFFF
#define MAXN 150
using namespace std;

int matrix[MAXN][MAXN];
bool flag[MAXN][MAXN];
int n,b;
struct Node{
    int x,y;
    int dir;
    int cnt;
};
int ans;

void dfs(Node now,int last_dir)
{
    Node son;
    int d1[4]={-1,0,1,0},
        d2[4]={0,1,0,-1};
    int i,j;
    for(int k=0;k<=3;k++)
    {
        if ((k+2)%4==last_dir||k==last_dir) continue;
        now.dir=k;
        son.x=now.x+d1[k];
        son.y=now.y+d2[k];
        while (son.x>=1&&son.x<=n&&son.y>=1&&son.y<=n
             &&!flag[son.x][son.y]&&matrix[son.x][son.y]!=1)
        {
            son.x+=d1[k];
            son.y+=d2[k];
        }
        if (son.x==now.x+d1[k]&&son.y==now.y+d2[k])//此方向不通
            continue;
        son.x-=d1[k];
        son.y-=d2[k];
        son.cnt=now.cnt+abs(son.x-now.x)+abs(son.y-now.y);

        if (flag[son.x+d1[k]][son.y+d2[k]])//如果撞到了自己走过的路，结束
        {
            if (ans<son.cnt)
                ans=son.cnt;
            continue;
        }
        i=now.x+d1[k];
        j=now.y+d2[k];
        while(i!=son.x+d1[k]||j!=son.y+d2[k])
        {
            flag[i][j]=true;
            i+=d1[k];
            j+=d2[k];
        }
        dfs(son,now.dir);
        i=now.x+d1[k];
        j=now.y+d2[k];
        while(i!=son.x+d1[k]||j!=son.y+d2[k])
        {
            flag[i][j]=false;
            i+=d1[k];
            j+=d2[k];
        }
    }
    //到这说明无路可走了
    if (ans<now.cnt)
        ans=now.cnt;
    return;
}

int main()
{
    FILE *fin=fopen("snail.in","r");
    FILE *fout=fopen("snail.out","w");
    fscanf(fin,"%d%d\n",&n,&b);
    memset(matrix,0,sizeof(matrix));
    for(int i=1;i<=b;i++)
    {
        char ch;
        int x,y;
        fscanf(fin,"%c%d\n",&ch,&x);
        y=ch+1-'A';
        matrix[x][y]=1;
    }

    memset(flag,false,sizeof(flag));
    Node st{1,1,0,1};
    flag[1][1]=true;
    dfs(st,-1);
    fprintf(fout,"%d\n",ans);
    /*
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        if (matrix[i][j]==1)
            printf("#");
        else
            printf(".");
        printf("\n");
    }
    */
    return 0;
}
