#include<bits/stdc++.h>
using namespace std;
char ara[20][20];
bool vis[20][20];
int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};
int a,b,cou=1;
void bfs(int x,int y)
{
    int r,t,i,m,n;
    queue<pair<int,int> >p;
    vis[x][y]=1;
    p.push(pair<int,int> (x,y));
    while(!p.empty())
    {
       pair<int,int>o;
       o=p.front();
       r=o.first;
       t=o.second;
       p.pop();
       for(i=0;i<4;i++)
       {
          m=r+fx[i];
          n=t+fy[i];
          if(!vis[m][n] && ara[m][n]!='#'&&(m>=0&&m<a)&&(n>=0&&n<b))
          {
              vis[m][n]=1;
              if((m==0||m==a-1)||(n==0||n==b-1))
              {
                  cou++;
              }
              p.push(pair<int,int> (m,n));

          }
       }

    }

}
int main ()
{
    int n,i,j,k,e,f,flag=0;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a>>b;
        for(j=0;j<a;j++)
        {
            for(k=0;k<b;k++)
            {
                cin>>ara[j][k];
                if(ara[j][k]=='.'&&((j==0||j==a-1)||(k==0||k==b-1)))
                {
                    e=j;
                    f=k;
                }
            }
        }
        bfs(e,f);
        if(cou==2)
        {
           for(j=0;j<a;j++)
           {
               for(k=0;k<b;k++)
               {
                   if(!vis[j][k]&&ara[j][k]=='.'&&((j==0||j==a-1)||(k==0||k==b-1)))
                   {
                      flag=1;
                      break;
                   }
               }
           }
           if(flag==0)
           {
               cout<<"valid"<<endl;
           }
           else
           {
               cout<<"invalid"<<endl;
           }
        }
        else
        {
            cout<<"invalid"<<endl;
        }
        cou=1;
        flag=0;
        memset(ara,'\0',sizeof(ara));
        memset(vis,0,sizeof(vis));
        e=0;
        f=0;



    }

}
