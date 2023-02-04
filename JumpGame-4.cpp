class Solution {
public:
    int minJumps(vector<int>& a) 
    {
        /* Same like jump game 3 , we apply BFS here. But there is slight veriation in this. A node i is connected to (i-1) and (i+1) and also to other 
        nodes j where a[i]=a[j]. So we need to store all the indices where elements are equal and for this we use an unordered map */
        int n = a.size();

        // store indices of equal elements into map
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<n;i++)
        mp[a[i]].push_back(i);

        // BFS
        vector<bool> vis(n,false);
        queue<int> q;
        q.push(0);
        vis[0]=true;
        vector<int> dis(n,1e8);
        dis[0]=0;
        while(!q.empty())
        {
            int temp = q.front();
            q.pop();
            if(temp-1>=0 and vis[temp-1]==false)
            {
                q.push(temp-1);
                vis[temp-1]=true;
                dis[temp-1] = dis[temp]+1;
            }
            if(temp+1<n and vis[temp+1]==false)
            {
                q.push(temp+1);
                vis[temp+1]=true;
                dis[temp+1]=dis[temp]+1;
            }
            // traverse all the nodes which are equal to a[temp]
            for(int i=0;i<mp[a[temp]].size();i++)
            {
                if(mp[a[temp]][i]!=temp and vis[mp[a[temp]][i]]==false)
                {
                    q.push(mp[a[temp]][i]);
                    vis[mp[a[temp]][i]]=true;
                    dis[mp[a[temp]][i]]=dis[temp]+1;
                }
            }
            mp[a[temp]].clear(); // this is very important optimisation step
        }
        return dis[n-1];
    }
};
