// link :- https://leetcode.com/problems/word-ladder/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        queue<pair<int,string>> q;
        unordered_set<string> words;
        for(int i=0;i<wordList.size();i++)
            words.insert(wordList[i]);
        if(words.find(endWord)==words.end())
            return 0;
        q.push({1,beginWord});
        while(!q.empty())
        {
            pair<int,string> temp = q.front();
            string s = temp.second;
            int distance = temp.first;
            q.pop();
            for(int i=0;i<s.length();i++)
            {
                string original = s;
                for(char c='a';c<='z';c++)
                {
                    original[i]=c;
                    if(original==endWord)
                        return distance+1;
                    if(words.find(original)!=words.end())
                    {
                        words.erase(original);
                        q.push({distance+1,original});
                    }
                }
            }
        }
        return 0;
    }
};
