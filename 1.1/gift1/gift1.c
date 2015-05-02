/*
ID:perfect13
LANG:C
TASK:gift1
*/
#include<stdio.h>
#include<string.h>
int main()
{
	FILE *fin=fopen("gift1.in","r");
	FILE *fout=fopen("gift1.out","w");
	int n,i,j,t,k,m[15],num,mm;
	char a[11][15],s[15];
	fscanf(fin,"%d",&n);
	for(i=1;i<=n;i++)
	{fscanf(fin,"%s",a[i]);m[i]=0;}
	for(i=1;i<=n;i++)
	{
		fscanf(fin,"%s",s);
		for(j=1;j<=n;j++)
			if (strcmp(s,a[j])==0) {k=j;break;}
		fscanf(fin,"%d%d",&mm,&num);
		for(j=1;j<=num;j++)
		{
			fscanf(fin,"%s",s);
			for(t=1;t<=n;t++)
			if (strcmp(s,a[t])==0) {m[t]+=(mm/num);break;}
		}
		if (num!=0) m[k]-=(mm-mm%num);
	}
	for(i=1;i<=n;i++)
		fprintf(fout,"%s %d\n",a[i],m[i]);
return 0;
}