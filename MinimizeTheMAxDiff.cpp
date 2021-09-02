#include <bits/stdc++.h>
using namespace std;

/*
Given an array arr[] denoting heights of N towers and a positive integer K, you have to modify the height of each tower either by increasing or decreasing them by K only once.
Find out what could be the possible minimum difference of the height of shortest and longest towers after you have modified each tower.
*/

int getMinDiff(int arr[],int n,int k){
    sort(arr,arr+n);
    int maxi=arr[n-1];
    int mini=arr[0];

    int res=maxi-mini;

    for(int i=1;i<n;i++){
        maxi=max(arr[n-1]-k,arr[i-1]+k);
        mini=min(arr[0]+k,arr[i]-k);
        res=min(res,maxi-mini);
    }

    return res;
}

int main(){

    int arr[5]={3,4,12,18,20};
    cout<<getMinDiff(arr,5,3)<<endl;


    return 0;
}