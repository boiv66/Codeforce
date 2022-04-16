#include <iostream>
#include <vector>
using namespace std;

int main()
{
    long long n;
    long long d;
    long long current = 1; 
    vector<long long>arr;
    cin >> n;
    cin >> d;
    for(long long i=0; i<n-1;i++) {
        long long tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    
    for (long long i = 0; i < n-1; i++ ){
        if (arr[current - 1] >= 1 && arr[current-1] <= n - current){
            current = current + arr[current-1]; 
            if (current == d){
                cout << "YES"; 
                break;
            }
        }
        else{
            cout << "NO"; 
            break; 
        }
    }
    
    
    
    
}