/*
You are given an unweighted, undirected tree. Write a program to output the length of the longest path (from one node to another)
in that tree. The length of a path in this case is number of edges we traverse from source to destination.

Input
The first line of the input file contains one integer N --- number of nodes in the tree (0 < N <= 10000). Next N-1 lines contain
 N-1 edges of that tree --- Each line contains a pair (u, v) means there is an edge between node u and node v (1 <= u, v <= N).

Output
Print the length of the longest path on one line.

Example
Input:
3
1 2
2 3

Output:
2
*/


#include<bits/stdc++.h>
#include<iostream>
using namespace std;

vector<int> g[10001];
int n;
int m;
int farest_node;
int longest_distance = 0; // longest distance between 2 nodes
int dis[10001];
int main()
{
    cin>>n;
    m=n-1;
    int a,b;
    while(m--)
    {
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
    dis[i]=INT_MAX;
    queue<int> q;
    q.push(1);
    dis[1]=0;
    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        for(int i=0;i<g[v].size();i++)
        {
            int child = g[v][i];
            if(dis[child]==INT_MAX)
            {
                dis[child] = dis[v]+1;
                q.push(child);
            }
        }
        farest_node = v;
    }
    // start bfs from the farest_node 
    for(int i=0;i<=n;i++)
    dis[i]=INT_MAX;
    q.push(farest_node);
    dis[farest_node]=0;
    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        for(int i=0;i<g[v].size();i++)
        {
            int child = g[v][i];
            if(dis[child]==INT_MAX)
            {
                dis[child] = dis[v]+1;
                q.push(child);
            }
        }
        longest_distance = dis[v];
    }
    cout<<longest_distance<<endl;
}
