/* link :- https://www.youtube.com/watch?v=amvrKlMLuGY */

int n;
bool vis[55][55];
bool isValid(int x,int y)
{
    if(x>=0 && x<n && y>=0 && y<n)
    {
        if(vis[x][y]==false)
            return true;
        else
            return false;
    }
    else
        return false;
}
class Solution {
public:
    int swimInWater(vector<vector<int>>& g) 
    {
priority_queue< pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> ,greater<pair<int,pair<int,int>>> > pq;
        int dirx[4] = {1,-1,0,0};
        int diry[4] = {0,0,-1,1};
        n = g.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                vis[i][j] = false;
            }
        }
        pq.push({g[0][0],{0,0}});
        vis[0][0]=true;
        int ans;
        while(!pq.empty())
        {
            pair<int,pair<int,int>> temp = pq.top();
            pq.pop();
            int max_node = temp.first;
            int x = temp.second.first;
            int y = temp.second.second;
            if(x==n-1 && y==n-1)
                return ans = max(max_node,g[x][y]);
            else
            {
                for(int i=0;i<4;i++)
                {
                    int childx = x + dirx[i];
                    int childy = y + diry[i];
                    if(isValid(childx,childy))
                    {
                        vis[childx][childy] = true;
                        int res = max(max_node,g[childx][childy]);
                        pq.push({res,{childx,childy}});
                    }
                }
            }
        }
        return ans;
    }
};
