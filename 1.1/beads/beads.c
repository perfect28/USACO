/*
ID:perfect13
LANG:C
TASK:beads
*/
#include<stdio.h>
#include<string.h>
int main()
{
	FILE *fin=fopen("beads.in","r");
	FILE *fout=fopen("beads.out","w");
	int n,i,j,num,max=0,l,r,k;
	char s[1000],ss[1000];
	fscanf(fin,"%d",&n);
	fscanf(fin,"%s",s);
	strcpy(ss,s);
	strcat(s,ss);
	for(i=0;i<=2*n-1;i++)
	{
		k=i+1;while (s[k]=='w') k++;
		if ((s[i]=='r'&&s[k]=='b')||(s[i]=='b'&&s[k]=='r'))
		{
			l=i;r=k;num=2+k-i-1;
			while ((--l>=0) && (s[l]==s[i]||s[l]=='w')) num++;
			while ((++r<=2*n-1) && (s[r]==s[i+1]||s[r]=='w')) num++;
			if (num>max) max=num;
		}
	}
	if (max==0||max>n) fprintf(fout,"%d\n",n);
	else fprintf(fout,"%d\n",max);
	return 0;
}