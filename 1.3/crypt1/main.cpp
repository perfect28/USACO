/*
ID:perfect13
LANG:C++
TASK:crypt1
*/
#include <iostream>
#include <cstdio>
using namespace std;

int n;
int num[20];

bool inNum(int k){
    int now=k;
    while(now){
        int t=now%10;
        int i;
        for(i=1;i<=n;i++)
            if (t==num[i]) break;
        if (i>n) return false;
        now=now/10;
    }
    return true;
}

int main()
{
    FILE *fin=fopen("crypt1.in","r");
    FILE *fout=fopen("crypt1.out","w");
    fscanf(fin,"%d",&n);
    for(int i=1;i<=n;i++)
        fscanf(fin,"%d",&num[i]);
    int ans=0;
    for(int i=100;i<=999;i++)
        for(int j=10;j<=99;j++)
            if (i*(j%10)<1000&&i*(j/10)<1000)
                if (i*j<10000)
                    if (inNum(i))
                        if (inNum(j))
                            if (inNum(i*(j%10)))
                                if (inNum(i*(j/10)))
                                    if (inNum(i*j))
                                        ans++;
    fprintf(fout,"%d\n",ans);
    return 0;
}
