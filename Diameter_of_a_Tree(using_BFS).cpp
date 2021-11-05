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
using namespace std;
vector<int> g[10001];//this is adjacency list
int vis[10001];
int maxD;//maximum distance
int maxNode;//node which is at the maximum distance from the current node from which we have started the dfs
void dfs(int v,int d);//v=current node,d=its distance from where we have started the dfs
int main()
{
	int n,a,b;
   cin>>n;
   for(int i=1;i<n;i++)
   {
   	cin>>a>>b;
   	g[a].push_back(b);
   	g[b].push_back(a);
   	
   }
   //adjacency list is ready 
   //to find diameter of a tree we have to apply dfs 2 times
   //we have to now initialise our maxD to -1 before applying the dfs.
   
   
   //first dfs call.
   maxD=-1;
   dfs(1,0);
   //before second dfs call we have to initialse the vis array zero again 
   for(int i=1;i<=n;i++)
   vis[i]=0;
   //now the second call has to be called starting from the maxNode obtained from first dfs call.
   dfs(maxNode,0);
   //now we have the diameter stored in the maxD variable 
   cout<<maxD<<endl;
   
   
}

void dfs(int v,int d)
{
	vis[v]=1;
	if(d>maxD)
	{
		maxD=d;
		maxNode=v;
	}
	for(int i=0;i<g[v].size();i++)
	{
		int child=g[v][i];
		if(vis[child]==0)
		dfs(child,d+1);
	}
	
}
