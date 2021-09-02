#include <bits/stdc++.h>
using namespace std;

//Given a number N, the task is find the number of ways to represent this number as a sum of 2 or more consecutive natural numbers.

int getCount(int N){
    int max_len=0;

    int sum=0;
    while(sum<N){
        max_len++;
        sum+=max_len;
    }
    int ans=0;

    for(int i=1;i<=max_len;i++){
        double a=(N*1.0 -(i*(i+1)/2))/(i+1);

        if(a>0 && a==int(a)){
            ans++;
        }
    }
    return ans;
}


int main(){
    cout<<getCount(21)<<endl;

    return 0;
}