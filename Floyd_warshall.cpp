/*
The Floyd Warshall Algorithm is for solving the All Pairs Shortest Path problem. The problem is to find shortest distances between every pair of vertices
in a given edge weighted directed Graph. Dijkstra finds the distance of all the nodes from a given source node. Understand the difference between both.
*/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int n,m;
int dis[101][101];

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j)
            dis[i][j]=0;
            else
            dis[i][j]=INT_MAX;
        }
    }
    int a,b,w;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b>>w;
        dis[a][b]=w;
    }
    for(int k=1;k<=n;k++) //src 
    { 
        for(int i=1;i<=n;i++)  //final 
        {
            //our aim is to calculate minimum distance between (k,i)
            for(int j=1;j<=n;j++) //middle man 
            {
                if(dis[k][j]!=INT_MAX && dis[j][i]!=INT_MAX) //route present or not  
                if(dis[k][i] > dis[k][j] + dis[j][i]) //compare the distance 
                dis[k][i] = dis[k][j] + dis[j][i];   //update 
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        cout<<dis[i][j]<<" ";
        cout<<endl;
        
    }
}

