class Solution {
public:
    int jump(vector<int>& a) 
    {
        int n = a.size();
        vector<bool> vis(n,false);
        vector<int> dis(n,1e8);
        queue<int> q;
        q.push(0);
        vis[0]=true;
        dis[0]=0;
        while(!q.empty())
        {
            int ind = q.front();
            q.pop();
            for(int i=1;i<=a[ind];i++)
            {
                if(ind+i<n and vis[ind+i]==false)
                {
                    q.push(ind+i);
                    vis[ind+i]=true;
                    dis[ind+i] = dis[ind]+1;
                }
            }
        }
        return dis[n-1];
    }
};
