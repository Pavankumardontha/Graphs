#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int n,m;
bool vis[10001];
vector<int> g[1001];
bool ans = false; // firt assumption :- No cycle present
void dfs(int v,int p)
{
    vis[v]=true;
    for(int i=0;i<g[v].size();i++)
    {
        int child = g[v][i];
        if(!vis[child])
        dfs(child,v);
        else if(child!=p)
        ans = true;
    }
}

int main()
{
    cin>>n>>m;
    int a,b;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    ans = false; // no cycle present assumption
    for(int i=1;i<=n;i++)
    if(!vis[i])
    dfs(i,-1);
    cout<<ans<<endl;
}
