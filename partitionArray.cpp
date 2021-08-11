
#include <bits/stdc++.h>
using namespace std;

int partition(int arr[],int n){
    
    int curr_max=arr[0];
    int prev_max=arr[0];
    int len=1;
    for(int i=1;i<n;++i){
        curr_max=max(curr_max,arr[i]);
        if(prev_max>arr[i]){
            len=i+1;
            prev_max=curr_max;
            
        }
    }
    return len;
}

int main() {
    // Write C++ code here
    //std::cout << "Hello world!";
    int arr[5]={8,9,10,0,12};
    cout<<partition(arr,5)<<endl;
    
    
    

    return 0;
}