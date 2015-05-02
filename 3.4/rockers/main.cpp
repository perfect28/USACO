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


/*dp������
����:������һ�������Եı���ģ��,
��������ⲻ��һ������,���Ƕ������.
���Բ����þ��䱳������ȥ��,������Ҫ�ڼ�һά.
��f[i,j,k]��ʾǰi������,��i������ĩΪj���ӵ�,
ǰk�ŵ����������������,��ô���߾ͺ�����:
��Ҫi��,Ҫi��.��Ҫ:f[i,j,k]=f[i-1,j,k].
Ҫ:f[i,j,k]=max{f[i-1,j-a[i],k],f[i-1,v,k-1]}+1
(��Ϊѡ�����׸�,����j>=a[i]).
��ô���Ƿ���i��ά����Ƕ����,������Ҫ�������Ż�(��Ȼn<=20).
������01������άתΪһά.��k��j����ѭ������ֻ֤ȡһ��.
�������շ���:
     f[j,k]=max{f[j,k],f[v,k-1]+1,f[j-a[i],k]+1}
���Ĵ���:
    readln(n,v,m); {������}
    fillchar(f,sizeof(f),0);
    for i:=1 to n do
      begin
        read(x);
        for k:=m downto 1 do
          for j:=v downto x do
            f[j,k]:=max(f[j,k],max(f[v,k-1],f[j-x,k])+1);
      end;
    writeln(f[v,m]);
С��:�����Ż����ܵĺܿ�.


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
            if (k&1)//ѡ�и���Ʒ
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
