#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdio>
using namespace std;
struct Node{
    int x, y;
}node;
 bool operator<( Node a, Node b){
    if(a.x==b.x) return a.y>b.y;
    return a.x>b.x;
}

struct cmp{
    bool operator()(Node a,Node b){
        if(a.x==b.x) return a.y>b.y;
        return a.x>b.x;}
};

int cmp(int u,int v)
{
    return u>v;
}
int main(){
    int a[8]={1,3,2,4,3,6,4,3};
    for(int i=0;i<8;i++)
        printf("%d ",a[i]);
    cout<<endl;
    sort(a,a+8,cmp);
    for(int i=0;i<8;i++)
        printf("%d ",a[i]);
    cout<<endl;
    priority_queue<Node>q;

    for(int i=0;i<10;i++){
        node.x=i;
        node.y=10-i/2;
        q.push(node);
    }
    while(!q.empty()){
        cout<<q.top().x <<' '<<q.top().y<<endl;
        q.pop();
    }
    /*
    priority_queue<Node,vector<Node>,cmp>p;
    for(int i=0;i<10;i++){
        node.x=i;
        node.y=10-i/2;
        p.push(node);
    }
    while(!p.empty()){
        cout<<p.top().x<<' '<<p.top().y<<endl;
        p.pop();
    }
    */
    return 0;
}
