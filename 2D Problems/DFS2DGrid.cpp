/* applying DFS on 2D grid. */
/* In the grid we have cells,in graphs we have edges.There are 2 different kind of edges depending upon the problem.In the problem statement it
In some of the problems,only the sides are considered as edges between the cells and in some of the problems,sides+corners are considered as 
edges.This entirely depends on the problem.Two cells are said to have an edge if they share a common edge or sometimes a common corner.Lets now
see how DFS works on graph and then try to correlate and convert this so that it can be applicable on 2D grid as well.
*/

/*
void DFS(int v)
{
	vis[v]=1;
	for(int i=0;i<g[v].size();i++)
	{
		int child=g[v][i];
		if(vis[child]==0)
		DFS(child);
	}
}

*/

/*we will now consider children as cells.Each cell has index (i,j) in the 2D matrix.Generally in a graph,the no. of children of a node cannot be
determined before hand.We will traverse all the nodes in the adjacency list of a graph and then find its children.When coming to cells in a matrix
it is abvious that its children will only present in anyone of the 8 diretions(if sides and corners both are considered)
*/

bool vis[10001][10001];
int n;//no of rows
int m;//no of columns
void DFS(int x,int y)
{
	vis[x][y]=1;//you will have a 2D visisted matrix in this case
	
	/*let us consider that only sides are considered as edges.Then in that case we have 4 directions to look for from a cell (x,y) ie up,down,right
	and left.If we consider even corners as edges then we will have 8 possible conections */
	if(isValid(x-1,y))//up
	DFS(x-1,y);
	
	if(isValid(x,y+1))//right
	DFS(x,y+1);
	
	if(isValid(x+1,y))//down
	DFS(x+1,y);
	
	if(isValid(x,y-1))//left
	DFS(x,y-1);
	
}

bool isValid(int x,int y)
{
	//let n be the no of rows and m be the no of columns 
	if(x>=0 && x<n && y>=0 && y<m)
	{
		if(vis[x][y]==false)
		return true;
		else
		return false;
	}
	else
	false;
}
