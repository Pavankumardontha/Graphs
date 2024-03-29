#include<bits/stdc++.h>
#include<iostream>
using namespace std;
/* A directed graph is strongly connected if there is a path between all pairs of vertices. A strongly connected component (SCC) of a directed graph is 
a maximal strongly connected subgraph.
This Algorithm is also used to find the loops and number of loops in the directed graph.
*/
//kosaraju strongly connected components 
vector<int> g[10001]; //graph
vector<int> rg[10001];//reverse graph
bool vis[10001]; //visited array 
stack<int> s;
int n; //no of nodes
int m; //no of edges
void dfs(int v)
{
    // insert the node into into the stack only after visiting all its children
    vis[v]=true;
    for(int i=0;i<g[v].size();i++)
    {
        int child = g[v][i];
        if(!vis[child])
        dfs(child);
    }
    s.push(v); //NOTE ****** this is very important. We should not insert into the stack before visiting all the children !!!
    return;
}

void rdfs(int v)  //dfs on the reverse graph 
{
    vis[v] = true;
    cout<<v<<" ";
    for(int i=0;i<rg[v].size();i++)
    {
        int child = rg[v][i];
        if(!vis[child])
        rdfs(child);
    }
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        vis[i]=false;
        g[i].clear();
        rg[i].clear();
    }
    int a;
    int b;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        g[a].push_back(b);
        rg[b].push_back(a);
    }
    
    /* 
    1) we will apply dfs on the input graph and push them in the stack as and when all the children of a particular node are visited in the dfs call. 
    2) we will pop elements from the stack and apply dfs on the reverse graph in the popped order.
    */
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        dfs(i);
    }
    
    for(int i=1;i<=n;i++)
    vis[i]=false;
    int cnt = 0; //strongly connected components count 
    while(!s.empty())
    {
        int temp = s.top();
        s.pop();
        if(!vis[temp])
        {
        //all the nodes in a strongly connected component will be visited by one dfs call 
            rdfs(temp);
            cout<<endl;
            cnt++;
        }
    }
    cout<<"No. of connected components : "<<cnt<<endl;
    
}



/*
input : 
11 13
1 2 
2 3 
3 1 
2 4 
4 5 
5 6 
6 4
7 6 
7 8 
8 9 
9 10 
10 7 
10 11

output : 4

*/
