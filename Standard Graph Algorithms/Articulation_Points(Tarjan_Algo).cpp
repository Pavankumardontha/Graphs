/*Problems :-
1) Submerging island problem SPOJ 
*/
/*
A vertex in an undirected connected graph is an articulation point (or cut vertex) if removing it (and edges through it) disconnects the graph. 
Articulation points represent vulnerabilities in a connected network – single points whose failure would split the network into 2 or more components. 
They are useful for designing reliable networks.For a disconnected undirected graph, an articulation point is a vertex removing which increases number of
connected components.
*/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int n;
int m;
vector<int> g[10001];
int vis[10001];
int in[10001];
int low[10001]; 
int ap[10001]; //articulation point array. ap[i]=1 if i is articulation point if not it is 0
int timer=0;
void dfs(int v,int p)
{
    vis[v]=1;
    in[v]=timer;
    low[v]=timer;
    timer++;
    int cnt = 0; //unvisited children count of current node
    for(int i=0;i<g[v].size();i++)
    {
        int child = g[v][i];
        if(child==p)
        continue;
        else if(vis[child])
        low[v]=min(low[v],in[child]);
        else
        {
            /*
            here we have 2 conditions. 
            a)If the node is the root node of the DFS tree then it must have atleast 2 
            children in the DFS tree for it to be an articulation point.
            b)If the node is not the root of the DFS tree then it should have atleast one 
            child in the DFS tree and also low[child]>=in[v] for v to be an articulation 
            point.Analyse example to understant the conditions better.
            */
            dfs(child,v);
            cnt++;
            
            //articulation point condition. Note that we have 2 conditions for articulation points. !!! 
            if(cnt>=2 && p==-1) //condition-1
            ap[v]=1;
            if(low[child]>=in[v] && p!=-1) //condition-2(the >= sign is very very important here which is slight change from the bridge condition
            ap[v]=1;
            
            /*bridge condition. We have only one condition for bridge. LOWC>INV
            if(low[child]>in[v])
            cout<<v<<"-"<<child<<" ";
            */
            //note the difference in the extra cnt variable and also in the if condition where we have greater than or equal to condition. !!!
            low[v]=min(low[v],low[child]);
        }
    }
}


int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        g[i].clear();
        vis[i]=0;
        ap[i]=0;
        low[i]=0;
        in[i]=0;
    }
    int a,b;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        dfs(i,-1);
    }
    for(int i=1;i<=n;i++)
    {
        if(ap[i]==1)
        cout<<i<<" ";
    }
    cout<<endl;
}

/* 
input test case :- 
7 7
1 2
1 3
2 3
3 4
3 5
5 6
5 7

solution :- 
3 5 
*/











