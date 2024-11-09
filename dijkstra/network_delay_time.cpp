class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        vector<pair<int,int>> g[n+1];
        for(int i=0;i<times.size();i++)
        {
            int a = times[i][0];
            int b = times[i][1];
            int t = times[i][2];
            g[a].push_back({t,b});
        }
        int dis[n+1];
        for(int i=1;i<=n;i++)
        dis[i]=INT_MAX;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        dis[k]=0;
        while(!pq.empty())
        {
            pair<int,int> temp = pq.top();
            pq.pop();
            int v = temp.second;
            int d = temp.first;
            for(int i=0;i<g[v].size();i++)
            {
                int child = g[v][i].second;
                int weight = g[v][i].first;
                if(dis[child] > d + weight)
                {
                    dis[child] = d + weight;
                    pq.push({dis[child],child});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        ans = max(ans,dis[i]);
        if(ans==INT_MAX)
        return -1;
        return ans;
    }
};
