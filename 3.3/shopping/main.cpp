 /*
ID:perfect13
LANG:C++
TASK:shopping
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#define INF 0x7FFFFFFF
#define MAXN 105000
using namespace std;


struct Coupon{
    int num;
    int price;
    int id[10];
    int quan[10];
}coupon[100];

struct Goods{
    int id;
    int price;
    int need;
}goods[1000];

int dp[6][6][6][6][6];

int main()
{
    FILE *fin=fopen("shopping.in","r");
    FILE *fout=fopen("shopping.out","w");
    int s;
    fscanf(fin,"%d",&s);
    for(int i=1;i<=s;i++)
    {
        fscanf(fin,"%d",&coupon[i].num);
        for(int j=1;j<=coupon[i].num;j++)
            fscanf(fin,"%d%d",&coupon[i].id[j],&coupon[i].quan[j]);
        fscanf(fin,"%d",&coupon[i].price);
    }
    int n;
    fscanf(fin,"%d",&n);
    for(int i=1;i<=n;i++)
        fscanf(fin,"%d%d%d",&goods[i].id,&goods[i].need,&goods[i].price);
    int i[6];

    for(i[1]=0;i[1]<=5;i[1]++)
     for(i[2]=0;i[2]<=5;i[2]++)
      for(i[3]=0;i[3]<=5;i[3]++)
       for(i[4]=0;i[4]<=5;i[4]++)
        for(i[5]=0;i[5]<=5;i[5]++)
        {
            int now=0;
            for(int j=1;j<=5;j++)
                now+=i[j]*goods[j].price;
                dp[i[1]][i[2]][i[3]][i[4]][i[5]]=now;
        }

    for(int k=1;k<=s;k++)
    {
        for(i[1]=0;i[1]<=5;i[1]++)
        for(i[2]=0;i[2]<=5;i[2]++)
        for(i[3]=0;i[3]<=5;i[3]++)
        for(i[4]=0;i[4]<=5;i[4]++)
        for(i[5]=0;i[5]<=5;i[5]++)
        {
            int d[10];
            bool ok=true;
            for(int j=1;j<=5;j++)
                d[j]=i[j];
            for(int j=1;j<=coupon[k].num;j++)
            {
                for(int t=1;t<=n;t++)
                if(coupon[k].id[j]==goods[t].id)
                {
                    if (i[t]>=coupon[k].quan[j])
                    {
                        d[t]=i[t]-coupon[k].quan[j];
                        break;
                    }
                    else ok=false;
                }
            }
            if(ok)
            {
                dp[i[1]][i[2]][i[3]][i[4]][i[5]]=min(dp[i[1]][i[2]][i[3]][i[4]][i[5]],
                                                     dp[d[1]][d[2]][d[3]][d[4]][d[5]]+coupon[k].price);
            }
        }
    }

    fprintf(fout,"%d\n",dp[goods[1].need][goods[2].need][goods[3].need][goods[4].need][goods[5].need]);
    return 0;
}

