class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) 
    {
        vector<pair<double,int>> g[n];
        priority_queue<pair<double,int>> pq; // we do not need a minimum heap here since we want to first explore paths nodes with higher probability of reaching from start node
        double probability[n]; // instead of distance its probability here
        for(int i=0;i<n;i++)
        probability[i]=0.0; // We want the maximum probability so we initialise it with 0
        for(int i=0;i<edges.size();i++)
        {
            int a = edges[i][0];
            int b = edges[i][1];
            double w = succProb[i];
            g[a].push_back({w,b});
            g[b].push_back({w,a});
        }
        probability[start_node]=1.0;
        pq.push({1.0,start_node});
        while(!pq.empty())
        {
            pair<double,int> temp = pq.top();
            pq.pop();
            double prob = temp.first;
            int v = temp.second;
            if(probability[v] > prob)
            continue;
            for(int i=0;i<g[v].size();i++)
            {
                int child = g[v][i].second;
                double weight = g[v][i].first;
                if(probability[child] < probability[v]*weight )
                {
                    probability[child] = probability[v]*weight;
                    pq.push({probability[child],child});
                }
            }
        }
        return probability[end_node];
    }
};
