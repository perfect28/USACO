 /*
ID:perfect13
LANG:C++
TASK:contact
*/
#include <iostream>
#include <map>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

typedef map<string,int> Cnt;
Cnt cnt;
typedef pair<string,int> pp;
vector<pp> vt;

int cmp(pp u,pp v)
{
    if (u.second==v.second)
    {
        if (u.first.size()==v.first.size())
            return u.first>v.first;
        else return u.first.size()>v.first.size();
    }
    else
        return u.second<v.second;
}

int main()
{
    ifstream fin ("contact.in");
    ofstream fout ("contact.out");
    int a,b,n;
    string str="";
    fin>>a>>b>>n;
    //cout<<a<<' '<<b<<' '<<n<<endl;
    string tmp="";
    while(getline(fin,tmp))
    {
        str+=tmp;
        //cout<<str<<endl;
    }


    for(int i=0;i<=-1;i++)
    {
        int num=0;
        num++;
        num++;
    }

    string sub;
    int ll=str.size();
    for(int len=a;len<=b;len++)
        for(int st=0;st<=ll-len;st++)
    {
        sub=str.substr(st,len);
        cnt[sub]++;
    }



    Cnt::iterator it=cnt.begin();
	while(it!=cnt.end()){
		vt.push_back(make_pair(it->first,it->second));
		++it;
	}

	sort(vt.begin(),vt.end(),cmp);


    int num=0;
    int next_line=0;
    for(int i=vt.size()-1;i>=0;i--)
    {
        if (i==vt.size()-1||vt[i].second!=vt[i+1].second)
        {
            num++;
            if (num>n) break;
            next_line=1;
            if (i!=vt.size()-1)
                fout<<endl;
            fout<<vt[i].second<<endl;
            fout<<vt[i].first;
        }
        else{
            next_line++;
            if (next_line>6)
            {
                fout<<endl;
                fout<<vt[i].first;
                next_line=1;
            }
            else
                fout<<" "<<vt[i].first;
        }
    }

    fout<<endl;
    return 0;
}
