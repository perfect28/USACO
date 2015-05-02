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
PointSet[]������ĵ㼯
ch[]�������͹���ϵĵ㼯��������ʱ�뷽������
n��PointSet�еĵ����Ŀ
len�������͹���ϵĵ�ĸ���
*/

struct Point
{
    double x,y;
};

Point PointSet[MAXN];
Point ch[MAXN];
int n;
int len;


//С��0,˵������p0p1�ļ��Ǵ���p0p2�ļ���
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

    //�ҵ�������ƫ����Ǹ���
    for(i=1;i<n;i++)
        if ((PointSet[i].y<PointSet[k].y)||((PointSet[i].y==PointSet[k].y)&&(PointSet[i].x<PointSet[k].x)))
            k=i;
    //�������ָ��ΪPointSet[0]
    tmp=PointSet[0];
    PointSet[0]=PointSet[k];
    PointSet[k]=tmp;

    //�����Ǵ�С����,����ƫ�̽�������
    for (i=1;i<n-1;i++)
    {
        k=i;
        for (j=i+1;j<n;j++)
            if( (multiply(PointSet[j],PointSet[k],PointSet[0])>0)
                ||((multiply(PointSet[j],PointSet[k],PointSet[0])==0)
                    &&(dis(PointSet[0],PointSet[j])<dis(PointSet[0],PointSet[k]))) )
                k=j;//k���漫����С���Ǹ���,������ͬ����ԭ�����
        tmp=PointSet[i];
        PointSet[i]=PointSet[k];
        PointSet[k]=tmp;
    }
    //������������ջ
    ch[0]=PointSet[0];
    ch[1]=PointSet[1];
    ch[2]=PointSet[2];
    //�ж����������е�Ĺ�ϵ
    for (i=3;i<n;i++)
    {
        //����������ת�Ĺ�ϵ,ջ��Ԫ�س�ջ
        while(multiply(PointSet[i],ch[top],ch[top-1])>=0) top--;
        //��ǰ����ջ�����е����������ϵ,�����ջ.
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

