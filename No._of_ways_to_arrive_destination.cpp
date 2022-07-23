// link :- https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/

/*We use Dijkstra algorithm to find the Shortest Path from src = 0 to dst = n - 1.While dijkstra, we create additional ways array, where ways[i] keeps the number of shortest path from src = 0 to dst = i. Then the answer is ways[n-1].*/
priority_queue<pair<long long,int> , vector<pair<long long,int>> , greater<pair<long long,int>>> pq;
vector<pair<long long,int>> g[201];
long long int dis[201];
long long int MOD = 1e9 + 7;
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) 
    {
        int src = 0;
        int destination = n-1;
        for(int i=0;i<n;i++)
        {
            g[i].clear();
            dis[i]=LONG_MAX;
        }
        dis[src]=0;
        long long int ways[n];
        ways[0]=1;
        pq.push(make_pair(0,src));
        for(int i=0;i<roads.size();i++)
        {
            g[roads[i][0]].push_back(make_pair(roads[i][2],roads[i][1]));
            g[roads[i][1]].push_back(make_pair(roads[i][2],roads[i][0]));
            
        }
        while(!pq.empty())
        {
            pair<int,int> temp = pq.top();
            pq.pop();
            int v = temp.second;
            int d = temp.first;
            if(d > dis[v])
                continue;
            for(int i=0;i<g[v].size();i++)
            {
                int child = g[v][i].second;
                if(dis[child]>dis[v] + g[v][i].first)
                {
                    dis[child] = dis[v] + g[v][i].first;
                    pq.push(make_pair(dis[child],child));
                    ways[child]=ways[v];
                }
                else if(dis[child]==dis[v] + g[v][i].first)
                    ways[child] = (ways[child] + ways[v])%MOD;
            }
        }
        return ways[n-1];
    }
};
