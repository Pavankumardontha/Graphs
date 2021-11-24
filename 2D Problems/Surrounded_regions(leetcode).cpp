bool vis[201][201];
char g[201][201];
int n;
int m;
bool isValid(int x, int y)
{
    if(x>0 and x<n and y>0 and y<m)
    {
        if(!vis[x][y] and g[x][y] == 'O')
            return true;
        else
            return false;
    }
    return false;
}

void dfs(int x, int y)
{
    vis[x][y] = 1;
    
    if(isValid(x-1,y))
        dfs(x-1,y);
    if(isValid(x+1,y))
        dfs(x+1,y);
    if(isValid(x,y+1))
        dfs(x,y+1);
    if(isValid(x,y-1))
        dfs(x,y-1);
}

class Solution {
public:
    void solve(vector<vector<char>>& board) 
    {
        n = board.size();
        m = board[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                g[i][j] = board[i][j];
                vis[i][j] = false;
            }
        }
        
        //collecting all the indices where 'O' is on the verge
        
        //first column
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
        {
            if(g[i][0] == 'O')
                v.push_back({i,0});
        }
        
        //first row 
        for(int j = 0;j<m;j++)
        {
            if(g[0][j] == 'O')
                v.push_back({0,j});
        }
        
        //last column 
        for(int i=0;i<n;i++)
        {
            if(g[i][m-1] == 'O')
                v.push_back({i,m-1});
        }
        
        //last row 
        for(int j=0; j<m; j++)
        {
            if(g[n-1][j] == 'O')
                v.push_back({n-1,j});
        }
        
        for(int i=0;i<v.size();i++)
        {
            pair<int,int> temp = v[i];
            if(!vis[temp.first][temp.second])
                dfs(temp.first,temp.second);
        }
        
        
        //converting all the unvisited 'O' nodes to 'X' in the board since these are bounded by all 'X''s
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j] == false and g[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }    
    }
};
