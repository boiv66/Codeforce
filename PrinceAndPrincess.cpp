#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include<bits/stdc++.h>

using namespace std;


int main()
{
    int n;
    cin >> n;
    // long long d;
    
    // vector<vector<long long>>arr;
    // vector<long long> arrN; 
    
    // string input; 

    for(int i=0; i<n;i++) {
    
        int tmp; 
        cin >> tmp;
        vector<bool> married(tmp, false);
        // cout << "tmp: " << tmp << endl; 
        // vector<long long> temp; 
        int unmarried_princess = -1; 
        for (int j = 0; j < tmp; j++){
           int list_count; 
           cin >> list_count; 
           bool princess = false; 
        //   cout << "list count " << list_count << endl; 
            while(list_count--){
               int b; 
               cin >> b; 
               
            //   cout << "b " << b << endl; 
               if (!princess && !married[b-1]){
                   married[b-1] = true; 
                   princess = true; 
                    
               }
           }
           if (!princess) {
               unmarried_princess = j; 
               
           }
        }
        if (unmarried_princess == -1){
            cout << "OPTIMAL" << endl; 
            
        }
        else{
            cout << "IMPROVE" << endl; 
            cout << unmarried_princess + 1 << " "; 
            for (int j = 0; j < tmp; j++){
                if (married[j] == false){
                    // cout << "unmarried prince"  << unmarried_princess << j + 1 ;
                    cout << j + 1 << endl; 
                    break;
                }
            }
        }
        
        
        
    }
    
    // for (int i = 0; i < n ; i++){
    //     for 
    // }
    
    

    return 0; 
}