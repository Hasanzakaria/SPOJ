#include<bits/stdc++.h>
using namespace std;
int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long int n,i,a,j,k,l,r,f,cou,flag;
    cin>>n;
    for(i=1;i<=n;i++)
    {
       flag=0;
       cou=0;
       r=0;
       cin>>a;
       pair<long long int,long long int>pq[a];
       priority_queue<long long int>cp;
       for(j=0;j<a;j++)
       {
           cin>>pq[j].first>>pq[j].second;
       }
       cin>>k>>l;
       for(j=0;j<a;j++)
       {
           pq[j].first=k-pq[j].first;
       }
       sort(pq,pq+a);
       while(l<k)
       {
          for(;pq[r].first<=l&&r<a;r++)
          {
             cp.push(pq[r].second);
          }
          if(cp.size()>0)
          {
              f=cp.top();
              cp.pop();
              l+=f;
              cou++;
          }
          else
          {
             flag=1;
             break;
          }
       }
       if(flag==0)
       {
          cout<<cou<<"\n";
       }
       else
       {
          cout<<-1<<"\n";
       }
    }

}
