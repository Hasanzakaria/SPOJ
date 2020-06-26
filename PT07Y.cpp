#include<iostream>
#include<queue>
using namespace std;
vector<int>edge[10001];
vector<int>::iterator k;
bool vis[10001],flag;
void bfs(int r)
{
    int y,b,cou;
    vis[r]=1;
    queue<int>t;
    t.push(r);
    while(!t.empty())
    {
        cou=0;
        y=t.front();
        t.pop();
        for(k=edge[y].begin();k!=edge[y].end();k++)
        {
           b=*k;
           if(!vis[b])
           {
               vis[b]=1;
               t.push(b);
           }
           else
           {
              cou++;
           }
        }
        if(cou>=2)
        {
            flag=1;
            break;
        }
    }

}
int main ()
{
    int n,m,i,t,e;
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        cin>>t>>e;
        edge[t].push_back(e);
        edge[e].push_back(t);
    }
    bfs(1);
    for(i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            flag=1;
            break;
        }

    }
    if(flag==1)
    {
        cout<<"NO"<<endl;
    }
    else
    {
        cout<<"YES"<<endl;
    }


}
