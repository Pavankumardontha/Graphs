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
    // NOTE :- The order of the loop is very important.Always middle man will be the first loop. !!!!!!!
    for(int k=1;k<=n;k++) //middle man 
    { 
        for(int i=1;i<=n;i++)  // src 
        {
            //our aim is to calculate minimum distance between (k,i)
            for(int j=1;j<=n;j++) // final 
            {
                if(dis[i][k]!=INT_MAX && dis[k][j]!=INT_MAX) //route present or not  
                if(dis[i][j] > dis[i][k] + dis[k][j]) //compare the distance 
                dis[i][j] = dis[i][k] + dis[k][j];   //update 
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

/* 
Test case :- 
4 4 
1 2 8
2 3 9
3 4 10
4 1 11 

solution :- 
0 8 17 27
30 0 9 19
21 29 0 10
11 19 28 0 
*/
