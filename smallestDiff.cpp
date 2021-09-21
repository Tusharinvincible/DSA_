#include <bits/stdc++.h>
using namespace std;

int smallestDiff(vector <int> arr1,vector <int> arr2){
    int n1=arr1.size();
    int n2=arr2.size();
    cout<<n1<<"  "<<n2<<endl;

    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());

    int i=0;
    int j=0;
    int ans=INT_MAX;

    while(i<n1 && j<n2){
        if(arr1[i]<=arr2[j]){
            
            ans=min(ans,abs(arr1[i]-arr2[j]));
            i++;

        }
        else{

            ans=min(ans,abs(arr1[i]-arr2[j]));
            j++;
            
        }

        if(ans==0){
            return 0;
        }
    }

    return ans;


    
}

int main(){
vector <int> arr1;
vector <int> arr2;

for(int i=0;i<6;i++){
    int ele;
    cin>>ele;
    arr1.push_back(ele);
}
for(int j=0;j<5;j++){
    int ele;
    cin>>ele;
    arr2.push_back(ele);
}
cout<<smallestDiff(arr1,arr2);
    return 0;
}