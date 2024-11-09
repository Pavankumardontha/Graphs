class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        /*
        At first we will have all the terminal nodes out_degree as 0
        The graph which is given will give us the outgoing nodes if we are at node i from graph[i]
        We will remove the terminal nodes first and try to decrement the out degree of all its parent nodes
        If any of the parent nodes( nodes by which we can reach the terminal nodes) out degree becomes 0 , then
        it means that its a safe node. We repeat this process for all the terminal nodes and it gives all the safe nodes
        But to get the parent nodes of i , we need to also have the reverse graph where 
        graph[i] -> gives all the outgoing edges from node i 
        reverse_graph[i] -> gives all the incoming edges to node i
        Its like applying toposort on the reverse graph. In the toposort we consider in degree and apply toposort in normal
        graph. But here we consider out degree and apply toposort on the reverse graph
        */
        vector<int> terminal_nodes;
        int n = graph.size();
        int out_degree[n];
        queue<int> q; // toposort queue. We start by pushing all the terminal nodes into this since their out degree is 0
        for(int i=0;i<graph.size();i++)
        {
            out_degree[i] = graph[i].size();
            if(out_degree[i]==0)
            q.push(i);
        }
        vector<int> reverse_graph[n];
        for(int i=0;i<graph.size();i++)
        {
            for(int j=0;j<graph[i].size();j++)
            {
                reverse_graph[graph[i][j]].push_back(i);
            }
        }
        vector<int> safe_nodes; // all terminal nodes are safe nodes
        while(!q.empty())
        {
            int temp = q.front();
            safe_nodes.push_back(temp);
            q.pop();
            for(int i=0;i<reverse_graph[temp].size();i++)
            {
                int parent = reverse_graph[temp][i];
                out_degree[parent]--;
                if(out_degree[parent]==0)
                q.push(parent);
            }
        }
        sort(safe_nodes.begin(),safe_nodes.end());
        return safe_nodes;
    }
};
