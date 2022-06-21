#include<bits/stdc++.h>
#include<iostream>
using namespace std;

/*
We have 2 types of edges here.Backedges and edges in DFS tree
Graph edges = Back-edges + DFS tree edges.
Backedges are edges in graph which are not present in the DFS tree edges.
in[v] = discovery time of a node. This is the time at which we explored node V in the DFS 
tree.
low[v] = min(least discovery time of children of v connected via backedges(already visited children),least low time of children of v connected via DFS tree)
For our current node,children can be 
a)parent of our current node(its ofcourse visited in this case.we just continue in this case)
b)unvisited.(we will explore this child and this edge gets added into the DFS tree)
c)visited and not parent(this edge between our current node and child is called the backedge.
In this case,we just change the low time of our current node by finding the minimum between 
low time of our current node and low time of this child)
*/

vector<int> g[10001];
int in[10001];
int low[10001];
bool vis[10001];
int timer = 0;
void dfs(int v,int p)
{
    vis[v] = 1;
    in[v] = timer; //discovery time 
    low[v] = timer; 
    timer++;
    /* travering all the children of our current node.*/
    for(int i=0;i<g[v].size();i++)
    {
        int child = g[v][i];
        if(child==p)
        continue;
        else if(vis[child]==1)
        {
            /* here we have a backedge.We just update the low time of the node with in time 
            of the child.*/
            low[v] = min(low[v],in[child]); 
        }
        else
        {
            //edge in the DFS tree.
/*here there is a chance of having a bridge.We will first explore the unexplored nodes and
compare lowtime of child and intime of current node.Finally we update the low time of current
node.*/
            dfs(child,v);
            if(low[child]>in[v])
            cout<<v<<"----"<<child<<" ";
            low[v] = min(low[v],low[child]); //this is for unvisited child
            
        }
    }
}

int main()
{
    int n;
    int m;
    cin>>n>>m;
    int a;
    int b;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    memset(vis,false,sizeof(vis));
    dfs(1,-1);
    return 0;
    
}

/* 
input case :-
7 7
1 2
1 3
2 3
3 4
3 5
5 6
5 7

solution :- 
3---4
5---6
5---7
3---5
