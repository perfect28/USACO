 /*
ID:perfect13
LANG:C++
TASK:fence
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#define INF 0x7FFFFFFF
#define MAXN 505
using namespace std;


int g[MAXN][MAXN];
int degree[MAXN];
int circuit[1050];
int circuitpos;


void find_circuit(int x)
{
    for(int i=1;i<MAXN;i++)
    if (g[x][i])
    {
        g[x][i]--;
        g[i][x]--;
        find_circuit(i);
    }
    circuit[++circuitpos]=x;
}

void find_euler_circuit(int i)
{
    circuitpos=0;
    find_circuit(i);
}

int main()
{
    FILE *fin=fopen("fence.in","r");
    FILE *fout=fopen("fence.out","w");
    int n,m;
    fscanf(fin,"%d",&m);
    memset(g,0,sizeof(g));
    memset(degree,0,sizeof(degree));
    for(int i=1;i<=m;i++)
    {
        int x,y;
        fscanf(fin,"%d%d",&x,&y);
        g[x][y]++;
        g[y][x]++;
        degree[x]++;
        degree[y]++;
    }

    int start;
    for(int i=1;i<MAXN;i++)
    {
        if (degree[i])
        {
            start=i;
            break;
        }
    }
    for(int i=1;i<MAXN;i++)
    {
        if (degree[i]&1){
            start=i;
            break;
        }
    }
    find_euler_circuit(start);
    for(int i=circuitpos;i>=1;i--)
        fprintf(fout,"%d\n",circuit[i]);
    return 0;
}
