#include<bits/stdc++.h>
#include<iostream>
using namespace std;
 
vector<int> g[10001];
int low[10001];
int in[10001];
int vis[10001];
int timer=0;
int ap[10001];
int n;
int m;
void dfs(int v,int p)
{
    vis[v]=1;
    low[v]=timer;
    in[v]=timer;
    timer++;
    int cnt = 0;
    for(int i=0;i<g[v].size();i++)
    {
        int child = g[v][i];
        if(child==p)
        continue;
        else if(vis[child])
        low[v] = min(low[v],in[child]);
        else
        {
            cnt++;
            dfs(child,v);
            if(cnt>1 && p==-1) // root of DFS tree is an articulation point if it as atleast 2 children
            ap[v]=1;
            if(low[child]>=in[v] && p!=-1)  
            ap[v]=1;
            low[v] = min(low[v],low[child]);
        }
    }
}
 
int main()
{
     while(1)
     {
         cin>>n>>m;
         if(n==0 && m==0)
         break;
         else
         {
             for(int i=1;i<=n;i++)
             {
                 g[i].clear();
                 in[i]=0;
                 low[i]=0;
                 vis[i]=0;
                 ap[i]=0;
             }
             int a,b;
             for(int i=0;i<m;i++)
             {
                 cin>>a>>b;
                 g[a].push_back(b);
                 g[b].push_back(a);
             }
             dfs(1,-1); //given initially that all are connected 
             int cnt = 0;
             for(int i=1;i<=n;i++)
             {
                 if(ap[i]==1)
                 cnt++;
             }
             cout<<cnt<<endl;
         }
     }
} 
