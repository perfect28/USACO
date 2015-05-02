 /*
ID:perfect13
LANG:C++
TASK:heritage
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#define INF 0x7FFFFFFF
#define MAXN 105
using namespace std;

typedef struct bitnode
{
    char data;
    struct bitnode *lchild,*rchild;
}bitnode,*bitree;

bitree root;
char InOrder[30];
char PreOrder[30];

FILE *fin=fopen("heritage.in","r");
FILE *fout=fopen("heritage.out","w");

bitree create(char *pre,char *in,int len)
{
    int k;
    if (len<=0) return NULL;
    bitree t=(bitree)malloc(sizeof(bitnode));
    t->data=*pre;
    char *p;
    for(p=in;*p;p++)
        if (*p==*pre) break;
    k=p-in;
    t->lchild=create(pre+1,in,k);
    t->rchild=create(pre+k+1,p+1,len-1-k);
    return t;
}

void postorder(bitree root)
{
    if (root!=NULL){
        postorder(root->lchild);
        postorder(root->rchild);
        fprintf(fout,"%c",root->data);
    }
}
int main()
{
    fscanf(fin,"%s",InOrder);
    fscanf(fin,"%s",PreOrder);
    int len=strlen(InOrder);
    root=(bitree)malloc(sizeof(bitnode));
    root=create(PreOrder,InOrder,len);
    postorder(root);
    fprintf(fout,"\n");
    return 0;
}
