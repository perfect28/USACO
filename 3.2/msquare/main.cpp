 /*
ID:perfect13
LANG:C++
TASK:msquare
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#define INF 0x7FFFFFFF
#define MAXN 105000
using namespace std;

bool flag[9][9][9][9][9][9][9];
struct Node{
    int square[2][4];
    int cnt;
    char rec[100];
}q[10000];

int square[2][4];
int num;
char ans[100];

void A_operation(int squ[2][4])
{
    int tmp[2][4];
    for(int i=0;i<2;i++)
        for(int j=0;j<4;j++)
        tmp[i][j]=squ[i][j];
    for(int i=0;i<2;i++)
        for(int j=0;j<4;j++)
        squ[1-i][j]=tmp[i][j];
}
void B_operation(int squ[2][4])
{
    int tmp[2][4];
    for(int i=0;i<2;i++)
        for(int j=0;j<4;j++)
        tmp[i][j]=squ[i][j];
    for(int i=0;i<2;i++)
        for(int j=1;j<4;j++)
        squ[i][j]=tmp[i][j-1];
    squ[0][0]=tmp[0][3];
    squ[1][0]=tmp[1][3];
}
void C_operation(int squ[2][4])
{
    int tmp[2][4];
    for(int i=0;i<2;i++)
        for(int j=0;j<4;j++)
        tmp[i][j]=squ[i][j];
    squ[0][1]=tmp[1][1];
    squ[0][2]=tmp[0][1];
    squ[1][1]=tmp[1][2];
    squ[1][2]=tmp[0][2];
}

bool cmp_squ(int squ[2][4])
{
    for(int i=0;i<2;i++)
        for(int j=0;j<4;j++)
            if (square[i][j]==squ[i][j])
                continue;
            else
                return false;
    return true;
}

void bfs(Node now)
{
    int h=0,t=1;

    if (cmp_squ(now.square)) return;
    Node tmp;
    memset(q,0,sizeof(q));
    memset(flag,false,sizeof(flag));
    q[t]=now;
    flag[now.square[0][0]][now.square[0][1]][now.square[0][2]][now.square[0][3]][now.square[1][0]][now.square[1][1]][now.square[1][2]]=true;

    while(h!=t){
        h=(h+1)%10000;

        tmp=q[h];
        A_operation(tmp.square);
        if (!flag[tmp.square[0][0]][tmp.square[0][1]][tmp.square[0][2]][tmp.square[0][3]][tmp.square[1][0]][tmp.square[1][1]][tmp.square[1][2]])
        {
            t=(t+1)%10000;
            q[t]=tmp;
            flag[tmp.square[0][0]][tmp.square[0][1]][tmp.square[0][2]][tmp.square[0][3]][tmp.square[1][0]][tmp.square[1][1]][tmp.square[1][2]]=true;
            q[t].cnt=q[h].cnt+1;
            strcat(q[t].rec,"A");
            //cout<<q[t].rec<<endl;
            if (cmp_squ(tmp.square))
            {
                strcpy(ans,q[t].rec);
                num=q[t].cnt;
                break;
            }
        }

        tmp=q[h];
        B_operation(tmp.square);
        if (!flag[tmp.square[0][0]][tmp.square[0][1]][tmp.square[0][2]][tmp.square[0][3]][tmp.square[1][0]][tmp.square[1][1]][tmp.square[1][2]])
        {
            t++;
            q[t]=tmp;
            flag[tmp.square[0][0]][tmp.square[0][1]][tmp.square[0][2]][tmp.square[0][3]][tmp.square[1][0]][tmp.square[1][1]][tmp.square[1][2]]=true;
            q[t].cnt=q[h].cnt+1;
            strcat(q[t].rec,"B");
            //cout<<q[t].rec<<endl;
            if (cmp_squ(tmp.square))
            {
                strcpy(ans,q[t].rec);
                num=q[t].cnt;
                break;
            }
        }

        tmp=q[h];
        C_operation(tmp.square);
        if (!flag[tmp.square[0][0]][tmp.square[0][1]][tmp.square[0][2]][tmp.square[0][3]][tmp.square[1][0]][tmp.square[1][1]][tmp.square[1][2]])
        {
            t++;
            q[t]=tmp;
            flag[tmp.square[0][0]][tmp.square[0][1]][tmp.square[0][2]][tmp.square[0][3]][tmp.square[1][0]][tmp.square[1][1]][tmp.square[1][2]]=true;
            q[t].cnt=q[h].cnt+1;
            strcat(q[t].rec,"C");
            //cout<<q[t].rec<<endl;
            if (cmp_squ(tmp.square))
            {
                strcpy(ans,q[t].rec);
                num=q[t].cnt;
                break;
            }
        }
    }
}


int main()
{
    FILE *fin=fopen("msquare.in","r");
    FILE *fout=fopen("msquare.out","w");
    for(int j=0;j<4;j++)
        fscanf(fin,"%d",&square[0][j]);
    for(int j=3;j>=0;j--)
        fscanf(fin,"%d",&square[1][j]);
    Node now;
    for(int j=0;j<4;j++)
        now.square[0][j]=j+1;
    for(int j=0;j<4;j++)
        now.square[1][j]=8-j;
    now.cnt=0;
    memset(now.rec,0,sizeof(now.rec));
    bfs(now);
    fprintf(fout,"%d\n",num);
    for(int i=0;i<strlen(ans);i++)
        fprintf(fout,"%c",ans[i]);
    fprintf(fout,"\n");
    return 0;
}
