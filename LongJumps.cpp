#include <iostream>
#include <vector>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long d;
    
    vector<vector<long long>>arr;
    vector<long long> arrN; 
    
    

    for(long long i=0; i<n;i++) {
        vector<long long> temp;
        long long tmp; 
        cin >> tmp;
        // cout << "tmp: " << tmp << endl; 
        arrN.push_back(tmp); 
        for(long long j = 0; j < tmp; j++){
            long long a; 
            cin >> a; 
            temp.push_back(a); 
        }
        arr.push_back(temp);
    }
    
        long long maxV = 0; 
        long long score = 0; 
    for (long long i = 0; i < n; i++){
        maxV = 0; 
        // cout << "----------------" << endl; 
        
        for (long long j = arrN[i]-1; j >= 0; j--){
            score = 0;
            score += arr[i][j]; 
            
            if (arr[i][j] + j < arrN[i]){
                
                // cout <<"arr[i][j] + j " << arr[i][j] + j << endl;
                score += arr[i][j+arr[i][j]]; 
            }
            
            arr[i][j] = score;
            
            if (maxV < score){
                maxV = score; 
            }
        
       
        }
        
        
    
        
        
        
        cout << maxV<< endl; 
        
    }
    
    

    return 0; 
}