#include<bits/stdc++.h>
using namespace std;
int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long int t,i,a,j,k,l,r,x,y,sum;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        sum=0;
        cin>>a;
        long long int ara[a][a];
        for(j=0;j<a;j++)
        {
            for(k=0;k<a;k++)
            {
                cin>>ara[j][k];
            }
        }
        for(l=0;l<a;l++)
        {
            for(j=0;j<a;j++)
            {
                for(k=0;k<a;k++)
                {
                    ara[j][k]=min(ara[j][k],ara[j][l]+ara[l][k]);
                }
            }
        }
        cin>>r;
        for(j=0;j<r;j++)
        {
            cin>>x>>y;
            sum+=ara[x-1][y-1];
        }
        cout<<"Case #"<<i<<": ";
        cout<<sum<<"\n";
    }

}
