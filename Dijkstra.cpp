#include <iostream>
#include<bits/stdc++.h>
#include<vector>

#define ipair pair<int, int> 

using namespace std;


vector<int>parent; 
vector<int>visited; 
vector<int>distanceE; 
vector<int> shorted; 
int source = 0; 
const int N = 100000; 

vector<pair<int, int>> weight[N];

bool dij(int source, long long end){
    end--; 
    priority_queue< ipair, vector<ipair>, greater<ipair>> pq; 
    pq.push(ipair(0, source)); 
    while(!pq.empty()){
        int vis = pq.top().second; 
        pq.pop(); 
        if(vis == end){
            return true; 
            
        }
        visited[vis] = true; 
        for (auto i: weight[vis]){
            int v = i.first; 
            int w = i.second; 
            if (!visited[v] && distanceE[vis] + w < distanceE[v]){
                distanceE[v] = distanceE[vis] + w; 
                parent[v] = vis; 
                pq.push(ipair(distanceE[v], v)); 
            }
        }
        
    }
    return false; 
    
    
}

void addEdge(int u, int v, int cost){
    // cout << u << " " << v << endl; 
    weight[u-1].push_back(make_pair(v-1,cost)); 
    weight[v-1].push_back(make_pair(u-1, cost)); 
}

void initDistance(long long vertice){
    for (int i =0; i < vertice; i++){
        distanceE.push_back(INT_MAX);
    }
    
    
}
int main()
{
   long long vertice; 
   long long edge; 
   
   long long count = 0; 
   cin >> vertice >> edge; 
//   cout << vertice << edge << endl; 
//   graph.resize(vertice);
   visited.resize(vertice);
   parent.resize(vertice); 
   
   for (int i; i < vertice; i++){
       visited[i] = false; 
   }
   
   for (int i = 0; i < edge; i++){
        int u; 
        int v; 
        int cost; 
        
        cin >> u >> v >> cost;
     
      addEdge(u,v, cost);
       
   } 
   
    initDistance(vertice); 
    parent[source] = -1; 
    distanceE[source] = 0; 
   
   if (dij(0,vertice)){
       long long temp = vertice -1; 
       while (temp != -1){
           shorted.push_back(temp); 
           temp = parent[temp]; 
           
       }
      
       for (int i = shorted.size() - 1; i >= 0; i--){
           cout << shorted[i] + 1 << " "; 
       }
       
   }
   else{
       cout << -1 ; 
   }
   
   cout << endl; 
}