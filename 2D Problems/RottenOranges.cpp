int n,m;
int vis[505][505];
int g[505][505];
int dirx[4] = {1,-1,0,0};
int diry[4] = {0,0,1,-1};
bool isValid(int x,int y)
{
    if(x>=0 && x<n && y>=0 && y<m)
    {
        if(g[x][y]==1 && vis[x][y]==false)
        return true;
        else
        return false;
    }
    else
    return false;
}
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) 
    {
        /*We will first put all the rotten oranges indices into the queue keeping 
the timer to start from time=0 .Then after pushing all the rotton nodes into the 
queue,we will push (-1,-1) at the end.When this node arrives we should increment the
timmer by 1.we will proceed till the queue becomes empty.*/
        n = grid.size();
        m = grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                vis[i][j] = false;
                g[i][j] = grid[i][j];
                if(g[i][j]==2)
                q.push({i,j});
            }
        }
        int timer = 0;
        q.push({-1,-1});
        while(!q.empty())
        {
            pair<int,int> temp = q.front();
            int x = temp.first;
            int y = temp.second;
            q.pop();
            if(x==-1 && y==-1)
            {
                timer++;
                if(!q.empty())
                q.push({-1,-1});
            }
            else
            {
                for(int i=0;i<4;i++)
                {
                    int childx = x + dirx[i];
                    int childy = y + diry[i];
                    if(isValid(childx,childy))
                    {
                        vis[childx][childy] = true;
                        q.push({childx,childy});
                    }
                }
            }
        }
        /* We have to now check if all the oranges have been rotten or not !! */
        /* If we have any fresh oranges then we will return -1. Unvisited nodes 
        which have g[i][j] = 1 are fresh oranges. !! */
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]==0 && g[i][j]==1)
                return -1;
            }
        }
        return timer-1;
    }
};
