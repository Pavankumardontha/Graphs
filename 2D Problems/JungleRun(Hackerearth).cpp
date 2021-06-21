#include<bits/stdc++.h>
#include<iostream>
using namespace std;


int dis[35][35];
int vis[35][35];
int n;
char grid[35][35];
bool isValid(int x,int y)
{
	if(x>=0 && x<n && y>=0 && y<n)
	{
		if(vis[x][y]==false)
		{
		    if(grid[x][y]=='P' || grid[x][y]=='E')
		    return true;
		    else
		    return false;
		}
		else
		return false;
	}
	else
	return false;
}
void bfs(int x,int y)
{
	vis[x][y] = true;
	queue<pair<int,int>> q;
	q.push(make_pair(x,y));
	dis[x][y] = 0;
	while(!q.empty())
	{
		pair<int,int> temp = q.front();
		q.pop();
		int tempx = temp.first;
		int tempy = temp.second;
		if(isValid(tempx-1,tempy))
		{
			vis[tempx-1][tempy] = true;
			dis[tempx-1][tempy] = dis[tempx][tempy]+1;
			q.push(make_pair(tempx-1,tempy));
		}
		if(isValid(tempx+1,tempy))
		{
			vis[tempx+1][tempy] = true;
			dis[tempx+1][tempy] = dis[tempx][tempy]+1;
			q.push(make_pair(tempx+1,tempy));
		}
		if(isValid(tempx,tempy-1))
		{
			vis[tempx][tempy-1] = true;
			dis[tempx][tempy-1] = dis[tempx][tempy]+1;
			q.push(make_pair(tempx,tempy-1));
		}
		if(isValid(tempx,tempy+1))
		{
			vis[tempx][tempy+1] = 1;
			dis[tempx][tempy+1] = dis[tempx][tempy]+1;
			q.push(make_pair(tempx,tempy+1));
		}
	}
	return;
}

int main()
{
	cin>>n;
	memset(vis,false,sizeof(vis));
	memset(dis,0,sizeof(dis));
	int startx;
	int starty;
	int endx;
	int endy;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>grid[i][j];
			if(grid[i][j]=='S')
			{
				startx = i;
				starty = j;
			}
			if(grid[i][j]=='E')
			{
				endx = i;
				endy = j;
			}
		}
	}
	bfs(startx,starty);
	int ans = dis[endx][endy] - dis[startx][starty];
	cout<<ans<<endl;
}
