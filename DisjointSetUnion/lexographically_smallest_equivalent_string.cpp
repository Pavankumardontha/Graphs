int par[26];
int set_size[26];
int find(int a)
{
    if(par[a]<0)
    return a;
    else
    return find(par[a]);

}
void merge(int a,int b)
{
    if(set_size[a] < set_size[b])
    {
        par[a]=b;
        set_size[b] += set_size[a];
    }
    else
    {
        par[b]=a;
        set_size[a] += set_size[b];
    }
}

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) 
    {
        for(int i=0;i<26;i++)
        {
            par[i]=-1;
            set_size[i]=1;
        }
        int n = s1.length();
        for(int i=0;i<n;i++)
        {
            // add both equivalents into one set
            int a = s1[i]-'a';
            int b = s2[i]-'a';
            int k = find(a);
            int l = find(b);
            if(k!=l)
            merge(k,l);
        }
        unordered_map<int,char> mp; // this stores the parent as key and the corresponding smallest lexographical character belonging to that set
        for(int i=0;i<n;i++)
        {
            // for each parent , find the smallest lexographical character in the entire set
            int a = s1[i]-'a';
            int parent = find(a);
            if(mp.find(parent) != mp.end())
            {
                if(s1[i] < mp[parent])
                mp[parent]=s1[i];
                if(s2[i] < mp[parent])
                mp[parent]=s2[i];
            }
            else
            {
                if(s1[i] < s2[i])
                mp[parent]=s1[i];
                else
                mp[parent]=s2[i];
            }
        }
        string ans="";
        for(int i=0;i<baseStr.size();i++)
        {
            int a = baseStr[i]-'a';
            int parent = find(a);
            if(mp.find(parent) != mp.end())
            ans = ans + mp[parent];
            else
            ans = ans + baseStr[i];
        }
        return ans;
    }
};
