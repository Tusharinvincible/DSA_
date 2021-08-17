#include <bits/stdc++.h>
using namespace std;

int merge(int arr[],int s,int m,int e){

    int ans=0;
    int j=m+1;
    for(int i=s;i<=m;i++){

        while(j<=e && arr[i]>(2*arr[j])){
            j++;
        }
        ans+=j-(m+1);


    }

    vector <int> v;

    int i=s;
    j=m+1;
    while(i<=m && j<=e){
        if(arr[i]<=arr[j]){
            v.push_back(arr[i]);
            i++;
        }else{
            v.push_back(arr[j]);
            j++;
        }
    }
    while(i<=m){
        v.push_back(arr[i]);
        i++;
    }
    while(j<=e){
        v.push_back(arr[j]);
        j++;
    }

    i=s;
    j=m+1;
    int k=0;

    while(i<=m){
        arr[i]=v[k];
        k++;
        i++;

    }
    while(j<=e){
        arr[j]=v[k];
        k++;
        j++;
    }


    return ans;


    
}


int mergeSort(int arr[],int s,int e){
    int ans=0;
    if(s<e){
        int mid=(s+e)/2;
        ans+=mergeSort(arr,s,mid);
        ans+=mergeSort(arr,mid+1,e);
        ans+=merge(arr,s,mid,e);
        return ans;
    }
    return ans;
}










int main(){
    int arr[5]={2,4,3,5,1};
    int i=0;
    int j=4;
    cout<<mergeSort(arr,i,j)<<endl;

}






 