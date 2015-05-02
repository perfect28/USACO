/*
ID:perfect13
LANG:C++
TASK:fc
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define INF 0x7FFFFFFF
#define MAXN 10050
using namespace std;
/*
PointSet[]：输入的点集
ch[]：输出的凸包上的点集，按照逆时针方向排列
n：PointSet中的点的数目
len：输出的凸包上的点的个数
*/

struct Point
{
    double x,y;
};

Point PointSet[MAXN];
Point ch[MAXN];
int n;
int len;


//小于0,说明向量p0p1的极角大于p0p2的极角
double multiply(Point p1,Point p2,Point p0)
{
    return((p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y));
}

double dis(Point p1,Point p2)
{
    return(sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y)));
}


void Graham_scan(Point PointSet[],Point ch[],int n,int &len)
{
    int i,j,k=0,top=2;
    Point tmp;

    //找到最下且偏左的那个点
    for(i=1;i<n;i++)
        if ((PointSet[i].y<PointSet[k].y)||((PointSet[i].y==PointSet[k].y)&&(PointSet[i].x<PointSet[k].x)))
            k=i;
    //将这个点指定为PointSet[0]
    tmp=PointSet[0];
    PointSet[0]=PointSet[k];
    PointSet[k]=tmp;

    //按极角从小到大,距离偏短进行排序
    for (i=1;i<n-1;i++)
    {
        k=i;
        for (j=i+1;j<n;j++)
            if( (multiply(PointSet[j],PointSet[k],PointSet[0])>0)
                ||((multiply(PointSet[j],PointSet[k],PointSet[0])==0)
                    &&(dis(PointSet[0],PointSet[j])<dis(PointSet[0],PointSet[k]))) )
                k=j;//k保存极角最小的那个点,或者相同距离原点最近
        tmp=PointSet[i];
        PointSet[i]=PointSet[k];
        PointSet[k]=tmp;
    }
    //第三个点先入栈
    ch[0]=PointSet[0];
    ch[1]=PointSet[1];
    ch[2]=PointSet[2];
    //判断与其余所有点的关系
    for (i=3;i<n;i++)
    {
        //不满足向左转的关系,栈顶元素出栈
        while(multiply(PointSet[i],ch[top],ch[top-1])>=0) top--;
        //当前点与栈内所有点满足向左关系,因此入栈.
        ch[++top]=PointSet[i];
    }
    len=top+1;
}


int main()
{
    FILE *fin=fopen("fc.in","r");
    FILE *fout=fopen("fc.out","w");
    int n;
    fscanf(fin,"%d",&n);
    for(int i=0;i<n;i++)
    {
        fscanf(fin,"%lf%lf",&PointSet[i].x,&PointSet[i].y);
    }
    Graham_scan(PointSet,ch,n,len);

    double ans=dis(ch[0],ch[len-1]);
    for(int i=0;i<len-1;i++)
        ans+=dis(ch[i],ch[i+1]);
    fprintf(fout,"%.2lf\n",ans);
    return 0;
}

