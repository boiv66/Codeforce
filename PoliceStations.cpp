#include <iostream>
#include<bits/stdc++.h>
#define ipair pair<long long, long long>

using namespace std;

int main()
{
    long long citi_num; 
    long long station_num; 
    long long distance; 
    
    cin >> citi_num >> station_num >> distance; 
    vector<bool> visited(citi_num+1, false);
    set<long long> e_road; 
    
    
    
    vector<ipair> vertice[1000000]; 
    // vertice.resize(citi_num+1);
    visited.resize(citi_num+1);
    queue <long long> q; 
    for (long long i = 0; i < station_num; i++){
        long long temp; 
        cin >> temp; 
        q.push(temp); 
        visited[temp] = true; 
    }
    
    
    
    for (long long i = 1; i < citi_num; ++i){
        long long a; 
        long long b; 
        cin >> a >> b; 
        vertice[a].push_back(ipair(b, i)); 
        vertice[b].push_back(ipair(a, i)); 
        e_road.insert(i); 
    }
    
    while(!q.empty()){
        long long u = q.front(); 
        q.pop(); 
        // visited[u] = true; 
        for (ipair i: vertice[u]){
            long long connected_citi = i.first; 
            long long road = i.second; 
            if (!visited[connected_citi]){
                q.push(connected_citi); 
                visited[connected_citi] = true; 
                e_road.erase(road); 
            }
        }
    }
    
    cout << e_road.size() << endl; 
    for (long long i: e_road){
        cout << i << " "; 
    }
    
    
    
    
   
   return 0;
}