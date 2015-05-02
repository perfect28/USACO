 /*
ID:perfect13
LANG:C++
TASK:camelot
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#define INF 0x7f7f7f7f
#define MAXN 105000
using namespace std;


struct node{
    int x,y;
    int flag;
}king,knight[1200],q[1000];

int row,col;
int sum[50][30];//骑士走的总步数
int extra[50][30];//接王多走的步数
bool vis[50][30];
int dist[50][30];
int d[50][30][50][30];

void spfa(node s)
{
    int h=0,t=1;
    bool ok=false;
    int d1[8]={-2,-2,-1,1,2,2,1,-1},
        d2[8]={-1,1,2,2,1,-1,-2,-2};
    node now,son;
    memset(q,0,sizeof(q));
    memset(dist,0,sizeof(dist));
    memset(vis,false,sizeof(vis));
    q[t]=s;
    vis[s.x][s.y]=1;
    while(h!=t)
    {
        h=(h+1)%1000;
        now=q[h];
        //vis[now.x][now.y]=false;
        for(int i=0;i<8;i++)
        {
            son.x=now.x+d1[i];
            son.y=now.y+d2[i];
            if (son.x>=1&&son.x<=row&&son.y>=1&&son.y<=col)
                if (!vis[son.x][son.y])
                {
                    t=(t+1)%1000;
                    q[t]=son;
                    vis[son.x][son.y]=1;
                    dist[son.x][son.y]=dist[now.x][now.y]+1;
                    d[s.x][s.y][son.x][son.y]=dist[son.x][son.y];
                }
        }
        if (ok) break;
    }
}


int main()
{
    FILE *fin=fopen("camelot.in","r");
    FILE *fout=fopen("camelot.out","w");
    fscanf(fin,"%d%d\n",&row,&col);
    int x;
    char y[3];
    fscanf(fin,"%s%d",&y,&x);
    king.x=x;
    king.y=y[0]-'A'+1;

    int knum=0;
    while(fscanf(fin,"%s%d",&y,&x)!=EOF)
    {
        knum++;
        knight[knum].x=x;
        knight[knum].y=y[0]-'A'+1;
    }

    memset(d,-1,sizeof(d));

     for(int i=1;i<=row;i++)
        for(int j=1;j<=col;j++)
        {
            for(int ii=1;ii<=row;ii++)
                for(int jj=1;jj<=col;jj++)
                    if (i==ii&&j==jj)
                        d[i][j][ii][jj]=0;
        }

    for(int i=1;i<=row;i++)
        for(int j=1;j<=col;j++)
        {
            node ss;
            ss.x=i;
            ss.y=j;
            spfa(ss);
        }

    for(int i=1;i<=row;i++)
        for(int j=1;j<=col;j++)
        {
            int d=max(abs(i-king.x),abs(j-king.y));
            extra[i][j]=d;
        }

    for(int i=1;i<=row;i++)
    {
        for(int j=1;j<=col;j++)
            printf("%d ",extra[i][j]);
        printf("\n");
    }

    memset(sum,0,sizeof(sum));
    for(int k=1;k<=knum;k++)
    {
        int x=knight[k].x;
        int y=knight[k].y;

        for(int i=1;i<=row;i++)
            for(int j=1;j<=col;j++)
                if (d[x][y][i][j]>=0&&sum[i][j]<INF)
                {
                    sum[i][j]+=d[x][y][i][j];
                }
                else sum[i][j]=INF;


        for(int kx=king.x-2;kx<=king.x+2;kx++)
            for(int ky=king.y-2;ky<=king.y+2;ky++)
                if (kx>=1&&kx<=row&&ky>=1&&ky<=col)
                {
                    int add=max(abs(kx-king.x),abs(ky-king.y));
                    for(int i=1;i<=row;i++)
                        for(int j=1;j<=col;j++)
                            if (d[x][y][kx][ky]>=0&&d[kx][ky][i][j]>=0&&d[x][y][i][j]>=0)
                        {
                            int temp=d[x][y][kx][ky]+d[kx][ky][i][j]-d[x][y][i][j];
                            if (extra[i][j]>temp+add&&temp>=0)
                                extra[i][j]=temp+add;
                        }
                }
    }


    printf("\n");
    for(int i=1;i<=row;i++)
    {
        for(int j=1;j<=col;j++)
            printf("%d ",extra[i][j]);
        printf("\n");
    }


    int ans=INF;
    for(int i=1;i<=row;i++)
    {
        for(int j=1;j<=col;j++)
            if (ans>sum[i][j]+extra[i][j])
                ans=sum[i][j]+extra[i][j];
    }

    fprintf(fout,"%d\n",ans);
    return 0;
}
