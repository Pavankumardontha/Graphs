#include<bits/stdc++.h>
#include<iostream>
using namespace std;

/*bellam ford algorithm: this is used for finding SSSP. SSSP means single source shortest path. We will find the 
length of path from our root node to all other nodes.This is used for weighted directed/undirected graph.Bellmanford 
algorithm can detect negative weight cycle.Dijkstra does not detect negative weight cycle.So we use bellmanford 
algorithm if the graph has negative weight cycles.Dijkstra algorithms runs into infinite loop in case of negative 
weight cycle.The time complexity of dijkstras is less than bellmanford.Storing the graph in edge list is slightly
better in this bellmanford algorithm. Initialise all the distances to INF and source node distance to 0 same as in 
case of dijkshtras.We will have N-1 phases.In each Phase,we traverse through whole edge list(x,y) and try to update 
the dis[y].We continue this process for all the edges in each phase.After (k+1)th phase,Bellmanford algorithm correctly
finds all the shortest paths of nodes whose number of edges(in_degree) are less than or equal to k. So if we have n 
nodes,each node can have atmost n-1 edges and so we need atleast n-1 phases in the worst case. This implementation is 
similar to krushkal's minimum spanning trees algorithm.*/
/*
The Floyd Warshall Algorithm is for solving the All Pairs Shortest Path problem. The problem is to find shortest
distances between every pair of verticesin a given edge weighted directed/undirected Graph. 
----------------
Dijkstra finds the distance of all the nodes from a given source node in a graph.Dijkstra fails in 2 conditions
a) Dijkstra’s algorithm never ends if the graph contains at least one negative cycle. By a negative cycle, we mean 
a cycle that has a negative total weight for its edges.
b) Dijkstra’s algorithm gives wrong results if some edge has negative weight.Dijkstra’s algorithm can reach an end 
if the graph contains negative edges, but no negative cycles. So the execution of the algorithm will definitely end 
in case of negative edge weight but might give wrong results. 
----------------
Bellmanford Algorithm is also used to find the distance of all the nodes from a given source node in a graph.Bellman Ford’s Algorithm works when there 
is negative weight edge, it also detects the negative weight cycle.Dijkstra’s Algorithm may or may not work when there is negative weight edge. 
But will definitely not work when there is a negative weight cycle.
----------------
Understand the difference between all 3 algorithms.
*/

struct edge
{
    int a;
    int b;
    int w;
};
edge g[10001];
int dis[10001];
int main()
{
    int n;
    int m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    dis[i]=INT_MAX;
    // this is very important step. Do not always initialise with INT_MAX because this can create problems !!!!
    
    for(int i=0;i<m;i++)
    {
        cin>>g[i].a;
        cin>>g[i].b;
        cin>>g[i].w;
    }
    
    int src;
    cin>>src;
    dis[src]=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<m;j++)
        {
            //this loop can be modified and the modified code is given down.
            if(dis[g[j].a]!=INT_MAX)
            if(dis[g[j].a]+g[j].w < dis[g[j].b])
            dis[g[j].b] = g[j].w + dis[g[j].a];
            
            if(dis[g[j].b]!=INT_MAX)
            if(dis[g[j].b] + g[j].w < dis[g[j].a])
            dis[g[j].a] = dis[g[j].b] + g[j].w;
            //for directed graph we only get one if condition.
        }
    }
    for(int i=1;i<=n;i++)
    cout<<dis[i]<<" ";
    cout<<endl;
}

/*Many times,we can improvise the above algorithm since some of the phases are not useful.
After some phase i,the distance array elements do not change.So instead of doing n-1 
phases,we can stop at a point where after a phase,there is not even one relaxation in the 
array in the next phase.
*/

bool flag;
for(int i=0;i<n-1;i++)
{
    flag = false;
    for(int j=0;j<m;j++)
    {
            if(dis[g[j].a]+g[j].w < dis[g[j].b])
            {
                dis[g[j].b] = g[j].w + dis[g[j].a];
                flag=true;
            }
            if(dis[g[j].b] + g[j].w < dis[g[j].a])
            {
                dis[g[j].a] = dis[g[j].b] + g[j].w;
                flag=true;
            }
        
    }
    if(flag==false)
    break; //this implies there was no updation in the distance array
}

/* input : 
6 9
1 2 4
1 6 2
2 3 5
2 6 1
6 3 8
6 5 10
3 4 6
3 5 3
5 4 5
1  

output : 
0 , 3 , 8 , 14 , 11 , 2
*/
