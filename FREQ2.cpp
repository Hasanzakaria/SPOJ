#include<bits/stdc++.h>
using namespace std;
int ara[100000];
int cou[100001],anss;
int check[100001];
struct node
{
    int a,b,c,d;
};
vector<node>v;
vector<node>::iterator e;
node temp;
bool cmp(node x,node y)
{
    if(x.a<y.a)
    {
        return 1;
    }
    else if(x.a==y.a)
    {
        return x.c<y.c;
    }
    return 0;
}
void removee(int pos)
{

    check[cou[ara[pos]]]--;
    if(check[cou[ara[pos]]]==0&&anss==cou[ara[pos]])
    {
        anss=cou[ara[pos]]-1;
    }
    cou[ara[pos]]--;
    check[cou[ara[pos]]]++;

}
void add(int pos)
{
    check[cou[ara[pos]]]--;
    cou[ara[pos]]++;
    check[cou[ara[pos]]]++;
    anss=max(anss,cou[ara[pos]]);
}
int main ()
{
    int n,m,i,j,x,y,l,currentl,currentr,w,r;
    scanf("%d %d",&n,&m);
    for(i=0; i<n; i++)
    {
        scanf("%d",&ara[i]);
    }
    l=ceil(sqrt(n));
    int ans[m+1];
    for(j=1; j<=m; j++)
    {
        scanf("%d %d",&x,&y);
        temp.a=x/l;
        temp.b=x;
        temp.c=y;
        temp.d=j;
        v.push_back(temp);
    }
    sort(v.begin(),v.end(),cmp);
    currentl=0;
    currentr=0;
    cou[ara[0]]++;
    check[cou[ara[0]]]=1;
    anss=1;
    for(e=v.begin(); e!=v.end(); e++)
    {
        temp=*e;
        w=temp.b;
        r=temp.c;
        while(currentl<w)
        {
            removee(currentl);
            currentl++;
        }
        while(currentl>w)
        {
            add(currentl-1);
            currentl--;
        }
        while(currentr<r)
        {
            add(currentr+1);
            currentr++;
        }
        while(currentr>r)
        {
            removee(currentr);
            currentr--;
        }
        ans[temp.d]=anss;
    }
    for(j=1; j<=m; j++)
    {
        printf("%d\n",ans[j]);
    }

}
