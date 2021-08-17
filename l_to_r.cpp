#include <bits/stdc++.h>
using namespace  std;

int leftBS(int arr[],int n,int ele){
    int s=0;
    int e=n-1;
    while(s<=e){
        int m=(s+e)/2;
        if(arr[m]>=ele){
            e=m-1;
        }
        else{
            s=m+1;
        }
    }
    return s;
}
int rightBS(int arr[],int n,int ele){
    int s=0;
    int e=n-1;
    while(s<=e){
        int m=(s+e)/2;
        if(arr[m]<=ele){
            s=m+1;
        }
        else{
            e=m-1;

        }
    }
    return e;
}

int main(){
    int arr[10]={1,1,2,2,3,4,5,6,7,10};
    int l=leftBS(arr,10,0);
    int r=rightBS(arr,10,10);
    cout<<r-l+1<<endl;



    return 0;
}
