/*
ID:perfect13
LANG:C++
TASK:numtri
*/
#include <iostream>
#include <cstdio>
using namespace std;

int matrix[1050][1050];
int ans[1050][1050];
int main()
{
    FILE *fin=fopen("numtri.in","r");
    FILE *fout=fopen("numtri.out","w");
    int n;
    fscanf(fin,"%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        if (i>=j)
        fscanf(fin,"%d",&matrix[i][j]);
    for(int i=1;i<=n;i++)
        ans[n][i]=matrix[n][i];
    for(int i=n-1;i>=1;i--)
        for(int j=1;j<=n;j++)
        if (i>=j)
        ans[i][j]=max(ans[i+1][j],ans[i+1][j+1])+matrix[i][j];
    fprintf(fout,"%d\n",ans[1][1]);
    return 0;
}
