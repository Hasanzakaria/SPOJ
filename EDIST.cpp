#include<bits/stdc++.h>
using namespace std;
string a,b;
long long int k,l;
long long int dip[2000][2000];
long long int dp(long long int i,long long int j)
{
    if(i==k)
    {
        return l-j;
    }
    else if(j==l)
    {
        return k-i;
    }
    if(dip[i][j]!=-1)
    {
        return dip[i][j];
    }
    long long int t,u,f,r;
    if(a[i]==b[j])
    {
        t=dp(i+1,j+1);
    }
    else
    {
        u=1+dp(i+1,j);
        f=1+dp(i+1,j+1);
        r=1+dp(i,j+1);
        t=min(u,f);
        t=min(t,r);
    }
    dip[i][j]=t;
    return dip[i][j];
}
int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long int n,i,f;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a>>b;
        k=a.size();
        l=b.size();
        memset(dip,-1,sizeof(dip));
        f=dp(0,0);
        cout<<f<<endl;
    }

}
