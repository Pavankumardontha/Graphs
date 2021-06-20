void BFS(int v)
{
	vis[v]=1;
	dis[v]=0;
	queue<int> q;
	q.push(v);
	
	while(!q.empty())
	{
		int temp=q.front();
		q.pop();
		
		for(int i=0;i<g[v].size();i++)
		{
			int child=g[v][i];
			if(vis[child]==0)
			{
				dis[child]=dis[temp]+1;
				vis[child]=1;
				q.push(child);
			}
		}
		
	}
}


/* now we will apply BFS on 2D grid */

bool vis[100001][100001];
int N;
int M;
int dis[100001][100001];//note here that even the distance matrix is 2D

bool isValid(int x,int y)
{
	if(x>=0 && x<N && y>=0 && y<M)//checking whether the current cell is inside the grid or not.If its inside then we will check whether its visisted or not.
	{
		if(vis[x][y]==false)
		return true;
		else
		return false;
	}
	else
	return false;
}
void BFS(int x,int y)
{
	queue<pair<int,int>> q;
	q.push(make_pair(x,y));
	vis[x][y]=1;
	dis[x][y]=0;
	
	while(!q.empty())
	{
		int tempx=q.front().first;
		int tempy=q.front().second;
		q.pop()
		
		//if we consider only sides as the edges then we will have 4 conditions.
		if(isValid(tempx-1,tempy))//up
		{
			q.push(make_pair(tempx-1,tempy));
			vis[tempx-1][tempy]=1;
			dis[tempx-1][tempy]=dis[tempx][tempy]+1;
		}
		
		if(isValid(tempx+1,tempy))//down
		{
			q.push(make_pair(tempx+1,tempy));
			vis[tempx+1][tempy]=1;
			dis[tempx+1][tempy]=dis[tempx][tempy]+1;
		}
		
		if(isValid(tempx,tempy+1))//right
		{
			q.push(make_pair(tempx,tempy+1));
			vis[tempx][tempy+1]=1;
			dis[tempx][tempy+1]=dis[tempx][tempy]+1;
		}
		
		if(isValid(tempx,tempy-1))//left
		{
			q.push(make_pair(tempx,tempy-1));
			vis[tempx][tempy-1]=1;
			dis[tempx][tempy-1]=dis[tempx][tempy]+1;
		}
		//if we consider even corners as edges then there will be 8 cases
	}
}
