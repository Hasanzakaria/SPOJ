#include<bits/stdc++.h>
using namespace std;
int status[(100000001/32)+1];
bool check(int n,int pos)
{
    return (bool)(n&(1<<pos));
}
int sett(int n,int pos)
{
    return n|(1<<pos);
}
void bitwise_sieve(int n)
{
    int i,t,j;
    t=sqrt(n);
    for(i=3; i<=t; i+=2)
    {
        if(check(status[i/32],i%32)==0)
        {
            for(j=i*i; j<=n; j+=2*i)
            {
                status[j/32]=sett(status[j/32],j%32);
            }
        }
    }
}
int main ()
{
    int i,cou=0;
    bitwise_sieve(100000000);
    cout<<2<<endl;
    for(i=3; i<100000000; i+=2)
    {
        if(check(status[i/32],i%32)==0)
        {
            cou++;
            if(cou==100)
            {
              cout<<i<<endl;
              cou=0;
            }
        }
    }
}
