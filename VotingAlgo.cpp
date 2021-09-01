#include <bits/stdc++.h>
using namespace std;

int majorityElement(int arr[],int n){
    int major=arr[0];
    int count=1;
    for(int i=1;i<n;i++){
       
        if(major==arr[i]){

            count+=1;
        }
        else{
            count--;
        }
         if(count==0){
            major=arr[i];
            count=1;
        }
    }

    int ct=0;
    for(int i=0;i<n;i++){
        if(major==arr[i]){
            ct++;
        }
    }
    if(ct>(n/2)){
        return major;
    }
    return -1;
}

int main(){

    int arr[4]={1,2,1,1};
    cout<<majorityElement(arr,4);
    return 0;
}