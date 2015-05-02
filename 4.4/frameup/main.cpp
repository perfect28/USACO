/*
ID:perfect13
LANG:C++
TASK:frameup
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 0x7FFFFFFF
#define MAXN 105
using namespace std;

struct Node{
    int left,right,up,down;
    char ch;
}node[200];


FILE *fin=fopen("frameup.in","r");
FILE *fout=fopen("frameup.out","w");
int h,w;
char matrix[35][35];
bool link[200][200];
int degree[200];
char res[10000][35];
char ans[35];
bool flag[200];
bool exist[200];
int sum;
int ans_num;

void dfs(int num)
{
    if (num>sum)
    {
        ++ans_num;
        for(int i=sum;i>=1;i--)
            res[ans_num][sum-i]=ans[i];
        res[ans_num][sum]='\0';
        //cout<<res[ans_num]<<endl;
    }
    for(int i='A';i<='Z';i++)
        if (exist[i])
    if (degree[i]==0&&!flag[i])
    {
        flag[i]=true;
        ans[num]=(char)i;
        for(int j='A';j<='Z';j++)
            if (exist[j]&&link[i][j])
                degree[j]--;
        dfs(num+1);
        flag[i]=false;
        ans[num]=0;
        for(int j='A';j<='Z';j++)
            if (exist[j]&&link[i][j])
                degree[j]++;
    }
}

/*
void swap(char u[35],char v[35])
{
    int len=strlen(u);
    char tmp[35];
    strcpy(tmp,u);
    strcpy(u,v);
    strcpy(v,tmp);
}

void sort()
{
    for(int i=1;i<=ans_num;i++)
    {
        for(int j=i+1;j<=ans_num;j++)
        {
            int tmp=strcmp(res[i],res[j]);
            if (tmp>0)
                swap(res[i],res[j]);
        }
    }
}
*/

int cmp(const void* a, const void* b)
{
    return (strcmp((char* )a,(char* )b));
}

int main()
{
    fscanf(fin,"%d%d",&h,&w);
    for(int i=0;i<h;i++)
        fscanf(fin,"%s",matrix[i]);
    for(int i='A';i<='Z';i++)
    {
        node[i].ch=(char)i;
        node[i].left=INF;
        node[i].right=-INF;
        node[i].up=INF;
        node[i].down=-INF;
    }
    memset(exist,false,sizeof(exist));
    for(int i=0;i<h;i++)
        for(int j=0;j<w;j++)
    {
        char now=matrix[i][j];
        if (now>='A'&&now<='Z')
        {
            if (!exist[now])
            {
                exist[now]=true;
                sum++;
            }
            if (node[now].left>j)
                node[now].left=j;
            if (node[now].right<j)
                node[now].right=j;
            if (node[now].up>i)
                node[now].up=i;
            if (node[now].down<i)
                node[now].down=i;
        }
    }
    memset(link,false,sizeof(link));
    memset(degree,0,sizeof(degree));
    for(int k='A';k<='Z';k++)
        if (exist[k])
    {
        //ио
        for(int j=node[k].left;j<=node[k].right;j++)
        {
            int i=node[k].up;
            char now=matrix[i][j];
            if (now!=node[k].ch)
            {
                if (!link[now][node[k].ch])
                {
                    degree[node[k].ch]++;
                    link[now][node[k].ch]=true;
                }
            }
        }

        //вС
        for(int i=node[k].up;i<=node[k].down;i++)
        {
            int j=node[k].left;
            char now=matrix[i][j];
            if (now!=node[k].ch)
            {
                if (!link[now][node[k].ch])
                {
                    degree[node[k].ch]++;
                    link[now][node[k].ch]=true;
                }
            }
        }

        //ср
        for(int i=node[k].up;i<=node[k].down;i++)
        {
            int j=node[k].right;
            char now=matrix[i][j];
            if (now!=node[k].ch)
            {
                if (!link[now][node[k].ch])
                {
                    degree[node[k].ch]++;
                    link[now][node[k].ch]=true;
                }
            }
        }

        //об
        for(int j=node[k].left;j<=node[k].right;j++)
        {
            int i=node[k].down;
            char now=matrix[i][j];
            if (now!=node[k].ch)
            {
                if (!link[now][node[k].ch])
                {
                    degree[node[k].ch]++;
                    link[now][node[k].ch]=true;
                }
            }
        }
    }

    memset(flag,false,sizeof(flag));
    dfs(1);

    qsort(res+1, ans_num, sizeof(res[0]), cmp);

    for(int i=1;i<=ans_num;i++)
        fprintf(fout,"%s\n",res[i]);

    return 0;
}
