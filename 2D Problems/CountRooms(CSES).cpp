#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int n;
int m;
bool vis[1001][1001];
char g[1001][1001];
bool isValid(int x,int y)
{
    if(x>=0 && x<n && y>=0 && y<m)
    {
        if(vis[x][y]==false && g[x][y]=='.')
        return true;
        else
        return false;
    }
    return false;
}
void dfs(int x,int y)
{
    vis[x][y] = true;
    /* we have children in 4 directions */
    if(isValid(x-1,y))
    dfs(x-1,y);
    if(isValid(x+1,y))
    dfs(x+1,y);
    if(isValid(x,y-1))
    dfs(x,y-1);
    if(isValid(x,y+1))
    dfs(x,y+1);
    return;
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        cin>>g[i][j];
    }
    memset(vis,false,sizeof(vis));
    int cnt = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(vis[i][j]==false && g[i][j]=='.')
            {
                dfs(i,j);
                cnt++;
            }
            else
            continue;
        }
    }
    cout<<cnt<<endl;
}
