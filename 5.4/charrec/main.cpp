/*
ID:perfect13
LANG:C++
TASK:charrec
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <string>
#define INF 0x7FFFFFFF
#define MAXN 150
using namespace std;


string dict[30][20];
int num;

int main()
{
    ifstream font("font.in");
    ifstream fin("charrec.in");
    ofstream fout("charrec.out");
    font>>num;
    for(int i=1;i<=num/20;i++)
        for(int j=0;j<20;j++)
            font>>dict[i][j];

    for(int i=1;i<=10;i++)
    {
        for(int j=0;j<20;j++)
            cout<<dict[i][j]<<endl;
        cout<<endl;
    }


    return 0;
}
