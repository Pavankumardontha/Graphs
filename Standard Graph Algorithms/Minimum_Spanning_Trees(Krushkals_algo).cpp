/*Krushkals Algorithm for MST(coding in hacker-earth as well as geeksforgeeks) */

/*
Given a weighted undirected graph. Find the sum of weights of edges of a Minimum Spanning Tree.

Input:
Given 2 integers N and M. N represents the number of vertices in the graph. M represents the number of edges between any 2 vertices.
Then M lines follow, each line has 3 space separated integers  , ,  where  and  represents an edge from a vertex  to a vertex  and  respresents the weight of that edge.

Output:
Print the summation of edges weights in the MST.

Constraints:
2<=N<=10000
1<=M<=100000
1<=a,b<=N
1<=w<=1000

*/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

/*whenever we want to take edges with weights as input then we creat a structure.And then create an array of that structure.*/
/* for dijshitra we create a vector of pairs.Only in case of Krushkals,we create a structure of type edge.*/
struct edge
{
	int a;
	int b;
	int w;//weight of the edge a-b
};

//now we create edge list.Note here that the size of the edge list is equal to the no of edges.
edge g[100001];

/*comparator function for sorting the edges.If we return true then 'a' would be placed before 'b' and if you return false then 'b'
would be placed before 'a'.We will sort edges depending upon their weights in ascending order. */
bool comp(edge x,edge y)
{
	if(x.w<y.w) //if weight of edge x is less than weight of edge y.
	return true;//in this case edge x should come before edge y.
	else
	return false;
}

/*since we use Disjoint set data structure in this algorithm. we have to have a parent array which is of size equal to the no. of nodes */
/* while applying disjoint set union,we require 3 things in hand. One is parent array and the other is find and the union functions.*/
int par[100001];

//we need to write 2 functions in case of Disjoint set.one is the find function which returns the parent of the set and the
//other one is the merge function which  takes 2 elements and merges them into one.'


int find(int a)
{
	//this returns the parent of node a.
	/*parent of node is that node itself if par[node] is -1.So if par[a]=-1 implies that parent of node is a itself.So initially,each node is 
	a parent of itself since they are not added into any group and thats the reason they ae initialised with -1.*/
	if(par[a]<0)//checking if our current node is the parent or if it is pointing to any other node.If its pointing to -1,then its the parent
	return a;
	else
	{
	  	//if the current node is not parent and pointing to another node.
	  	par[a]=find(par[a]);//make note of this its very useful
	  	return par[a];
	  	//or we can directly return the parent of 'a' from this function
	}
}

void merge(int a,int b)
{
	//for merging we just make the parent of one to point to other
	par[a]=b;
	//we can also use par[b]=a;	
}


int main()
{
	int n,m;
	cin>>n>>m;
	//n=no. of nodes
	//m=no. of edges
	
	//we should clear the parent array and make each other point to themselves.We will make every element as a parent to itself
	for(int i=1;i<=n;i++)
	par[i]=-1;
	/* initially all the nodes point to themselves and they are parents of themselves.*/
    //we should now take the input of m edges
    for(int i=0;i<m;i++)
    cin>>g[i].a>>g[i].b>>g[i].w;
    
    //now we have to sort this edges based on weights.Remember this down step and note the difference between vector and array sorting
    sort(g,g+m,comp); //this is array sorting.
    
    int sum=0;//this stores the sum of all the weights in the minimum spanning tree.
    for(int i=0;i<m;i++)
    {
     //we have m edges with us now.we have also sorted the edges depending on their weights.So now lets proceed.we will find
     //the parents of the first edge.
     /*we have 2 choices for each edge,whether it can be included or cannot be included.So we have only 2 sets here,the included set and 
     the not included set.We can either include an edge or not include.*/
     int k=find(g[i].a);
     int l=find(g[i].b);
     
     /*we have the parents of our edge (a,b) in (k,l)
     if both of their parents are equal then they belong to the same set.If they belong to the same set,then their is 
     always a path from 'a' to 'b' and thus we no need to add edge a,b into our Minimum spanning Tree edge-list. That
	 means we do not add the weight of the edge (a,b) into our sum variable.Sum variable returns the sum of all the 
	 edges considered in the Minimum spanning tree. If their parents are not same then they both do not belong to the same 
	 set and there is no way to reach from 'a' to 'b' and hence we should add edge (a,b) into our minimum spanning tree 
	 edge-list.*/
	 
	 if(k!=l)//if both the node parents are different then we should add the edge into the Minimum spanning tree edge-list
	 {
	 	sum=sum+g[i].w;
	 	merge(k,l); //NOT NOT NOT  merge(g[i].a,g[i].b)
		/* here its very important to note that we are merging the parents of the nodes and NOT the nodes. Mergeing the parents is different than megering the nodes. 
		Whenever we merge the parents, we are mergeing 2 large groups which have different parents by making their parents same. If parents of any 2 nodes are same 
		then it means that we can reach one node via another through some path. If they are not reachable then their parents will be different. Reachable nodes have the 
		same parents. !! 
		*/
	 	
	 }
	}
	cout<<sum<<endl;
}


/*Given n( no of nodes of the graph) and e no of edges of the graph followed by edges b/w vertexes and weight as input, calculate the minimum 
spanning trees cost.
Note1: it is guaranteed that the given graph is not a disjoint.

sample input :-
8 8
1 5 6
1 3 2
3 7 3
7 6 5
7 8 4
6 8 4
1 4 7
4 2 6

output
32

test case - 2 
4 5
1 2 7
1 4 6
4 2 9
4 3 8
2 3 6

output 
21
*/
