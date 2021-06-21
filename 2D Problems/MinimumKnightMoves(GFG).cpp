int dis[1005][1005];
int vis[1005][1005];
int grid[1005][1005];
int dirx[8] = {2,2,-2,-2,1,1,-1,-1};
int diry[8] = {-1,1,-1,1,2,-2,2,-2};
int sx;
int sy;
int ex;
int ey;
int n;

bool isValid(int x,int y)
{
    if(x>=0 && x<n && y>=0 && y<n)
    {
        if(vis[x][y]==false)
        return true;
        else
        return false;
    }
    return 
    false;
}
void bfs(int x,int y)
{
    vis[x][y] = true;
    dis[x][y] = 0;
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    while(!q.empty())
    {
        pair<int,int> temp = q.front();
        q.pop();
        int tempx = temp.first;
        int tempy = temp.second;
        for(int i=0;i<8;i++)
        {
            int x1 = tempx + dirx[i];
            int y1 = tempy + diry[i];
            if(isValid(x1,y1))
            {
                dis[x1][y1] = dis[tempx][tempy] + 1;
                vis[x1][y1] = true;
                q.push(make_pair(x1,y1));
            }
        }
    }
    return;
}
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    sx = KnightPos[0]-1;
	    sy = KnightPos[1]-1;
	    ex = TargetPos[0]-1;
	    ey = TargetPos[1]-1;
	    n = N;
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            vis[i][j] = false;
	            dis[i][j] = 0;
	        }
	    }
	    bfs(sx,sy);
	    int ans = dis[ex][ey];
	    return ans;
	}
};
