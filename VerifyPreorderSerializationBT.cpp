#include <bits/stdc++.h>
using namespace std;

bool isValidSerialization(string preorder){
    int n=preorder.size();

    if(preorder[0]=='#' && n==1){
        return true;
    }
    if(preorder[0]=='#' && n>1){
        return false;

    }
    int nullPointer=2;
    bool isChar=false;
    for(int i=1;i<n;i++){
        if(nullPointer==0){
            return false;
        }
        if(preorder[i]!='#'){
            if(isChar==false){
                isChar=true;
                nullPointer++;
            }
           
        }
        else{
            nullPointer--;
            isChar=false;
        }
    }
    if(nullPointer==0){
        return true;
    }
    return false;

}


int main(){

    string preorder="9#98##";
    cout<<isValidSerialization(preorder)<<endl;



    return 0;
}