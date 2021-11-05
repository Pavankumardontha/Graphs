#include<bits/stdc++.h>
#include<iostream>
using namespace std;

/* bellmanford single source shortest path.*/
/*bellam ford algorithm: this is used for finding SSSP. SSSP means single source shortest 
path.We will find the length of path from our root node to all other nodes.This is used for 
weighted directed/undirected graph.Bellmanford algorithm can detect negative weight cycle.
Dijkstra does not detect negative weight cycle.So we use bellmanford algorithm if the graph 
has negative weight cycles.Dijkstra algorithms runs into infinite loop in case of negative 
weight cycle.The time complexity of dijkstras is less than bellmanford.Storing the graph in
edge list is slightly better in this bellmanford algorithm.Initialise all the distances to 
INF and source node distance to 0 same as in case of dijkshtras.
We will have N-1 phases.In each Phase,we traverse through whole edge list(x,y) and try to 
update the dis[y].We continue this process for all the edges in each phase.
After (k+1)th phase,Bellmanford algorithm correctly finds all the shortest paths of nodes whose number of edges(in_degree) are less than or equal to k.So if we have n nodes,
each node can have atmost n-1 edges and so we need atleast n-1 phases in the worst case.This implementation is similar to krushkal's minimum spanning trees algorithm.*/

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
    dis[i]=1e7;
    
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
            if(dis[g[j].a]+g[j].w < dis[g[j].b])
            dis[g[j].b] = g[j].w + dis[g[j].a];
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