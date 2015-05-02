 /*
ID:perfect13
LANG:C++
TASK:fence6
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#define INF 0x7FFFFFFF
#define MAXN 105
using namespace std;

int n;
int ans;
struct segment{
    int len;
    int left[MAXN];
    int right[MAXN];
}seg[MAXN];
bool vis[MAXN];
int st;
void dfs(int s,int dir,int len)
{
    int son,d;
    if (len>=ans)
        return;

    if (dir==0)//×ó±ß
    {
        for(int i=1;i<=seg[s].left[0];i++)
        {
            son=seg[s].left[i];
            d=0;//Ä¬ÈÏ×ó¶Ëµã
            for(int j=1;j<=seg[son].right[0];j++)
                if (seg[son].right[j]==s){
                    d=1;
                    break;
                }

            if (son==st&&d==0)
            {
                if (ans>len)
                    ans=len;
                return;
            }

            if (!vis[son])
            {
                vis[son]=true;
                dfs(son,1-d,len+seg[son].len);
                vis[son]=false;
            }
        }
    }
    else if (dir==1)//ÓÒ±ß
    {
        for(int i=1;i<=seg[s].right[0];i++)
        {
            son=seg[s].right[i];
            d=0;//Ä¬ÈÏ×ó¶Ëµã
            for(int j=1;j<=seg[son].right[0];j++)
                if (seg[son].right[j]==s){
                    d=1;
                    break;
                }

            if (son==st&&d==0)
            {
                if (ans>len)
                    ans=len;
                return;
            }

            if (!vis[son])
            {
                vis[son]=true;
                dfs(son,1-d,len+seg[son].len);
                vis[son]=false;
            }
        }
    }
}

int main()
{
    FILE *fin=fopen("fence6.in","r");
    FILE *fout=fopen("fence6.out","w");
    fscanf(fin,"%d",&n);
    for(int i=1;i<=n;i++)
    {
        int id;
        fscanf(fin,"%d",&id);
        fscanf(fin,"%d",&seg[id].len);
        fscanf(fin,"%d%d",&seg[id].left[0],&seg[id].right[0]);
        for(int j=1;j<=seg[id].left[0];j++)
            fscanf(fin,"%d",&seg[id].left[j]);
        for(int j=1;j<=seg[id].right[0];j++)
            fscanf(fin,"%d",&seg[id].right[j]);
    }
    ans=INF;
    for(st=2;st<=n;st++)
    {
        memset(vis,false,sizeof(vis));
        vis[st]=true;
        dfs(st,1,seg[st].len);
    }


    fprintf(fout,"%d\n",ans);
    return 0;
}
