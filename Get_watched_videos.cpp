// link :- https://leetcode.com/problems/get-watched-videos-by-your-friends/
/* solved using BFS */ 
vector<int> g[101];
bool vis[101];
int n;
class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) 
    {
        memset(vis,false,sizeof(vis));
        for(int i=0;i<n;i++)
            g[i].clear();
        for(int i=0;i<friends.size();i++)
        {
            for(int j=0;j<friends[i].size();j++)
            {
                int k = friends[i][j];
                g[i].push_back(k);
            }
        }
        n = friends.size();
        int dis[n];
        queue<int> q;
        q.push(id);
        vis[id]=true;
        dis[id]=0;
        while(!q.empty())
        {
            int node = q.front();
            // DO NOT SET vis[node] = true here. Set while pushing into the queue. If not there might be a chance of pushing the same node more than twice. !!!
            q.pop();
            for(int i=0;i<g[node].size();i++)
            {
                int child = g[node][i];
                if(!vis[child])
                {
                    dis[child] = dis[node] + 1;
                    q.push(child);
                    vis[child]=true; // MOST IMPORTANT STEP
                }
            }
        }
        vector<int> nodes_at_level;
        for(int i=0;i<n;i++)
        {
            if(dis[i]==level)
                nodes_at_level.push_back(i);
        }
        unordered_map<string,int> freq;
        for(int i=0;i<nodes_at_level.size();i++)
        {
            int k1 = nodes_at_level[i];
            vector<string> videos = watchedVideos[k1];
            for(int j=0;j<videos.size();j++)
                freq[videos[j]]++;
        }
        set<pair<int,string>> s;
        for(auto i=freq.begin();i!=freq.end();i++)
        {
            s.insert(make_pair(i->second,i->first));
            //cout<<i->first<<endl;
        }
        vector<string> res;
        for(auto &x : s)
            res.push_back(x.second);
        return res;
        
    }
};
