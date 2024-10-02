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
    if(set_size[a] > set_size[b])
    {
        par[b]=a;
        set_size[a] += set_size[b]; 
    }
    else
    {
        par[a]=b;
        set_size[b] += set_size[a];
    }
}
class Solution {
public:
    bool equationsPossible(vector<string>& equations) 
    {
        for(int i=0;i<26;i++)
        {
            par[i]=-1;
            set_size[i]=1;
        }
        // traversing through the equality signs and adding them into DSU
        for(int i=0;i<equations.size();i++)
        {
            int a = equations[i][0] - 'a';
            int b = equations[i][3] - 'a';
            if(equations[i][1] == '=' and a!=b)
            {
                int k = find(a);
                int l = find(b);
                if(k!=l)
                merge(k,l);
            }
        }
        for(int i=0;i<equations.size();i++)
        {
            int a = equations[i][0] - 'a';
            int b = equations[i][3] - 'a';
            if(equations[i][1] == '!')
            {
                if(a == b)
                return false;
                int k = find(a);
                int l = find(b);
                if(k==l)
                return false;
            }
        }
        return true;
    }
};
