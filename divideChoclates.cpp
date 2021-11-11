#include <bits/stdc++.h>
using namespace std;


bool isPossible(vector<int> &arr, int k,int targ){
    int sum=0;
    int ct=0;
    int i=0;
    while(i<arr.size()){
        sum=0;
        while(i<arr.size() && sum<=targ){
            sum+=arr[i];
            if(sum<=targ)
            	i++;
            
        }
        i++;
        if(sum>targ)
        	ct++;
        
    }
    if(ct>k){
        return true;
    }
    return false;
}


int getMaximumSweetness(vector<int> &arr, int k)
{
    int high=0;
    int low=1;
    if(k>=arr.size()){
        return 0;
    }
    for(int x: arr){
        high+=x;
    }
    
    while(low<=high){
        int mid=(low+(high-low)/2);
        if(isPossible(arr,k,mid)){
           // cout<<"Low:  "<<low<<endl;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
  //  cout<<"low:  "<<endl;
    return low;
}
