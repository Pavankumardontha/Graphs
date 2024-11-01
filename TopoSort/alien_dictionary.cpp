class Solution {
  public:
    string findOrder(string dict[], int n, int k) 
    {
        /*
        there are k words in dictionary
        at each step we compare 2 consecutive words in the 
        dictionary and create a relation out of this.
        dict[0] , dict[1] --> one relation
        dict[i] , dict[2] --> one relation
        .
        .
        .
        and so on....
        we consider the letters as nodes from 0 to 25
        */
        vector<int> g[k];
        vector<int> in(k,0); //indegree
        for(int i=0;i<n-1;i++)
        {
            string s1 = dict[i];
            string s2 = dict[i+1];
            int n1 = s1.length();
            int n2 = s2.length();
            int l=0;
            while(l<n1 and l<n2)
            {
                if(s1[l] != s2[l])
                {
                    /* s1[l] comes before s2[l] So there is an edge from s1[l] to s2[l] */
                    int a = s1[l]-'a';
                    int b = s2[l]-'a';
                    g[a].push_back(b);
                    in[b]++;
                    break;
                }
                l++;
            }
        }
        // we have got all the relations now.We will apply topo sort
        queue<int> q;
        string ans="";
        for(int i=0;i<k;i++)
        {
            if(in[i]==0)
            q.push(i);
        }
        while(!q.empty())
        {
            int temp = q.front();
            q.pop();
            char c = 'a' + temp;
            ans = ans + c;
            for(int i=0;i<g[temp].size();i++)
            {
                int child = g[temp][i];
                in[child]--;
                if(in[child] == 0)
                q.push(child);
            }
        }
        return ans;
    }
};
