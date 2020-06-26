#include<bits/stdc++.h>
using namespace std;
long long int tree[1000001],propagate[1000001];
void update(long long int node,long long int b,long long int e,long long int i,int j,long long int x)
{
    if(propagate[node]!=0)
    {
        tree[node]+=(e-b+1)*propagate[node];
        propagate[2*node]+=propagate[node];
        propagate[(2*node)+1]+=propagate[node];
        propagate[node]=0;
    }
    if (i > e || j < b)
    {
        return;
    }
    if (b >= i && e <= j)
    {
        tree[node]+= ((e - b + 1) * x);
        propagate[2*node]+= x;
        propagate[(2*node)+1]+=x;
        return;
    }
    long long int Left = node * 2;
    long long int Right = (node * 2) + 1;
    long long int mid = (b + e) / 2;
    update(Left, b, mid, i, j, x);
    update(Right, mid + 1, e, i, j, x);
    tree[node] = tree[Left]+ tree[Right];
}
long long int query(long long int node, long long int b,long long  int e, long long int i, long long int j)
{
    if(propagate[node]!=0)
    {
        tree[node]+=(e-b+1)*propagate[node];
        propagate[2*node]+=propagate[node];
        propagate[(2*node)+1]+=propagate[node];
        propagate[node]=0;
    }
    if (i > e || j < b)
    {
        return 0;
    }
    if (b >= i and e <= j)
    {
        return tree[node];

    }

    long long int Left = node*2;
    long long int Right = (node*2) + 1;
    long long int mid = (b + e) / 2;

    long long int p1 = query(Left, b, mid, i, j);
    long long int p2 = query(Right, mid + 1, e, i, j);

    return p1 + p2;
}
int main ()
{
    long long int t,i,a,b,j,x,m,n,v,ans;
    scanf("%lld",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%lld %lld",&a,&b);
       // printf("Case %lld:\n",i);
        for(j=1;j<=b;j++)
        {
            scanf("%lld",&x);
            if(x==0)
            {
                scanf("%lld %lld %lld",&m,&n,&v);
                update(1,0,a-1,m-1,n-1,v);
            }
            else
            {
                scanf("%lld %lld",&m,&n);
                ans=query(1,0,a-1,m-1,n-1);
                printf("%lld\n",ans);
            }
        }
        memset(tree,0,sizeof(tree));
        memset(propagate,0,sizeof(propagate));
    }
}
