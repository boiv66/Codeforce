#include <iostream>
#include <vector>

using namespace std;


long long con_Cat; 
long long count = 0; 
long long vertice; 
vector<long long> cat; 
vector<vector<long long>> tree;
// long long cat[100005]; 
// vector<long long> tree[100005];

void dfs (long long current, long long previous, long long consecutive){
   
    if (consecutive > con_Cat) return; 
    
    bool leaf = true; 
    
    for (long long i = 0; i < tree[current].size(); i++){
        long long next = tree[current][i]; 
        // the vertex is leaf when the next == previous, 
        // they only have 1 edge, connecting with their previous
        if (next == previous){
            continue; 
        }
        
        leaf = false; 
        if (cat[next]){
            dfs(next, current , consecutive+1);
        }
        else {
            dfs(next, current, 0);
        }
    }
    if (leaf){
        count ++; 
    }
    return; 
    
    
}

int main()
{
 
    
 
   cin >> vertice;
   
   
   cin >> con_Cat; 
   tree.resize(vertice);
//   cout << vertice; 
//   cout << con_Cat; 
   
//   tree.resize(vertice-1); 
   
   for (int i=0; i < vertice; i++){
        long long temp; 
        cin >> temp; 
        cat.push_back(temp); 
        // cat[i] = temp; 
        
       
   }
    
    
//   
   
   for (int i = 0; i < vertice - 1 ; i++){
       long long x; 
       long long y; 
       cin >> x >> y; 
       tree[x-1].push_back(y-1); 
       tree[y-1].push_back(x-1); 
    //   cout << "A"<< endl; 
   }
   
    // cout << tree[1][0] << endl ; 
   
  
   
    dfs(0, -1, cat[0]); 
   
    cout  << count << endl; 
   
   
   return 0;
}