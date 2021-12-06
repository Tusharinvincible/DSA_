/*

You are given 'N' jobs with their start time 'Start', end time 'End' and profit 'Profit'. You need to tell the maximum profit you can obtain by performing these jobs such that no two jobs overlap.
*/


#include <bits/stdc++.h>
using namespace std;
class job{
    public:
    int s;
    int e;
    int p;
};

bool cmp(job j1,job j2){
    if(j1.e<j2.e){
        return true;
    }
    else{
        if(j1.e==j2.e){
            return j1.s<j2.s;
        }
        return false;
    }
}

int bs(job arr[],int index){
    int idx=index;
    int low=0;
    int high=index-1;
    
    while(low<=high){
        int mid=(low+high)>>1;
        
        if(arr[mid].e<=arr[idx].s){
            if(arr[mid+1].e<=arr[idx].s){
                low=mid+1;
            }
            else{
                return mid;
            }
        }
        else{
            high=mid-1;
        }
    }
    
    return -1;
}
long long int findMaxProfit(vector<int> &start, vector<int> &end, vector<int> &profit)
{
    int N=start.size();
    job arr[N];
    
    for(int i=0;i<N;i++){
        arr[i].s=start[i];
        arr[i].e=end[i];
        arr[i].p=profit[i];
    }
    
    sort(arr,arr+N,cmp);
    
    vector <long long int > prof(N);
    prof[0]=arr[0].p;
    
    for(int i=1;i<N;i++){
        long long int  isInclude=arr[i].p;
        
        int idx=bs(arr,i);
        if(idx!=-1){
            isInclude+=prof[idx];
        }
        
        prof[i]=max(prof[i-1],isInclude);
    }
    
    return prof[N-1];
}
