/*
The Floyd Warshall Algorithm is for solving the All Pairs Shortest Path problem. The problem is to find shortest
distances between every pair of vertices in a given edge weighted directed/undirected Graph. 
----------------
Dijkstra finds the distance of all the nodes from a given source node in a graph.Dijkstra fails in 2 conditions
a) Dijkstra’s algorithm never ends if the graph contains at least one negative cycle. By a negative cycle, 
we mean a cycle that has a negative total weight for its edges.
b) Dijkstra’s algorithm gives wrong results if some edge has negative weight.Dijkstra’s algorithm can reach an 
end if the graph contains negative edges, but no negative cycles. So the execution of the algorithm will
definitely end in case of negative edge weight but might give wrong results. 
----------------
Bellmanford Algorithm is also used to find the distance of all the nodes from a given source node in a graph.
Bellman Ford’s Algorithm works when there is negative weight edge, it also detects the negative weight cycle.
Dijkstra’s Algorithm may or may not work when there is negative weight edge. But will definitely not work 
when there is a negative weight cycle.
----------------
Understand the difference between all 3 algorithms.

*/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int n,m;
int dis[101][101];

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j)
            dis[i][j]=0;
            else
            dis[i][j]=INT_MAX;
        }
    }
    int a,b,w;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b>>w;
        dis[a][b]=w;
        // dis[b][a]=w; this applies in case of undirected graph !!!
    }
    // NOTE :- The order of the loop is very important.Always middle man will be the first loop. !!!!!!!
    for(int k=1;k<=n;k++) //middle man 
    { 
        for(int i=1;i<=n;i++)  // src 
        {
            //our aim is to calculate minimum distance between (k,i)
            for(int j=1;j<=n;j++) // final 
            {
                if(dis[i][k]!=INT_MAX && dis[k][j]!=INT_MAX) //route present or not  
                if(dis[i][j] > dis[i][k] + dis[k][j]) //compare the distance 
                dis[i][j] = dis[i][k] + dis[k][j];   //update 
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        cout<<dis[i][j]<<" ";
        cout<<endl;
        
    }
}

/* 
Test case :- 
4 4 
1 2 8
2 3 9
3 4 10
4 1 11 

solution :- 
0 8 17 27
30 0 9 19
21 29 0 10
11 19 28 0 
*/
