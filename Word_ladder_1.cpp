// link :- https://leetcode.com/problems/word-ladder/

vector<int> g[5001];
bool differbyone(string s1, string s2)
{
    int count = 0;
    if(s1.length()!=s2.length())
        return false;
    else
    {
        int n = s1.length();
        int c = 0;
        for(int i=0;i<n;i++)
        {
            if(s1[i]!=s2[i])
                c=c+1;
        }
        if(c==1)
            return true;
        else
            return false;
    }
}
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        //check if endWord is present or not
        int endword_index = -1;
        int beginword_index = -1;
        for(int i=0;i<wordList.size();i++)
        {
            if(endWord==wordList[i])
                endword_index = i;
            if(beginWord==wordList[i])
                beginword_index = i;
        }
        if(endword_index==-1)
            return 0;
        
        // push the beginword into the wordlist if it is not present in the wordList
        if(beginword_index==-1)
        {
            wordList.push_back(beginWord);
            beginword_index = wordList.size()-1;
        }
        int n = wordList.size();
        for(int i=0;i<n;i++)
            g[i].clear();
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                // if both the strings differ by one character then there exists an edge between them
                bool check_diff = differbyone(wordList[i],wordList[j]);
                if(check_diff)
                {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        int dis[n];
        for(int i=0;i<n;i++)
            dis[i]=INT_MAX;
        bool vis[n];
        for(int i=0;i<n;i++)
            vis[i]=false;
        dis[beginword_index]=0;
        queue<int> q;
        q.push(beginword_index);
        vis[beginword_index]=true;
        while(!q.empty())
        {
            int v = q.front();
            q.pop();
            for(int i=0;i<g[v].size();i++)
            {
                int child = g[v][i];
                if(!vis[child])
                {
                    dis[child] = dis[v] + 1;
                    q.push(child);
                    vis[child]=true;
                }
            } 
        }
        if(dis[endword_index]==INT_MAX)
            return 0;
        else
            return dis[endword_index]+1;
        
    }
};
