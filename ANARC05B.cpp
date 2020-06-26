#include<bits/stdc++.h>
using namespace std;
map<int,int>cp;
int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,i,m,sum,l,r;
    while(cin>>n)
    {
        sum=0;
        if(n==0)
        {
            break;
        }
        int ara[n+1],kar[n+1];
        ara[0]=0;
        for(i=1;i<=n;i++)
        {
            cin>>ara[i];
            kar[i]=ara[i];
        }
        cin>>m;
        int tak[m+1];
        tak[0]=0;
        for(i=1;i<=m;i++)
        {
            cin>>tak[i];
            cp[tak[i]]=i;
        }
        for(i=1;i<=n;i++)
        {
            ara[i]=ara[i-1]+ara[i];
        }
        for(i=1;i<=m;i++)
        {
            tak[i]=tak[i-1]+tak[i];
        }
        l=0;
        r=0;
        for(i=1;i<=n;i++)
        {
           if(cp[kar[i]]!=0)
           {
             sum+=max(ara[i]-ara[l],tak[cp[kar[i]]]-tak[r]);
             l=i;
             r=cp[kar[i]];
           }
        }
        sum+=max(ara[n]-ara[l],tak[m]-tak[r]);
        cout<<sum<<"\n";
        cp.clear();
    }
}
