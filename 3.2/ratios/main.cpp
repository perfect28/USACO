 /*
ID:perfect13
LANG:C++
TASK:ratios
*/
#include <iostream>
#include <cstdio>
#define INF 0x7FFFFFFF
#define MAXN 105000
using namespace std;


int b[4];
int d[4][4][4];

int cnt_matrix(int m[4][4])
{
    int value;
    value=m[1][1]*m[2][2]*m[3][3]+m[1][2]*m[2][3]*m[3][1];
    value+=(m[2][1]*m[3][2]*m[1][3]-m[1][3]*m[2][2]*m[3][1]);
    value-=(m[1][2]*m[2][1]*m[3][3]+m[2][3]*m[3][2]*m[1][1]);
    return value;
}


int main()
{
    FILE *fin=fopen("ratios.in","r");
    FILE *fout=fopen("ratios.out","w");
    for(int i=1;i<=3;i++)
        fscanf(fin,"%d",&b[i]);
    for(int j=1;j<=3;j++)
        for(int i=1;i<=3;i++)
        fscanf(fin,"%d",&d[0][i][j]);

    for(int k=1;k<=3;k++)
        for(int i=1;i<=3;i++)
            for(int j=1;j<=3;j++)
                d[k][i][j]=d[0][i][j];



    int k=0;
    int tmp[4];
    bool ok=false;
    while(k<=100)
    {
        k++;
        for(int i=1;i<=3;i++)
            tmp[i]=k*b[i];
        for(int i=1;i<=3;i++)
            d[1][i][1]=tmp[i];
        for(int i=1;i<=3;i++)
            d[2][i][2]=tmp[i];
        for(int i=1;i<=3;i++)
            d[3][i][3]=tmp[i];

        int de=cnt_matrix(d[0]);
        if (de==0)
        {
            break;
        }

        int d1=cnt_matrix(d[1]);
        int d2=cnt_matrix(d[2]);
        int d3=cnt_matrix(d[3]);
        if (d1%de==0&&d2%de==0&&d3%de==0)
            if (d1/de>=0&&d2/de>=0&&d3/de>=0)
        {
            fprintf(fout,"%d %d %d %d\n",d1/de,d2/de,d3/de,k);
            ok=true;
            break;
        }
    }

    if (!ok)
        fprintf(fout,"NONE\n");

    return 0;
}
