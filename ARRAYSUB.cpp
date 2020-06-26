#include<bits/stdc++.h>
using namespace std;
int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    multiset<int>s;
    multiset<int>::iterator p;
    int n,low=0,high=0,maxx,k=1,r,g,i;
    cin>>n;
    int ara[n];
    for(i=0;i<n;i++)
    {
        cin>>ara[i];
    }
    cin>>r;
    s.insert(ara[low]);
    while(high<n)
    {

       if(k<r)
       {
           k++;
           high++;
           if(high<n)
           {
               s.insert(ara[high]);
           }
       }
       else
       {
           k--;
           p=s.end();
           p--;
           cout<<*p<<" ";
           g=ara[low];
           low++;
           p=s.find(g);
           s.erase(p);
       }
    }

}
