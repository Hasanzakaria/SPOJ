#include<bits/stdc++.h>
using namespace std;
int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long int n,i,sum,ans;
    while(cin>>n)
    {
        sum=0;
        ans=0;
        if(n==0)
        {
           break;
        }
        long long int ara[n];
        for(i=0;i<n;i++)
        {
            cin>>ara[i];
        }
        for(i=0;i<n;i++)
        {
           sum+=ara[i];
           ans+=abs(sum);
        }
        cout<<ans<<"\n";
    }
}
