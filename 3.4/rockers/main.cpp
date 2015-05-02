 /*
ID:perfect13
LANG:C++
TASK:rockers
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#define INF 0x7FFFFFFF
#define MAXN 105
using namespace std;

int n,t,m;
int cost[30];
int v[30];


/*dp方法：
分析:此题有一个很明显的背包模型,
但是这道题不是一个背包,而是多个背包.
所以不能用经典背包问题去解,这里需要在加一维.
设f[i,j,k]表示前i个歌曲,第i个歌曲末为j分钟的,
前k张碟所加入的最大歌曲数,那么决策就好想了:
不要i歌,要i歌.不要:f[i,j,k]=f[i-1,j,k].
要:f[i,j,k]=max{f[i-1,j-a[i],k],f[i-1,v,k-1]}+1
(因为选择这首歌,所以j>=a[i]).
那么我们发现i这维大概是多余的,所以需要进行下优化(虽然n<=20).
类似于01背包二维转为一维.将k和j倒着循环来保证只取一次.
所以最终方程:
     f[j,k]=max{f[j,k],f[v,k-1]+1,f[j-a[i],k]+1}
核心代码:
    readln(n,v,m); {不解释}
    fillchar(f,sizeof(f),0);
    for i:=1 to n do
      begin
        read(x);
        for k:=m downto 1 do
          for j:=v downto x do
            f[j,k]:=max(f[j,k],max(f[v,k-1],f[j-x,k])+1);
      end;
    writeln(f[v,m]);
小结:经过优化后跑的很快.


*/

int main()
{
    FILE *fin=fopen("rockers.in","r");
    FILE *fout=fopen("rockers.out","w");
    int ans=0;
    fscanf(fin,"%d%d%d",&n,&t,&m);
    for(int i=1;i<=n;i++)
        fscanf(fin,"%d",&cost[i]);
    for(int i=0;i<(1<<n);i++)
    {
        int num=0;
        for(int j=1;j<=m;j++)
            v[j]=t;
        int now=1;
        int k=i;
        for(int j=1;j<=n;j++)
        {
            if (k&1)//选中该物品
            {
                if (v[now]>=cost[j])
                    v[now]-=cost[j];
                else{
                    while(v[now]<cost[j]&&now<=m)
                        now++;
                    if (now>m)
                        break;
                    v[now]-=cost[j];
                }
                num++;
            }
            k=k>>1;
        }
        if (ans<num)
            ans=num;
    }
    fprintf(fout,"%d\n",ans);
    return 0;
}
