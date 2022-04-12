#include <iostream>
#include <vector> 
using namespace std;

int main()
{
    
    long long emp_num = 0; 
    cin >> emp_num;
    
    vector<long long> quaf;
    vector<long long> cost_Array; 
    vector<vector<long long>> app; 
    
    for (int i = 0; i < emp_num; i++){
        long long temp; 
        cin >> temp; 
        quaf.push_back(temp); 
    }
    
    long long app_num; 
    long long employee = 0;
    long long cost = 0; 
    cin >> app_num; 
    
    vector<long long> visited (emp_num + 1, false); 
    
    app.resize(app_num + 1); 
    cost_Array.resize(emp_num + 1);
    
    for(int i = 1; i <= app_num; i++){
        long long a,b,c; 
        cin >> a >> b >> c; 
        // app[i].push_back(a); 
        // app[i].push_back(b);
        // app[i].push_back(c); 
        
        if(!visited[b]){
            employee++; 
            cost += c; 
            cost_Array[b] = c; 
            visited[b] = true; 
            
        }
        else{
            if (cost_Array[b] > c){
                cost = cost - cost_Array[b] + c;
			cost_Array[b] = c; 
                
            }
        }
         
    }
    
    if (employee == emp_num - 1){
        cout << cost << endl ; 
    }
    else {
        cout << -1 << endl; 
    }
    
    // for(int i = 1; i <= app_num; i++){
    //     for (int j = 0; j < 3; j++){
    //         cout << app[i][j] << " "; 
    //     }
    //     cout << endl; 
    // }
    
    

   
   return 0;
}