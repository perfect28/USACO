/*
ID:perfect13
LANG:C++
TASK:sort3
*/
#include <iostream>
#include <cstdio>
#define MAXN 1050
using namespace std;

int arr[MAXN];
int cnt[4];
int solve[4][4];
int main()
{
    FILE *fin=fopen("sort3.in","r");
    FILE *fout=fopen("sort3.out","w");
    int n;
    fscanf(fin,"%d",&n);
    for(int i=1;i<=n;i++){
        fscanf(fin,"%d",&arr[i]);
        cnt[arr[i]]++;
    }
    for(int i=1;i<=n;i++){
        switch(arr[i]){
        case 1:
            if (i>cnt[1]&&i<=cnt[1]+cnt[2])
                solve[2][1]++;
            if (i>cnt[1]+cnt[2])
                solve[3][1]++;
            break;
        case 2:
            if (i<=cnt[1])
                solve[1][2]++;
            if (i>cnt[1]+cnt[2])
                solve[3][2]++;
            break;
        case 3:
            if (i<=cnt[1])
                solve[1][3]++;
            if (i>cnt[1]&&i<=cnt[1]+cnt[2])
                solve[2][3]++;
            break;
        }
    }
    int sum=solve[1][2]+solve[1][3]+solve[2][1]+solve[2][3]+solve[3][1]+solve[3][2];
    int ans=0;
    for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++)
        if (i!=j)
        {
            while(solve[i][j]&&solve[j][i])
            {
                ans+=1;
                solve[i][j]--;
                solve[j][i]--;
                sum-=2;
            }
        }
    ans+=(sum/3)*2;
    fprintf(fout,"%d\n",ans);
    return 0;
}
