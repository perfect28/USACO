 /*
ID:perfect13
LANG:C++
TASK:spin
*/
#include <iostream>
#include <cstdio>
#define INF 0x7FFFFFFF
#define MAXN 105000
using namespace std;


typedef struct{
    int st,len;
}Gap;

Gap gap[10][10];
int num[10];
int speed[10];
bool mark[400];

int main()
{
    FILE *fin=fopen("spin.in","r");
    FILE *fout=fopen("spin.out","w");
    for(int i=1;i<=5;i++)
    {
        fscanf(fin,"%d",&speed[i]);
        fscanf(fin,"%d",&num[i]);
        for(int j=1;j<=num[i];j++)
            fscanf(fin,"%d%d",&gap[i][j].st,&gap[i][j].len);
    }

    int time,degree;
    bool flag,ok;
    for(time=0;time<360;time++)
    {
        for(degree=0;degree<360;degree++)
        {
            flag=true;
            for(int i=1;i<=5;i++)
            {
                ok=false;
                for(int j=1;j<=num[i];j++)
                {
                    int st=(gap[i][j].st+speed[i]*time)%360;
                    int ed=(st+gap[i][j].len)%360;
                    if (st<ed)
                    {
                        if (degree>=st&&degree<=ed)
                        {
                            ok=true;
                            break;
                        }
                    }
                    else{
                        if (degree>=st||degree<=ed)
                        {
                            ok=true;
                            break;
                        }
                    }
                }
                if (ok)
                    continue;
                else {
                    flag=false;
                    break;
                }
            }
            if(flag) break;
        }
        if (flag){
            fprintf(fout,"%d\n",time);
            break;
        }
    }
    if (!flag) fprintf(fout,"none\n");
    return 0;
}
