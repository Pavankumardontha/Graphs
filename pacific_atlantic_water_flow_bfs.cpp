/*
Question is somewhat wrongly framed , We need to check starting from (i,j) 
whether we can reach both the pacific ocean and atlantic ocean.
*/

bool pacific[201][201];
bool atlantic[201][201];
bool vis_pacific[201][201];
bool vis_atlantic[201][201];
int n,m;

bool isValid(int i,int j)
{
    if(i>=0 and i<n and j>=0 and j<m)
    return true;
    return false;
}
void pacific_ocean_traversal(vector<vector<int>>& heights)
{
    queue<pair<int,int>> q;

    // push all the corner points 
    for(int i=0;i<n;i++)
    {
        vis_pacific[i][0]=true;
        pacific[i][0] = true;
        pair<int,int> temp;
        temp.first=i;
        temp.second=0;
        q.push(temp);
    }
    for(int i=0;i<m;i++)
    {
        vis_pacific[0][i]=true;
        pacific[0][i]=true;
        pair<int,int> temp;
        temp.first=0;
        temp.second=i;
        q.push(temp);
    }

    while(!q.empty())
    {
        pair<int,int> temp = q.front();
        q.pop();
        
        int i = temp.first;
        int j = temp.second;

        if(isValid(i+1,j) and vis_pacific[i+1][j] == false and heights[i][j] <= heights[i+1][j])
        {
            q.push({i+1,j});
            vis_pacific[i+1][j]=true;
            pacific[i+1][j]=true;
        }
        
        if(isValid(i-1,j) and vis_pacific[i-1][j] == false and heights[i][j] <= heights[i-1][j])
        {
            q.push({i-1,j});
            vis_pacific[i-1][j]=true;
            pacific[i-1][j]=true;
        }

        if(isValid(i,j+1) and vis_pacific[i][j+1] == false and heights[i][j] <= heights[i][j+1])
        {
            q.push({i,j+1});
            vis_pacific[i][j+1]=true;
            pacific[i][j+1]=true;
        }

        if(isValid(i,j-1) and vis_pacific[i][j-1] == false and heights[i][j] <= heights[i][j-1])
        {
            q.push({i,j-1});
            vis_pacific[i][j-1]=true;
            pacific[i][j-1]=true;
        }
    }

}


void atlantic_ocean_traversal(vector<vector<int>>& heights)
{
    queue<pair<int,int>> q;

    // push all the corner points 
    for(int i=0;i<n;i++)
    {
        vis_atlantic[i][m-1]=true;
        atlantic[i][m-1] = true;
        pair<int,int> temp;
        temp.first=i;
        temp.second=m-1;
        q.push(temp);
    }
    for(int i=0;i<m;i++)
    {
        vis_atlantic[n-1][i]=true;
        atlantic[n-1][i]=true;
        pair<int,int> temp;
        temp.first=n-1;
        temp.second=i;
        q.push(temp);
    }

    while(!q.empty())
    {
        pair<int,int> temp = q.front();
        q.pop();
        
        int i = temp.first;
        int j = temp.second;

        if(isValid(i+1,j) and vis_atlantic[i+1][j] == false and heights[i][j] <= heights[i+1][j])
        {
            q.push({i+1,j});
            vis_atlantic[i+1][j]=true;
            atlantic[i+1][j]=true;
        }
        
        if(isValid(i-1,j) and vis_atlantic[i-1][j] == false and heights[i][j] <= heights[i-1][j])
        {
            q.push({i-1,j});
            vis_atlantic[i-1][j]=true;
            atlantic[i-1][j]=true;
        }

        if(isValid(i,j+1) and vis_atlantic[i][j+1] == false and heights[i][j] <= heights[i][j+1])
        {
            q.push({i,j+1});
            vis_atlantic[i][j+1]=true;
            atlantic[i][j+1]=true;
        }

        if(isValid(i,j-1) and vis_atlantic[i][j-1] == false and heights[i][j] <= heights[i][j-1])
        {
            q.push({i,j-1});
            vis_atlantic[i][j-1]=true;
            atlantic[i][j-1]=true;
        }
    }

}

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
    {
        n = heights.size();
        m = heights[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                pacific[i][j]=false;
                atlantic[i][j]=false;
                vis_pacific[i][j]=false;
                vis_atlantic[i][j]=false;
            }
        }
        pacific_ocean_traversal(heights);
        atlantic_ocean_traversal(heights);
        vector<vector<int>> ans;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(atlantic[i][j] == true and pacific[i][j] == true)
                {
                    vector<int> temp;
                    temp.push_back(i);
                    temp.push_back(j);
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }
};
