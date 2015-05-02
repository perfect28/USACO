/*
ID:perfect13
LANG:C++
TASK:skidesign
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define INF 0x7f7f7f7f
using namespace std;

int num[1050];

int main()
{
    FILE *fin=fopen("skidesign.in","r");
    FILE *fout=fopen("skidesign.out","w");
    int n;
    fscanf(fin,"%d",&n);
    for(int i=1;i<=n;i++)
        fscanf(fin,"%d",&num[i]);
    sort(num+1,num+1+n);
    int ans=INF,sum;
    int st,ed;
    int d=num[n]-num[1]-17;
    if (d<=0)
        ans=0;
    else{
        for(int i=0;i<=d;i++)
        {
            st=num[1]+i;
            ed=st+17;
            sum=0;
            for(int j=1;j<=n;j++)
                if (num[j]<st)
                    sum+=(st-num[j])*(st-num[j]);
                else
                    break;

            for(int j=n;j>=1;j--)
                if (num[j]>ed)
                    sum+=(num[j]-ed)*(num[j]-ed);
                else
                    break;
            if (ans>sum)
                ans=sum;
        }
    }

    fprintf(fout,"%d\n",ans);
    return 0;
}
