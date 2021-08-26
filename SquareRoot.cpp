#include <bits/stdc++.h>
using namespace std;



bool isPerfectSquare(int num){
    int s=0;
    int e=num;

    while(s<=e){
        int mid=(s+e)/2;
        if(mid*mid==num){
            return true;
        }
        else if((mid*mid)<num){
            s=mid+1;
        }else{
            e=mid-1;
        }
    }
    return false;
}






int main(){

    int num;
    cin>>num;
    if(isPerfectSquare(num)){
        cout<<"Given Num is Perfect Square: "<<endl;
    }
    else{
        cout<<"Given Num is Not A Perfect Square:  "<<endl;
    }
}