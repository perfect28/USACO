/*
ID:perfect13
LANG:C++
TASK:starry
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define INF 0x7FFFFFFF
#define MAXN 105
using namespace std;

char matrix[MAXN][MAXN];
bool flag[MAXN][MAXN];
char ans[MAXN][MAXN];

struct Node{
    int x,y;
    int h,w;
    int m[MAXN][MAXN];
}node[200],now_node;

struct Point{
    int x,y;
};

int w,h;
char now_char,cnt_char;

void divide(int x,int y)
{
    Point q[1000],now,son;
    int head=0,tail=1;
    int d1[8]={-1,-1,-1,0,1,1,1,0},
        d2[8]={-1,0,1,1,1,0,-1,-1};
    memset(q,0,sizeof(q));
    memset(now_node.m,0,sizeof(now_node.m));
    now_node.x=x+1;now_node.y=y+1;
    now_node.h=1;now_node.w=1;
    now_node.m[1][1]=1;
    q[tail].x=x;
    q[tail].y=y;
    flag[x][y]=true;
    while(head<tail)
    {
        now=q[++head];
        for(int k=0;k<=7;k++)
        {
            son.x=now.x+d1[k];
            son.y=now.y+d2[k];
            if (son.x>=0&&son.x<h&&son.y>=0&&son.y<w)
                if (matrix[son.x][son.y]=='1'&&!flag[son.x][son.y])
                {
                    if (son.x+2-now_node.x>now_node.h)
                        now_node.h=son.x+2-now_node.x;

                    if (son.y+1<now_node.y)
                    {
                        now_node.y=son.y+1;
                        now_node.w++;
                        for(int j=now_node.w;j>=2;j--)
                        {
                            for(int i=1;i<=now_node.h;i++)
                                now_node.m[i][j]=now_node.m[i][j-1];
                        }
                        for(int i=1;i<=now_node.h;i++)
                            now_node.m[i][1]=0;
                    }
                    else if (son.y+2-now_node.y>now_node.w)
                        now_node.w=son.y+2-now_node.y;

                    now_node.m[son.x+2-now_node.x][son.y+2-now_node.y]=1;
                    q[++tail]=son;
                    flag[son.x][son.y]=true;
                }
        }
    }
}


bool comp(int u[MAXN][MAXN],int v[MAXN][MAXN],int h,int w)
{
    for(int i=1;i<=h;i++)
        for(int j=1;j<=w;j++)
        if (u[i][j]!=v[i][j])
            return false;
    return true;
}

void check()
{
    Node tmp,un_tmp;
    int k;
    for(k='a';k<=cnt_char;k++)
    {
        tmp=now_node;
        if (tmp.h==node[k].h&&tmp.w==node[k].w)
            if (comp(tmp.m,node[k].m,tmp.h,tmp.w))
            {
                now_char=(char)k;
                return;
            }
        un_tmp=tmp;
        for(int i=1;i<=tmp.h;i++)
            for(int j=1;j<=tmp.w;j++)
            un_tmp.m[i][j]=tmp.m[i][tmp.w+1-j];
        if (un_tmp.h==node[k].h&&un_tmp.w==node[k].w)
            if (comp(un_tmp.m,node[k].m,un_tmp.h,un_tmp.w))
            {
                now_char=(char)k;
                return;
            }

        //向右90 (j,h+1-i)
        memset(tmp.m,0,sizeof(tmp.m));
        for(int i=1;i<=now_node.h;i++)
            for(int j=1;j<=now_node.w;j++)
        {
            tmp.m[j][now_node.h+1-i]=now_node.m[i][j];
        }
        tmp.h=now_node.w;
        tmp.w=now_node.h;
        if (tmp.h==node[k].h&&tmp.w==node[k].w)
            if (comp(tmp.m,node[k].m,tmp.h,tmp.w))
            {
                now_char=(char)k;
                return;
            }
        un_tmp=tmp;
        for(int i=1;i<=tmp.h;i++)
            for(int j=1;j<=tmp.w;j++)
            un_tmp.m[i][j]=tmp.m[i][tmp.w+1-j];
        if (un_tmp.h==node[k].h&&un_tmp.w==node[k].w)
            if (comp(un_tmp.m,node[k].m,un_tmp.h,un_tmp.w))
            {
                now_char=(char)k;
                return;
            }

        //向左90 (w+1-j,i)
        memset(tmp.m,0,sizeof(tmp.m));
        for(int i=1;i<=now_node.h;i++)
            for(int j=1;j<=now_node.w;j++)
        {
            tmp.m[now_node.w+1-j][i]=now_node.m[i][j];
        }
        tmp.h=now_node.w;
        tmp.w=now_node.h;
        if (tmp.h==node[k].h&&tmp.w==node[k].w)
            if (comp(tmp.m,node[k].m,tmp.h,tmp.w))
            {
                now_char=(char)k;
                return;
            }
        un_tmp=tmp;
        for(int i=1;i<=tmp.h;i++)
            for(int j=1;j<=tmp.w;j++)
            un_tmp.m[i][j]=tmp.m[i][tmp.w+1-j];
        if (un_tmp.h==node[k].h&&un_tmp.w==node[k].w)
            if (comp(un_tmp.m,node[k].m,un_tmp.h,un_tmp.w))
            {
                now_char=(char)k;
                return;
            }


        //旋转180 (w+1-j,h+1-i)
        memset(tmp.m,0,sizeof(tmp.m));
        for(int i=1;i<=now_node.h;i++)
            for(int j=1;j<=now_node.w;j++)
        {
            tmp.m[now_node.h+1-i][now_node.w+1-j]=now_node.m[i][j];
        }
        tmp.h=now_node.h;
        tmp.w=now_node.w;
        if (tmp.h==node[k].h&&tmp.w==node[k].w)
            if (comp(tmp.m,node[k].m,tmp.h,tmp.w))
            {
                now_char=(char)k;
                return;
            }
        un_tmp=tmp;
        for(int i=1;i<=tmp.h;i++)
            for(int j=1;j<=tmp.w;j++)
            un_tmp.m[i][j]=tmp.m[i][tmp.w+1-j];
        if (un_tmp.h==node[k].h&&un_tmp.w==node[k].w)
            if (comp(un_tmp.m,node[k].m,un_tmp.h,un_tmp.w))
            {
                now_char=(char)k;
                return;
            }
    }
    cnt_char++;
    now_char=cnt_char;
    //cout<<now_node.x<<' '<<now_node.y<<':'<<endl;
    for(int i=1;i<=now_node.h;i++)
    {
        for(int j=1;j<=now_node.w;j++)
        {
            node[cnt_char].m[i][j]=now_node.m[i][j];
            /*
            if (node[cnt_char].m[i][j])
                printf("%c",now_char);
            else
                printf("0");
            */
        }
        //printf("\n");
    }
    node[cnt_char].h=now_node.h;
    node[cnt_char].w=now_node.w;
    return;
}

void print(int x,int y)
{
    for(int i=1;i<=now_node.h;i++)
        for(int j=1;j<=now_node.w;j++)
        if (now_node.m[i][j])
            ans[x+i-1][y+j-1]=now_char;
}

int main()
{
    FILE *fin=fopen("starry.in","r");
    FILE *fout=fopen("starry.out","w");
    fscanf(fin,"%d%d",&w,&h);
    for(int i=0;i<h;i++)
        fscanf(fin,"%s",&matrix[i]);

    memset(flag,false,sizeof(flag));
    cnt_char='a'-1;
    for(int i=0;i<h;i++)
        for(int j=0;j<w;j++)
        if (matrix[i][j]=='1'&&!flag[i][j])
        {
            divide(i,j);//划a分出当前区域
            check();//检查是否是之前出现过的形状
            print(now_node.x,now_node.y);//在答案矩阵中绘制当前区域
        }
    for(int i=1;i<=h;i++)
    {
        for(int j=1;j<=w;j++)
        {
            if (ans[i][j])
                fprintf(fout,"%c",ans[i][j]);
            else
                fprintf(fout,"0");
        }
        fprintf(fout,"\n");
    }
    return 0;
}
