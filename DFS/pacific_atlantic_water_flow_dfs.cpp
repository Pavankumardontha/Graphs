/*
atlantic[i][j] = 1 if from rain water from point (i,j) we can reach atlantic ocean
atlantic[i][j] = -1 if (i,j) is not solved
atlantic[i][j] = 0 if rain water from point (i,j) cannot reach to atlantic ocean
same goes with pacific ocean too. 
dp[i][j] = 1 if from point (i,j) we can each both pacific and atlantic ocean
*/
int n,m;
int dp[201][201];
int atlantic[201][201];
int pacific[201][201];
bool vis_pacific[201][201]; // visited array for pacific ocean iteration
bool vis_atlantic[201][201];
bool isValid(int i,int j)
{
    if(i>=0 and i<n and j>=0 and j<m)
    return true;
    return false;
}


bool can_reach_pacific(int i, int j, vector<vector<int>>& heights)
{
    /*
    Lets say this cell is called by some (x,y) cell which is one of the adjacent cell to (i,j)
    We will explore all the possible adjacent cells other than (x,y) and see if we can reach 
    pacific ocean or not. Sometimes we cannot reach pacific ocean from (i,j) leaving the route 
    (x,y) from which (i,j) was called. But there is a change that water can flow from (x,y) from 
    some other route other than (i,j). So pacific[i][j] will only be false if and only if all the
    ways are explored.
    */
    if(pacific[i][j] !=-1)
    return pacific[i][j];
    if(i==0 or j==0)
    return pacific[i][j]=1;
    vis_pacific[i][j]=true;

    bool all_paths_explored=true;
    bool ans1=false,ans2=false,ans3=false,ans4=false;
    if(isValid(i+1,j) and heights[i][j]>=heights[i+1][j])
    {
        if(vis_pacific[i+1][j])
        all_paths_explored=false;
        else
        ans1 = can_reach_pacific(i+1,j,heights);
    }
    if(isValid(i,j+1) and heights[i][j] >= heights[i][j+1])
    {
        if(vis_pacific[i][j+1])
        all_paths_explored=false;
        else
        ans2 = can_reach_pacific(i,j+1,heights);
    }
    if(isValid(i-1,j) and heights[i][j] >= heights[i-1][j])
    {
        if(vis_pacific[i-1][j])
        all_paths_explored=false;
        else
        ans3 = can_reach_pacific(i-1,j,heights);
    }
    if(isValid(i,j-1) and heights[i][j] >= heights[i][j-1])
    {
        if(vis_pacific[i][j-1])
        all_paths_explored=false;
        else
        ans4 = can_reach_pacific(i,j-1,heights);
    }
    vis_pacific[i][j]=false;
    if(ans1 or ans2 or ans3 or ans4)
    return pacific[i][j] = true;
    else
    {
        if(all_paths_explored) // we assign false to pacific[i][j] only after we explore all the possible paths from i,j
        return pacific[i][j]=false;
        else
        return false; // do not assign false to pacific[i][j] since there are paths that are yet to be explored 
    }
}

bool can_reach_atlantic(int i,int j, vector<vector<int>>& heights)
{
    if(atlantic[i][j] !=-1)
    return atlantic[i][j];
    if(i==n-1 or j==m-1)
    return atlantic[i][j] = 1;

    vis_atlantic[i][j]=true;
    bool ans1=false;
    bool ans2=false;
    bool ans3=false;
    bool ans4=false;
    bool all_paths_explored=true;
    if(isValid(i+1,j) and heights[i][j] >= heights[i+1][j])
    {
        if(vis_atlantic[i+1][j])
        all_paths_explored=false;
        else
        ans1 = can_reach_atlantic(i+1,j,heights);
    }
    if(isValid(i,j+1) and heights[i][j] >= heights[i][j+1])
    {
        if(vis_atlantic[i][j+1])
        all_paths_explored=false;
        else
        ans2 = can_reach_atlantic(i,j+1,heights);
    }
    if(isValid(i-1,j) and heights[i][j] >= heights[i-1][j])
    {
        if(vis_atlantic[i-1][j])
        all_paths_explored=false;
        else
        ans3 = can_reach_atlantic(i-1,j,heights);
    }
    if(isValid(i,j-1) and heights[i][j] >= heights[i][j-1])
    {
        if(vis_atlantic[i][j-1])
        all_paths_explored=false;
        else
        ans4 = can_reach_atlantic(i,j-1,heights);
    }
    vis_atlantic[i][j]=false;
    if(ans1 or ans2 or ans3 or ans4)
    return atlantic[i][j] = true;
    else
    {
        if(all_paths_explored)
        return atlantic[i][j]=false;
        else
        return false; // do not assign false to atlantic[i][j] since there are paths that are yet to be explored
    }
}

int solve(int i, int j, vector<vector<int>>& heights)
{
    if(dp[i][j] != -1)
    return dp[i][j];
    dp[i][j] = can_reach_pacific(i,j,heights) and can_reach_atlantic(i,j,heights);
    //dp[i][j] = can_reach_pacific(i,j,heights);
    //dp[i][j] = can_reach_atlantic(i,j,heights);
    return dp[i][j];
}
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
    {
        n = heights.size();
        m = heights[0].size();
        vector<vector<int>> ans;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                dp[i][j] =-1;
                atlantic[i][j] = -1;
                pacific[i][j] = -1;
                vis_pacific[i][j]=false;
                vis_atlantic[i][j]=false;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                solve(i,j,heights);
                if(dp[i][j])
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
