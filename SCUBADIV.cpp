#include<bits/stdc++.h>
using namespace std;
long long int aa,bb,m;
long long int oxy[1000],nit[1000],weight[1000];
long long int check[1010][25][80];
long long int dp(long long int a,long long int b,long long int c)
{
    if(b<0)
    {
        b=0;
    }
    if(c<0)
    {
        c=0;
    }
    if(b==0&&c==0)
    {
        return 0;
    }
    if(a==m)
    {
        return 100000000000;
    }
    if(check[a][b][c]!=-1)
    {
        return check[a][b][c];
    }
    long long int k,l;
    k=weight[a]+dp(a+1,b-oxy[a],c-nit[a]);
    l=dp(a+1,b,c);
    check[a][b][c]=min(k,l);
    return check[a][b][c];
}
int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long int n,i,j,p;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>aa>>bb;
        cin>>m;
        for(j=1;j<=m;j++)
        {
          cin>>oxy[j-1]>>nit[j-1]>>weight[j-1];
        }
        memset(check,-1,sizeof(check));
        p=dp(0,aa,bb);
        cout<<p<<"\n";
    }

}
