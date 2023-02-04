class Solution {
public:
    bool canReach(vector<int>& a, int start) 
    {
        int n = a.size();
        vector<bool> vis(n,false);
        queue<int> q;
        q.push(start);
        vis[start]=true;
        while(!q.empty())
        {
            int ind = q.front();
            q.pop();
            if(a[ind]==0)
            return true;
            // ind might have 2 children that is ind-a[ind] and ind+a[ind]
            if(ind-a[ind]>=0 and vis[ind-a[ind]]==false)
            {
                q.push(ind-a[ind]);
                vis[ind-a[ind]]=true;
            }
            if(ind+a[ind]<n and vis[ind+a[ind]]==false)
            {
                q.push(ind+a[ind]);
                vis[ind+a[ind]]=true;
            }
        }
        return false;
    }
};
