#include <bits/stdc++.h>
using namespace std;

void stringPermutation(string s,string ans,map <int,int> &mp){

    if(ans.size()>1 && ans[ans.size()-1]=='B' && ans[ans.size()-2]=='A'){
        return;
    }
    if(ans.size()==s.size()){
        cout<<ans<<endl;
        return;
    }

    for(int i=0;i<s.size();i++){
        if(mp[s[i]]==0){
            ans+=s[i];
            mp[s[i]]=1;
            stringPermutation(s,ans,mp);
            ans.pop_back();
            mp[s[i]]=0;
            
        }
    }

}






int main(){

    string s="ABC";
    string ans="";
    map <int,int> mp;
    stringPermutation(s,ans,mp);



    return 0;
}