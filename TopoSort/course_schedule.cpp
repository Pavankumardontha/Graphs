vector<int> g[2001];
int in[2001];
int n,m;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {

        n = numCourses;
        for(int i=0;i<n;i++)
        {
            in[i]=0;
            g[i].clear();
        }
        for(int i=0;i<prerequisites.size();i++)
        {
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            // b is prerequisite to a 
            g[b].push_back(a);
            in[a]++;
        }
        queue<int> q;
        vector<int> res;
        for(int i=0;i<n;i++)
        {
            if(in[i]==0)
            q.push(i);
        }
        while(!q.empty())
        {
            int temp = q.front();
            q.pop();
            res.push_back(temp);
            for(int i=0;i<g[temp].size();i++)
            {
                int child = g[temp][i];
                in[child]--;
                if(in[child] == 0)
                q.push(child);
            }
        }
        if(res.size() == n)
        return true;
        else
        return false;
        
    }
};
