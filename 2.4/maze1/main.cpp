/*
ID:perfect13
LANG:C++
TASK:maze1
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#define INF 999999
using namespace std;

typedef struct{
    int x,y;
    int dis;
}Node;

Node entrance[3];
int n,m;
char matrix[300][100];
int dist[300][100];


Node q[10000];
bool vis[300][100];
int maxn;

void bfs(Node k)
{
    int h=0,t=1;
    Node now;
    int d1[4]={-1,0,1,0},
        d2[4]={0,1,0,-1};
    memset(q,0,sizeof(q));
    memset(vis,false,sizeof(vis));
    q[t]=k;
    while(h!=t)
    {
        h=(h+1)%10000;
        now=q[h];
        //vis[now.x][now.y]=false;
        for(int i=0;i<4;i++)
        {
            int x=now.x+d1[i];
            int y=now.y+d2[i];
            if (x>=1&&x<=n&&y>=1&&y<=m&&!vis[x][y])
            {
                int xx=(x*2-1+now.x*2-1)/2;
                int yy=(y*2-1+now.y*2-1)/2;
                if (matrix[xx][yy]==' ')
                {
                    vis[x][y]=true;
                    t=(t+1)%10000;
                    q[t].x=x;
                    q[t].y=y;
                    q[t].dis=now.dis+1;
                    if (dist[x][y]>q[t].dis)
                        dist[x][y]=q[t].dis;
                }
            }

        }
    }
}

int main()
{
    FILE *fin=fopen("maze1.in","r");
    FILE *fout=fopen("maze1.out","w");
    fscanf(fin,"%d%d\n",&m,&n);

    //第i行:i*2-1
    //第j列:j*2-1
    for(int i=0;i<=2*n;i++)
        fgets(matrix[i],sizeof(matrix[i]),fin);

    int num=0;
    //出口在上下
    for(int j=1;j<2*m;j+=2)
    {
        if (matrix[0][j]==' '){
            num++;
            entrance[num].x=1;
            entrance[num].y=(j+1)/2;
        }
        if (matrix[2*n][j]==' '){
            num++;
            entrance[num].x=n;
            entrance[num].y=(j+1)/2;
        }
    }
    //出口在左右
    for(int i=1;i<2*n;i+=2)
    {
        if (matrix[i][0]==' '){
            num++;
            entrance[num].x=(i+1)/2;
            entrance[num].y=1;
        }
        if (matrix[i][2*m]==' '){
            num++;
            entrance[num].x=(i+1)/2;
            entrance[num].y=m;
        }
    }

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        dist[i][j]=INF;

    for(int i=1;i<=2;i++)
    {
        entrance[i].dis=1;
        bfs(entrance[i]);
    }

    int ans=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        if (ans<dist[i][j]&&dist[i][j]!=INF)
            ans=dist[i][j];
    fprintf(fout,"%d\n",ans);
    return 0;
}
