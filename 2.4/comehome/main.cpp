/*
ID:perfect13
LANG:C++
TASK:comehome
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#define INF 999999
using namespace std;

//int matrix[200][200];
int minn;
char ans_ch;

typedef struct{
    int x,value,next;
}Node;

Node f[20500];
int st[300],dist[300],q[1000];
bool vis[300];

void spfa(int s)
{
    int h=0,t=1;
    int now,son;
    memset(vis,false,sizeof(vis));
    memset(dist,-1,sizeof(dist));
    q[t]=s;
    dist[s]=0;
    vis[s]=true;
    while(h!=t){
        h=(h+1)%1000;
        now=q[h];
        //vis[now]=false;
        int tmp=st[now];
        while(tmp!=-1)
        {
            son=f[tmp].x;
            if (dist[son]-f[tmp].value>dist[now]||dist[son]<0)
            {
                dist[son]=dist[now]+f[tmp].value;
                if (son=='Z')
                    if (minn>dist[son])
                    {
                        ans_ch=s;
                        minn=dist[son];
                    }

                if (!vis[son])
                {
                    vis[son]=true;
                    t=(t+1)%1000;
                    q[t]=son;
                }
            }
            tmp=f[tmp].next;
        }
    }
}

int main()
{
    FILE *fin=fopen("comehome.in","r");
    FILE *fout=fopen("comehome.out","w");
    int n;
    fscanf(fin,"%d\n",&n);
    char ch1,ch2;
    int tmp;
    memset(st,-1,sizeof(st));
    for(int i=1;i<=n;i++)
    {
        fscanf(fin,"%c %c %d\n",&ch1,&ch2,&tmp);
        //matrix[ch1][ch2]=tmp;
        f[i].x=ch2;
        f[i].value=tmp;
        f[i].next=st[ch1];
        st[ch1]=i;

        f[i+n].x=ch1;
        f[i+n].value=tmp;
        f[i+n].next=st[ch2];
        st[ch2]=i+n;
    }

    minn=INF;
    for(int st='A';st<='Y';st++)
        spfa(st);

    fprintf(fout,"%c %d\n",ans_ch,minn);
    return 0;
}
