/*
ID: perfect13
LANG: C
TASK: ride
*/
#include<stdio.h>
#include<string.h>
int main() 
{
    FILE *fin  = fopen ("ride.in", "r");
    FILE *fout = fopen ("ride.out", "w");
    char a[7],b[7];
	int i,j,sum1=1,sum2=1;
    fscanf(fin,"%s%s", a,b);
	for(i=0;i<=strlen(a);i++)
		sum1=(sum1*(a[i]-64))%47;
	for(j=0;j<=strlen(b);j++)
		sum2=(sum2*(b[j]-64))%47;
	if (sum1==sum2) fprintf(fout, "GO\n");
	else fprintf(fout,"STAY\n");
    return 0;
}

