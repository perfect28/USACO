/*
ID:perfect13
LANG:C++
TASK:castle
*/
#include <iostream>
#include <cstdio>
#define MAXN 100
using namespace std;

enum {
    West = 1,
    North = 2,
    East = 4,
    South = 8
};

typedef struct{
    int id;
    int wall;
}Node;

Node matrix[MAXN][MAXN];

int roomNum;
int roomSize[MAXN*MAXN];
int m,n;

void dfs(int num,int x,int y)
{
    if (matrix[x][y].id) return;

    matrix[x][y].id=num;
    roomSize[num]++;
    int dir=matrix[x][y].wall;

    if (x>1&&!(dir&North)) dfs(num,x-1,y);//向北
    if (x<n&&!(dir&South)) dfs(num,x+1,y);//向南
    if (y>1&&!(dir&West)) dfs(num,x,y-1);//向西
    if (y<m&&!(dir&East)) dfs(num,x,y+1);//向东
}

int main()
{
    FILE *fin=fopen("castle.in","r");
    FILE *fout=fopen("castle.out","w");
    fscanf(fin,"%d%d",&m,&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        fscanf(fin,"%d",&matrix[i][j].wall);
    int num=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        if (!matrix[i][j].id)
            dfs(++num,i,j);
    int maxn=0;
    for(int i=1;i<=num;i++)
        if (maxn<roomSize[i])
        maxn=roomSize[i];

    int maxnRoom=0;
    int ansx,ansy;
    char ansDir;
    for(int j=1;j<=m;j++)
    {
        for(int i=n;i>=1;i--)
        {
            int dir=matrix[i][j].wall;
            if (i>1&&(dir&North))//向北
            {
                int id1=matrix[i][j].id;
                int id2=matrix[i-1][j].id;
                if (id1!=id2)
                    if (maxnRoom<roomSize[id1]+roomSize[id2])
                    {
                        maxnRoom=roomSize[id1]+roomSize[id2];
                        ansx=i;
                        ansy=j;
                        ansDir='N';
                    }
            }

            if (j<m&&(dir&East))//向东
            {
                int id1=matrix[i][j].id;
                int id2=matrix[i][j+1].id;
                if (id1!=id2)
                    if (maxnRoom<roomSize[id1]+roomSize[id2])
                    {
                        maxnRoom=roomSize[id1]+roomSize[id2];
                        ansx=i;
                        ansy=j;
                        ansDir='E';
                    }
            }
        }
    }

    fprintf(fout,"%d\n%d\n%d\n",num,maxn,maxnRoom);
    fprintf(fout,"%d %d %c\n",ansx,ansy,ansDir);
    return 0;
}
