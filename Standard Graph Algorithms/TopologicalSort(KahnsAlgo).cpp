
/*we will give high priority to the nodes which have less indegree.In each case,we choose edges having indegree 0 or all of its dependencies have
already been explored. */

#include<bits/stdc++.h>
using namespace std;

vector<int> arr[100];//adjacency list
vector<int> res;//to store the topological sort ordering
int in[100];//to calculate the indegree of a node

void kahn(int n)
{
	//here n is the no of nodes in our graph
	//we will create a queue and push all the nodes into it which have indegree 0.
	queue<int> q;
	for(int i=1;i<=n;i++)
	if((in[i]==0))
	q.push(i);
	
	//we will proceed similar to BFS
	while(!q.empty())
	{
		int temp=q.front();
		//we will push this into the result vector
		res.push_back(temp);
		q.pop();
		
		//we will now move to the children of the temp and decrease their indegree count by 1,since its parent temp has been explored.
		for(int i=0;i<arr[temp].size();i++)
		{
		      	int child=arr[temp][i];
			in[child]--;
			if(in[child]==0)
			q.push(child);   	
		}
		
	}
	
	//printing the toposort
    	for(int i=0;i<res.size();i++)
	cout<<res[i]<<" ";
	cout<<endl;	
	
	
}



int main()
{
	//we always use directed graph in case of topological sort
	int n,m,x,y;
	cin>>n;//no of nodes
	cin>>m;//no of edges
	
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		arr[x].push_back(y);
		// understand why we are doing arr[x].push_back(y) and not arr[y].push_back(x)
		in[y]++;//here only we will increment the indegree of y.
	}
	
	kahn(n);
}


/* sample input:
5 6
1 2
1 3
2 3
2 4
3 4
3 5

sample output:
 1 2 3 4 5 
 
 */
