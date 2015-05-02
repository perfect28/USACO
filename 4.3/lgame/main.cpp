 /*
ID:perfect13
LANG:C++
TASK:lgame
*/
#include <iostream>
#include <cstdio>
#include <fstream>
#include <cstring>
#include <string>
#define INF 0x7FFFFFFF
#define MAXN 105
using namespace std;

string dict[40040];
string now[40040];
string ans_str[40040];
int value[40040];

int flag[200],tmp[200],cost[200];
int grade[26]={2,5,4,4,1,6,5,5,1,7,6,3,5,2,3,5,7,2,1,2,4,6,6,7,5,7};
int main()
{
    ifstream fdict ("lgame.dict");
    ifstream fin ("lgame.in");
    ofstream fout ("lgame.out");
    int num=0;
    string word;
    string in;
    while(fdict>>in&&in[0]!='.')
    {
        dict[++num]=in;
    }
    fin>>word;
    memset(flag,0,sizeof(flag));
    memset(value,0,sizeof(value));
    for(string::size_type i=0;i<word.size();i++)
        flag[word[i]-'a']++;

    int cnt=0;
    for(int i=1;i<=num;i++)
    {
        int j;
        for(j=0;j<26;j++)
            tmp[j]=flag[j];

        string::size_type x;
        for(x=0;x<dict[i].size();x++)
            if (tmp[dict[i][x]-'a'])
            {
                tmp[dict[i][x]-'a']--;
            }
            else
            {
                break;
            }
        if (x==dict[i].size())
        {
            now[++cnt]=dict[i];
            //cout<<now[cnt]<<endl;
            for(x=0;x<dict[i].size();x++)
                value[cnt]+=grade[dict[i][x]-'a'];
        }
    }
    /*
    printf("%d\n",num);
    printf("%d\n",cnt);
    for(int i=1;i<=cnt;i++)
        cout<<now[i]<<' '<<value[i]<<endl;
        */

    int ans=0,maxn;
    string::size_type x;
    for(int i=1;i<=cnt;i++)
    {
        bool repeat=true;
        int k=i;
        while(repeat)
        {
            int j;
            maxn=0;
            for(int j=0;j<26;j++)
                tmp[j]=flag[j];
            for(x=0;x<now[i].size();x++)
            {
                tmp[now[i][x]-'a']--;
            }
            maxn+=value[i];
            for(j=k+1;j<=cnt;j++)
            {
                memset(cost,0,sizeof(cost));
                for(x=0;x<now[j].size();x++)
                {
                    cost[now[j][x]-'a']++;
                }
                for(x=0;x<now[j].size();x++)
                {
                    if (tmp[now[j][x]-'a']>=cost[now[j][x]-'a']) continue;
                    else break;
                }
                if (x==now[j].size())
                {
                    k=j;
                    for(x=0;x<now[j].size();x++)
                    {
                        tmp[now[j][x]-'a']-=cost[now[j][x]-'a'];
                    }
                    maxn+=value[j];
                    //cout<<j<<endl;
                }
            }
            if (ans<maxn)
                ans=maxn;

            if (maxn==value[i])
                repeat=false;
        }
    }
    fout<<ans<<endl;

    int ans_num;
    for(int i=1;i<=cnt;i++)
    {
        bool repeat=true;
        int k=i;
        while(repeat)
        {
            int j;
            maxn=0;
            ans_num=0;
            for(int j=0;j<26;j++)
                tmp[j]=flag[j];
            for(x=0;x<now[i].size();x++)
            {
                tmp[now[i][x]-'a']--;
            }
            maxn+=value[i];
            ans_str[++ans_num]=now[i];
            for(j=k+1;j<=cnt;j++)
            {
                memset(cost,0,sizeof(cost));
                for(x=0;x<now[j].size();x++)
                {
                    cost[now[j][x]-'a']++;
                }
                for(x=0;x<now[j].size();x++)
                {
                    if (tmp[now[j][x]-'a']>=cost[now[j][x]-'a']) continue;
                    else break;
                }
                if (x==now[j].size())
                {
                    k=j;
                    ans_str[++ans_num]=now[j];
                    for(x=0;x<now[j].size();x++)
                    {
                        tmp[now[j][x]-'a']-=cost[now[j][x]-'a'];
                    }
                    maxn+=value[j];
                    //cout<<j<<endl;
                }
            }
            if (ans==maxn)
            {
                for(int j=1;j<ans_num;j++)
                    fout<<ans_str[j]<<' ';
                fout<<ans_str[ans_num]<<endl;
            }

            if (maxn==value[i])
                repeat=false;
        }
    }
    return 0;
}
