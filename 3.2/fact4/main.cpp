 /*
ID:perfect13
LANG:C++
TASK:fact4
*/
#include <iostream>
#include <cstdio>
#define INF 0x7FFFFFFF
#define MAXN 105000
using namespace std;

int main()
{
    FILE *fin=fopen("fact4.in","r");
    FILE *fout=fopen("fact4.out","w");
    int n;
    fscanf(fin,"%d",&n);
    int product=1;
    for(int i=1;i<=n;i++)
    {
        product*=i;
        while (product%10==0)
            product/=10;
        product=product%10000;
    }

    fprintf(fout,"%d\n",product%10);
    return 0;
}
