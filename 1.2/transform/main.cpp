/*
ID:perfect13
LANG:C++
TASK:transform
*/
#include <iostream>
#include <cstdio>
using namespace std;
int n;
char matrix[15][15],tmp[15][15],cmp[15][15];
char t[15][15];

bool compare(char s[][15])
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        if (cmp[i][j]==s[i][j]) continue;
        else return false;
    return true;
}

bool turn_ninety(char s[][15],char t[][15]){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            s[j][n-1-i]=t[i][j];
        }
    if (compare(s)) return true;
    else return false;
}

bool turn_one_eighty(char s[][15],char t[][15]){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            s[n-1-i][n-1-j]=t[i][j];
        }
    if (compare(s)) return true;
    else return false;
}

bool turn_back_ninety(char s[][15],char t[][15]){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            s[n-1-j][i]=t[i][j];
        }
    if (compare(s)) return true;
    else return false;
}

void mirror_image(char s[][15]){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            s[i][n-1-j]=matrix[i][j];
        }
}

bool combination(char s[][15]){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        t[i][j]=s[i][j];
    mirror_image(t);
    if (turn_ninety(tmp,t)||turn_one_eighty(tmp,t)||turn_back_ninety(tmp,t))
        return true;
    else return false;
}

int main()
{
    FILE *fin=fopen("transform.in","r");
    FILE *fout=fopen("transform.out","w");
    fscanf(fin,"%d",&n);
    for(int i=0;i<n;i++)
        fscanf(fin,"%s",matrix[i]);
    for(int i=0;i<n;i++)
        fscanf(fin,"%s",cmp[i]);
    if (turn_ninety(tmp,matrix)) {fprintf(fout,"1\n");return 0;}
    if (turn_one_eighty(tmp,matrix)) {fprintf(fout,"2\n");return 0;}
    if (turn_back_ninety(tmp,matrix)) {fprintf(fout,"3\n");return 0;}

    mirror_image(tmp);
    if (compare(tmp)) {fprintf(fout,"4\n");return 0;}

    if (combination(tmp)) {fprintf(fout,"5\n");return 0;}

    if (compare(matrix)) {fprintf(fout,"6\n");return 0;}
    fprintf(fout,"7\n");
    return 0;
}
