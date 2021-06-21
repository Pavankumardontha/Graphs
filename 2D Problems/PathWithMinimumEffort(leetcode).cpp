#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution 
{
public:
    int minimumEffortPath(vector<vector<int>>& height) 
    {
        /* we will first define the direction matrix which describes all possible directions 
        that we can take. 
        direction order = up,down,left and right.*/
        int dirx[4] = {-1,+1,0,0};
        int diry[4] = {0,0,-1,+1};
        /* we are using dijikstra here and hence we need a priority queue of pair<int,int>.
        but here there is a slight variation since the nodes are 2D points and not single 
        points like in traditional graphs. In general,
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        we have the above type priority queue for our normal graph. where the first element 
        represents the distance and the second element reqpresents the node which is 1D in 
        traditional graphs. We will modify this to represent 2D graph nodes.We also need a distance
        matrix as well.*/
        
        int n = height.size(); //rows
        int m = height[0].size();  //columns
        int dis[n][m]; //effort[i][j]
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                dis[i][j] = INT_MAX;
        }
priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}}); /*this is like the source point.!! (r-1,c-1) will be our destination point.*/
        while(!pq.empty())
        {
            pair<int,pair<int,int>> temp = pq.top();
            pq.pop();
            int effort = temp.first; //maximum difference between consecutive elements till now
            pair<int,int> node = temp.second;
            if(node.first==n-1 && node.second==m-1)
                return effort;
            else
            {
                /* we will traverse all the children of our current node.*/
                for(int i=0;i<4;i++)
                {
                    /* x = x-coordinate of child 
                    y = y-coordinate of child
                    */
                    int x = node.first + dirx[i];
                    int y = node.second + diry[i];
                    if(x<0 || y<0 || x>=n || y>=m)
                        continue;
                    else
                    {
                        if(dis[x][y]>max(effort,abs(height[x][y]-height[node.first][node.second])))
                        {
                            dis[x][y] = max(effort,abs(height[x][y]-height[node.first][node.second]));
                            pq.push({dis[x][y],{x,y}});
                        }
                    }
                }
            }
        }
        return 0;
    }
};
