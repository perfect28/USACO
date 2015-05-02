/*
ID:perfect13
LANG:C++
TASK:pprime
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#define MAXN 10000
using namespace std;

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

vector<int> result;
void dfs(int num,int len)
{
    if (len>8) return;
    if(is_prime(num))
        result.push_back(num);
    int factor=10;
    for(int i=0;i<len;i++)
        factor*=10;

    for(int i=0;i<10;i++)
    {
        int tmp=i*factor+num*10+i;
        dfs(tmp,len+2);
    }
}
int main()
{
    FILE *fin=fopen("pprime.in","r");
    FILE *fout=fopen("pprime.out","w");
    int a,b;
    fscanf(fin,"%d%d",&a,&b);
    initiate();
    for(int i=0;i<=9;i++)
        dfs(i,1);
    result.push_back(11);
    sort(result.begin(),result.end());
    for(int i=0;i<result.size();i++)
        if (result[i]>=a&&result[i]<=b)
        fprintf(fout,"%d\n",result[i]);
    return 0;
}
