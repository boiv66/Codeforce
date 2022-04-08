#include <iostream>
#include <vector>
using namespace std;

void select_pair(vector<int>boy, vector<int>girl, int pair, vector<int>boy_count, vector<int>girl_count){
    
    long long comb = 0;
    
    // cout << "pair: " << pair << endl; 
    for (int i = 0; i< pair; i++){
        // cout << "boy count: " << boy_count[boy[i]-1] << " " << "girl_count: " << girl_count[girl[i]-1] << endl;
        comb += pair - (boy_count[boy[i]-1] + girl_count[girl[i]-1] - 1);
        // int j = i +1; 
        // // cout << "boy: " << boy[i] << endl; 
        // while (j <= pair-1){
        //     if (boy[j] != boy[i] && girl[j] != girl[i]){
        //         // cout << "A" << endl; 
        //         comb++; 
        //     }
        //     j++; 
            
        // }
    }
    
    cout <<  comb/2 << endl; 
}

int main()
{
    int n; 
    cin >> n; 
    
    
  
    int pair = 0; 
    for (int i =0; i < n; i++){
        vector<int> girl;
        vector<int> boy;
        // vector<int> boy_count; 
        // vector<int> girl_count; 
       
        int boy_num; 
        int girl_num; 
        // cout << "------------"<< endl; 
        
            
        cin >> boy_num >> girl_num >> pair; 
        vector<int> boy_count(boy_num, 0); 
        vector<int> girl_count(girl_num, 0); 
            
    
        // cout << "pair: " << pair << endl;
        for(int j = 0; j < pair; j++){
            int temp; 
            cin >> temp; 
            boy_count[temp-1]++; 
            boy.push_back(temp);
        }
        
        for(int j =0; j < pair; j++){
            int temp; 
            cin >> temp; 
            girl_count[temp-1]++;
            girl.push_back(temp); 
        }
        
        
        
        select_pair(boy, girl, pair, boy_count, girl_count);
    }
   
   return 0;
}