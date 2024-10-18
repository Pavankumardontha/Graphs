/*
dp[i][j] will give the maximum length of the path starting at index (i,j)

IMPORTANT POINTS: 
If we have calculated optimal path for matrix[0][0] and suppose that it is 
- (0,0) -> (0, 1) -> (0, 2) -> (1, 2) ->(1, 1) ->(1, 0), which is 6 in length. Now, for finding the optimal path for matrix[0][1], there's no need to recalculate the path again because it is part of optimal path of matrix[0][0] and for getting the optimal path for matrix[0][0], we must also have gotten the optimal path of its adjacent visitable cells. So, optimal answer for matrix[0][1] could have directly been returned as 5 if we had used DP.

- once we calculate the optimal answer for a cell, we most probably have also recursed for its adjacent cells and calculated the optimal answers for them as well.

- The problem has optimal substructure property meaning that the solutions of bigger problems can be calculated from optimal solutions of its sub-problems. So, if there's a longest path (optimal solution) for a given cell starting at that cell, all the cells in its path must also have optimal paths as well starting at those cells respectively.


*/

int n;
int m;
int g[201][201];
int dp[201][201];
bool isValid(int i, int j)
{
    if(i>=0 and i<n and j>=0 and j<m)
    return true;
    return false;
}

int solve(int i, int j)
{
    if(dp[i][j] != -1)
    return dp[i][j];
    
    /* from (i,j) we can move to 4 directions */
    int max_path_length = 1;
    // down
    if(isValid(i+1,j) and g[i][j] < g[i+1][j])
    max_path_length = max(max_path_length , 1 + solve(i+1,j));
    // up
    if(isValid(i-1,j) and g[i][j] < g[i-1][j])
    max_path_length = max(max_path_length , 1 + solve(i-1,j));
    
    // left
    if(isValid(i,j-1) and g[i][j] < g[i][j-1])
    max_path_length = max(max_path_length , 1 + solve(i,j-1));

    // right
    if(isValid(i,j+1) and g[i][j] < g[i][j+1])
    max_path_length = max(max_path_length , 1 + solve(i,j+1));

    return dp[i][j] = max_path_length;

}

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) 
    {
        n = matrix.size();
        m = matrix[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                dp[i][j] = -1;
                g[i][j] = matrix[i][j];
            }
        }
        int max_path_length = 1;
        // calculate maximum path length for each (i,j)
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                max_path_length = max(max_path_length,solve(i,j));
            }
        }
        return max_path_length;
    }
};
