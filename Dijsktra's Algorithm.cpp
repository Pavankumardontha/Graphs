/* Dijsktra's Algorithm: In this algorithm we use priority queue(min heap)
Insertion in Priority queue O(logn)
Deletion in Priority queue O(logn)
Finding min/max in Priority Queue O(1).
 */

#include<bits/stdc++.h>
#include<iostream>
using namespace std;
//we will create adjacency list but this time we use pair because we also have weights now 
vector<pair<int,int> > g[10001];//this is adjacencylist for a weight graph.So we have two techniques one is the struct edge which we use in krushkals algo and the other is 
// this.Note also that the first member in this pair, is the weight and NOT the distance.!!!!! Distance is only stored in the distance array and in the priority queue.

//we use distance array which stores  the sum of weights of all the edges in the shortest path from out source node to the
//current node.

int dis[10001];

//we also use Priority Queue in this method
priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq; //this is min heap implementation.Min heap with respect to the first element in the pair.
//priority_queue<pair<int,int>> pq; //this is normal max heap implementation
//the first element in the above pair in the priority queue is the distance and NOT the weight.
//PAIR----VECTORPAIR----GREATERPAIR--- this is important to remember


int main()
{
	int n,m,a,b,w,src;
	//src is the source node
	cin>>n>>m;
	//n=no of nodes ,m=no of edges
	for(int i=1;i<=n;i++)
	{
		dis[i]=INT_MAX;
		g[i].clear();
	}
	
	while(m--)
	{
		cin>>a>>b>>w;
		g[a].push_back(make_pair(w,b));
		g[b].push_back(make_pair(w,a));//this step will not be there for a directed graph
	}
	//we push the src node into the priority queue and do it same as the BFS
	
	cin>>src;
	pq.push(make_pair(0,src)); //Note that here we are pushing distance as first element of the pair and node as the second element of the pair.
	dis[src]=0;
	/* make sure that in the graph vector we have weights and the children but in the priority queue we will have the distance
	of the nodes from the source node.*/
	while(!pq.empty())
	{
		//same as BFS
		pair<int,int> temp=pq.top(); //remember that this is not pq.front() as in normal case 
/*whenever a node is coming then it means that its distance is already assigned.We assign the distances to the nodes from
source and then only push that node with its distance into the priority queue.*/	
		int d=temp.first;
		int node=temp.second;
		pq.pop();
/*we now have our current node and the distance of it from the source node. We will add this distance and weight associated with different edges and find the distance of its
children. We will update and push into the priority queue if needed.*/
		for(int i=0;i<g[node].size();i++)
		{
			pair<int,int> edge =g[node][i]; /* this is an edge between our current node and its children.In other words we are traversing the adjacency list of 
our current node.We will push this into the priority queue if and only if we update its distance.*/
			if(d+edge.first<dis[edge.second])
			{
				dis[edge.second]=d+edge.first;
				pq.push(make_pair(dis[edge.second],edge.second));
			}
		}
	}
	
	for(int i=1;i<=n;i++)
	cout<<dis[i]<<" ";
}

/*
Input:-
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
1                        (src)

output: 0 , 3 , 8 , 14 , 11 , 2
*/

