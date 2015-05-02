/*
ID:perfect13
LANG:C++
TASK:ttwo
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef struct{
    int x,y;
    int dir;
}Node;

Node farmer,cow;
char matrix[10][10];
int d1[4]={-1,0,1,0},
    d2[4]={0,1,0,-1};

void move(Node &u)
{
    int x,y,dir;
    dir=u.dir;
    x=u.x+d1[dir];
    y=u.y+d2[dir];
    if (matrix[x][y]=='*'||x<0||y<0||x>=10||y>=10)
    {
        u.dir=(dir+1)%4;
    }
    else{
        u.x=x;
        u.y=y;
    }
}
int main()
{
    FILE *fin=fopen("ttwo.in","r");
    FILE *fout=fopen("ttwo.out","w");
    for(int i=0;i<10;i++)
        fscanf(fin,"%s",matrix[i]);

    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
    {
        if (matrix[i][j]=='F')
        {
            farmer.x=i;
            farmer.y=j;
            farmer.dir=0;
        }
        if (matrix[i][j]=='C')
        {
            cow.x=i;
            cow.y=j;
            cow.dir=0;
        }
    }

    int time=0;
    bool ok=false;
    while(1)
    {
        if (time>10000) break;
        if (cow.x==farmer.x&&cow.y==farmer.y)
        {
            ok=true;
            break;
        }
        time++;
        move(cow);
        move(farmer);
    }

    if (ok)
        fprintf(fout,"%d\n",time);
    else fprintf(fout,"0\n");

    return 0;
}
