/*
ID:perfect13
LANG:C++
TASK:fracdec
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

bool flag[105000];
int ans[1005000];


/*
此题错误百出：
1.循环节判断出错
2.前括号多次输出
3.每隔76个字符被忽略
4.0重复不能判断是循环
5.根本思路出错，应该用余数重复来判断循环节囧
6.如果可以整除，那么第一位小数的0要特殊处理
7.如果整数部分是0，换行要注意
*/

int main()
{
    FILE *fin=fopen("fracdec.in","r");
    FILE *fout=fopen("fracdec.out","w");
    int n,d;
    fscanf(fin,"%d%d",&n,&d);

    int it=0;
    if (n/d>=1)
    {
        it=n/d;
        n=n%d;
    }

    memset(flag,false,sizeof(flag));
    int num=0;
    int tick=-1;
    while(1)
    {
        if (flag[n])
        {
            tick=(n*10)/d;
            break;
        }
        flag[n]=true;
        if (n==0){
            if (num==0)
                ans[++num]=0;
            break;
        }
        ans[++num]=(n*10)/d;
        n=(n*10)%d;
    }

    int cnt=1;
    fprintf(fout,"%d.",it);

    if (it==0) cnt++;
    else
    while(it)
    {
        cnt++;
        it/=10;
    }


    bool once=true;
    for(int i=1;i<=num;i++)
    {
        if (cnt%76==0)
            fprintf(fout,"\n");
        if (ans[i]==tick&&i<num)
        {
            if (once){
                fprintf(fout,"(");
                cnt++;
                once=false;
            }
        }

        fprintf(fout,"%d",ans[i]);
        cnt++;

        if (i==num&&tick!=-1){
            fprintf(fout,")");
        }
    }
    fprintf(fout,"\n");
    return 0;
}
