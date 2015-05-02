/*
ID:perfect13
LANG:C++
TASK:window
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

struct Win
{
    int x1,y1,x2,y2;
    int floor;
    char name;
}w[200];

bool flag[200];
int area[200];
int num;

int cmp(Win u,Win v)
{
    return u.floor<v.floor;
}

void cover(int l,int r,int b,int t,int k,int c)
{
    while(k<=num&&(l>w[k].x2||r<w[k].x1||b>w[k].y2||t<w[k].y1))
        k++;
    if (k>num)
    {
        area[c]+=(r-l)*(t-b);
        return;
    }
    if (l<w[k].x1)
    {
        cover(l,w[k].x1,b,t,k+1,c);
        l=w[k].x1;
    }
    if (r>w[k].x2)
    {
        cover(w[k].x2,r,b,t,k+1,c);
        r=w[k].x2;
    }
    if (b<w[k].y1)
    {
        cover(l,r,b,w[k].y1,k+1,c);
        b=w[k].y1;
    }
    if (t>w[k].y2)
    {
        cover(l,r,w[k].y2,t,k+1,c);
        t=w[k].y2;
    }
}

int main()
{
    FILE *fin=fopen("window.in","r");
    FILE *fout=fopen("window.out","w");
    char cmd,name,none;
    double ans;
    int lx,ly,rx,ry;
    Win tmp;
    num=0;
    memset(flag,false,sizeof(flag));
    while(fscanf(fin,"%c%c",&cmd,&none)!=EOF)
    {
        if (cmd=='w')
        {
            fscanf(fin,"%c%c",&name,&none);
            if (!flag[name])
            {
                flag[name]=true;
                num++;
                fscanf(fin,"%d%c",&lx,&none);
                fscanf(fin,"%d%c",&ly,&none);
                fscanf(fin,"%d%c",&rx,&none);
                fscanf(fin,"%d%c\n",&ry,&none);
                if (lx<rx){
                    w[num].x1=lx;
                    w[num].x2=rx;
                }
                else{
                    w[num].x1=rx;
                    w[num].x2=lx;
                }
                if (ly<ry){
                    w[num].y1=ly;
                    w[num].y2=ry;
                }
                else{
                    w[num].y1=ry;
                    w[num].y2=ly;
                }
                w[num].name=name;
            }
        }
        else if (cmd=='t')
        {
            fscanf(fin,"%c%c\n",&name,&none);
            for(int i=1;i<=num;i++)
            {
                if (w[i].name==name)
                {
                    tmp=w[i];
                    int j;
                    for(j=i;j<num;j++)
                        w[j]=w[j+1];
                    w[j]=tmp;
                    break;
                }
            }
        }
        else if (cmd=='b')
        {
            fscanf(fin,"%c%c\n",&name,&none);
            for(int i=1;i<=num;i++)
            {
                if (w[i].name==name)
                {
                    tmp=w[i];
                    int j;
                    for(j=i;j>1;j--)
                        w[j]=w[j-1];
                    w[j]=tmp;
                    break;
                }
            }
        }
        else if (cmd=='d')
        {
            fscanf(fin,"%c%c\n",&name,&none);
            flag[name]=false;
            for(int i=1;i<=num;i++)
            {
                if (w[i].name==name)
                {
                    for(int j=i;j<num;j++)
                        w[j]=w[j+1];
                    num--;
                    break;
                }
            }
        }
        else if (cmd=='s')
        {
            fscanf(fin,"%c%c\n",&name,&none);
            memset(area,0,sizeof(area));
            for(int i=num;i>=1;i--)
                cover(w[i].x1,w[i].x2,w[i].y1,w[i].y2,i+1,w[i].name);

            for(int i=1;i<=num;i++)
                if (name==w[i].name)
                {
                    //printf("%d\n",area[name]);
                    ans=area[name]*1.0/((w[i].x2-w[i].x1)*(w[i].y2-w[i].y1)*1.0)*100;
                    fprintf(fout,"%.3lf\n",ans);
                    break;
                }
        }
    }
    return 0;
}
