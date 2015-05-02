/*
ID:perfect13
LANG:C++
TASK:sprime
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define MAXN 10000
using namespace std;

int st,ed;
bool prime[MAXN];
int prime_list[MAXN];
int num;

void initiate()
{
    memset(prime,true,sizeof(prime));
    prime[0]=false;
    prime[1]=false;
    for(int i=2;i<MAXN;i++)
        if (prime[i])
        {
            prime_list[++num]=i;
            for(int j=i+i;j<MAXN;j+=i)
                prime[j]=false;
        }
}

bool is_prime(int k)
{
    if (k<MAXN){
        if (prime[k]) return true;
        else return false;
    }
    for(int i=1;i<=num;i++)
        if (k%prime_list[i]==0) return false;
    return true;
}

int n;
FILE *fin=fopen("sprime.in","r");
FILE *fout=fopen("sprime.out","w");

void dfs(int num,int k)
{
    if (!is_prime(num)) return;
    if (k>=n)
    {
        fprintf(fout,"%d\n",num);
        return;
    }
    for(int i=1;i<=9;i+=2){
        int temp=num*10+i;
        dfs(temp,k+1);
    }
}

int main()
{
    fscanf(fin,"%d",&n);
    initiate();
    int pri[4]={2,3,5,7};
    for(int i=0;i<4;i++)
        dfs(pri[i],1);
    return 0;
}
