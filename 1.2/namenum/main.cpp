/*
ID:perfect13
LANG:C++
TASK:namenum
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int num=0,ans_num;
bool flag=false;
char ans[5050][15];
char dict[5050][15];
char num_str[15];
char arr[5050][15];


void find_in_dict(char str[]){
    for(int i=1;i<=num;i++)
        if (strcmp(str,arr[i])==0)
        {
            strcpy(ans[++ans_num],dict[i]);
            flag=true;
        }
}

void transfer()
{
    for(int i=1;i<=num;i++)
    {
        for(int j=0;j<strlen(dict[i]);j++){
            switch(dict[i][j]){
            case 'A':case 'B':case 'C':
                arr[i][j]='2';
                break;
            case 'D':case 'E':case 'F':
                arr[i][j]='3';
                break;
            case 'G':case 'H':case 'I':
                arr[i][j]='4';
                break;
            case 'J':case 'K':case 'L':
                arr[i][j]='5';
                break;
            case 'M':case 'N':case 'O':
                arr[i][j]='6';
                break;
            case 'P':case 'R':case 'S':
                arr[i][j]='7';
                break;
            case 'T':case 'U':case 'V':
                arr[i][j]='8';
                break;
            case 'W':case 'X':case 'Y':
                arr[i][j]='9';
                break;
            default:
                arr[i][j]='0';
            }
        }
    }
}

int main()
{
    FILE *fin=fopen("namenum.in","r");
    FILE *fout=fopen("namenum.out","w");
    FILE *ftest=fopen("dict.txt","r");
    while(fscanf(ftest,"%s",dict[++num])!=EOF){
    }
    fscanf(fin,"%s",num_str);
    transfer();

    find_in_dict(num_str);

    if (flag)
        for(int i=1;i<=ans_num;i++)
        fprintf(fout,"%s\n",ans[i]);
    else
        fprintf(fout,"NONE\n");

    return 0;
}
