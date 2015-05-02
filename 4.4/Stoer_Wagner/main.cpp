 #include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>

#define INT_MAX 0x7fffffff

using namespace std;

int tab[502][502];
int N,M;
bool combine[502];
int minC=INT_MAX;

/*
��s-t��С��ķ���
����w(A,x) = ��w(v[i],x)��v[i]��A
����AxΪ��xǰ����A�����е�ļ��ϣ�������x��
1.���A={a}��aΪV�������
2.ѡȡV-A�е�w(A,x)���ĵ�x���뼯��
3.��|A|=|V|���������������w(A,x)��ת��2
����ڶ�������A�ĵ�Ϊs�����һ������A�ĵ�Ϊt����s-t��С��Ϊw(At,t)
*/

void search(int &s,int &t){
    bool vis[502];
    int w[502];
    memset(vis,0,sizeof(vis));
    memset(w,0,sizeof(w));
    int ttabj=1000;
    for(int i=1;i<=N;i++){
        int max=-INT_MAX;
        for(int j=1;j<=N;j++){
            if(!vis[j]&&!combine[j]&&max<w[j]){
                max=w[j];
                ttabj=j;
            }
        }
        if(t==ttabj){minC=w[t];return;}
        vis[ttabj]=1;
        s=t,t=ttabj;
        for(int j=1;j<=N;j++){
            if(!vis[j]&&!combine[j])
                w[j]+=tab[t][j];
        }
    }
    minC=w[t];
}

int mincut(){
    int ans=INT_MAX;
    int s,t;
    memset(combine,0,sizeof(combine));
    for(int i=1;i<N;i++){
        s=t=-1;
        search(s,t);
        combine[t]=true;
        ans=ans>minC?minC:ans;
        for(int j=1;j<=N;j++){
            tab[s][j]+=tab[t][j];
            tab[j][s]+=tab[j][t];
        }
    }
    return ans;
}

int main(){
    freopen("milk6.in","r",stdin);
    while(cin>>N>>M){
        memset(tab,0,sizeof(tab));
        int u,v,w;
        while(M--){
            scanf("%d %d %d",&u,&v,&w);
            tab[u][v]+=w;
            tab[v][u]+=w;
        }
        cout<<mincut()<<endl;
    }
    return 0;
}
