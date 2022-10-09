int n;
int m;
bool vis[301][301];
class Solution {
public:
    bool isValid(vector<vector<char>>& grid,int x,int y)
    {
        if(x>=0 and x<n and y>=0 and y<m)
        {
            if(grid[x][y]=='1' and vis[x][y]==false)
                return true;
            else
                return false;
        }
        return false;
    }
    void dfs(vector<vector<char>>& grid,int x, int y)
    {
        vis[x][y]=true;
        if(isValid(grid,x+1,y))
            dfs(grid,x+1,y);
        if(isValid(grid,x-1,y))
            dfs(grid,x-1,y);
        if(isValid(grid,x,y+1))
            dfs(grid,x,y+1);
        if(isValid(grid,x,y-1))
            dfs(grid,x,y-1);
        
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        n = grid.size();
        m = grid[0].size();
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                vis[i][j]=false;
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]==false and grid[i][j]=='1')
                {
                    dfs(grid,i,j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
