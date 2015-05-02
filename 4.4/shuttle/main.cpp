/*
ID:perfect13
LANG:C++
TASK:shuttle
*/
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
#include <set>
#define INF 0x7FFFFFFF
#define MAXN 10000
using namespace std;

int n;
struct Node{
    string status;
    int blank;
    int step;
    int path[200];
}q[2],ans;

queue<Node> Q;
//set<string> S;
//typedef map< string,bool > Flag;
//Flag flag;

ifstream fin ("shuttle.in");
ofstream fout ("shuttle.out");

bool judge(Node u)
{
    if (u.blank!=n)
        return false;
    for(int i=0;i<n;i++)
        if (u.status[i]!='1')
        return false;
    for(int i=n+1;i<2*n+1;i++)
        if (u.status[i]!='0')
        return false;
    return true;
}

bool reach_end()
{
    //判断是否已到达终点
    if (judge(ans))
    {
        for(int i=1;i<=ans.step;i++)
        {
            if (i==ans.step||i%20==0)
                fout<<ans.path[i]<<endl;
            else
                fout<<ans.path[i]<<' ';
        }
        return true;
    }
    return false;
}

void bfs()
{
    //int h=0,t=1;
    q[1].step=0;
    q[1].blank=n;
    q[1].status.resize(25);
    int i;
    for(i=0;i<n;i++)
        q[1].status[i]='0';
    q[1].status[i]='.';
    for(i=i+1;i<2*n+1;i++)
        q[1].status[i]='1';
    //cout<<q[1].status<<endl;
    Node now;
    Q.push(q[1]);

    //S.clear();
    while(!Q.empty())
    {
        //h=(h+1)%MAXN;
        //now=now;
        now=Q.front();
        //cout<<now.status<<endl;
        Q.pop();
        //左边跳过来
        if (!(now.blank+3<2*n+1&&now.status[now.blank+1]=='0'&&now.status[now.blank+2]=='0'&&now.status[now.blank+3]=='1'))
        {
            if (now.blank-2>=0)
            if (now.status[now.blank-2]=='0'&&now.status[now.blank-1]=='1')
            {
                Node son=now;
                son.status[now.blank-2]=now.status[now.blank];
                son.status[now.blank]=now.status[now.blank-2];
                //cout<<son.status<<endl;
                //if (S.count(son.status)==0)
                {
                    //t=(t+1)%MAXN;
                    //flag[son.status]=true;
                    //S.insert(son.status);
                    son.blank=now.blank-2;
                    son.step=now.step+1;
                    memcpy(son.path,now.path,sizeof(now.path));
                    son.path[son.step]=son.blank+1;
                    //q[t]=son;
                    ans=son;
                    Q.push(son);
                    if (reach_end()) break;
                }
            }

            //左边移过来
            if (now.blank-1>=0&&now.status[now.blank-1]=='0')
            {
                Node son=now;
                son.status[now.blank-1]=now.status[now.blank];
                son.status[now.blank]=now.status[now.blank-1];
                //cout<<son.status<<endl;
                //if (S.count(son.status)==0)
                {
                    //t=(t+1)%MAXN;
                    //flag[son.status]=true;
                    //S.insert(son.status);
                    son.blank=now.blank-1;
                    son.step=now.step+1;
                    memcpy(son.path,now.path,sizeof(now.path));
                    son.path[son.step]=son.blank+1;
                    ans=son;
                    Q.push(son);
                    if (reach_end()) break;
                }
            }
        }


        if (!(now.blank-3>=0&&now.status[now.blank-1]=='1'&&now.status[now.blank-2]=='1'&&now.status[now.blank-3]=='0'))
        {
            //右边移过来
            if (now.blank+1<2*n+1&&now.status[now.blank+1]=='1')
            {
                Node son=now;
                son.status[now.blank]=now.status[now.blank+1];
                son.status[now.blank+1]=now.status[now.blank];
                //cout<<son.status<<endl;
                //if (S.count(son.status)==0)
                {
                    //t=(t+1)%MAXN;
                    //flag[son.status]=true;
                    //S.insert(son.status);
                    son.blank=now.blank+1;
                    son.step=now.step+1;
                    memcpy(son.path,now.path,sizeof(now.path));
                    son.path[son.step]=son.blank+1;
                    ans=son;
                    Q.push(son);
                    if (reach_end()) break;
                }
            }

            //右边跳过来
            if (now.blank+2<2*n+1)
            if (now.status[now.blank+1]=='0'&&now.status[now.blank+2]=='1')
            {
                Node son=now;
                son.status[now.blank+2]=now.status[now.blank];
                son.status[now.blank]=now.status[now.blank+2];
                //cout<<son.status<<endl;
                //if (S.count(son.status)==0)
                {
                    //t=(t+1)%MAXN;
                    //flag[son.status]=true;
                    //S.insert(son.status);
                    son.blank=now.blank+2;
                    son.step=now.step+1;
                    memcpy(son.path,now.path,sizeof(now.path));
                    son.path[son.step]=son.blank+1;
                    ans=son;
                    Q.push(son);
                    if (reach_end()) break;
                }
            }
        }
    }
}


/*
这道题尤其无语……BFS本可以过的，但是不能标记，也不需要标记，因为根本不会走回去……！！！！
暴内存暴了好久╮(╯▽╰)╭
*/
int main()
{
    fin>>n;
    bfs();
    return 0;
}
