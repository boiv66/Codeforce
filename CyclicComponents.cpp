#include <iostream>
#include <vector> 
#include <bits/stdc++.h>

using namespace std;
vector<int>connectVertex; 
vector<int>visited; 
bool check;
vector<vector<int>> graph; 

void dfs(int u){
    visited[u] = true; 
    connectVertex.push_back(u); 
    if (graph[u].size() != 2){
        check = false; 
    }
    for (int i = 0; i < graph[u].size(); i++){
        if (!visited[graph[u][i]]){
            dfs(graph[u][i]); 
        }
    }
    
}

void addEdge(int u, int v){
    graph[u-1].push_back(v-1); 
    graph[v-1].push_back(u-1); 
}


int main()
{
   long long vertice; 
   long long edge; 
   
   long long count = 0; 
   cin >> vertice >> edge; 
//   cout << vertice << edge << endl; 
   graph.resize(vertice);
   visited.resize(vertice);
   for (int i; i < vertice; i++){
       visited[i] = false; 
   }
   
   for (int i = 0; i < edge; i++){
        int u; 
        int v; 
        cin >> u >> v;
    
       addEdge(u,v); 
       
   }
   for (int i = 0; i < vertice; i++){
       if(!visited[i]){
           
           check = true; 
           dfs(i); 
           if (check){
            //   cout << "a" << endl;
               count++;
           }
           
       }
       
   }
   cout << count ; 
   return 0;
}