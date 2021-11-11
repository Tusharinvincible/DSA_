#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <bits/stdc++.h>


using namespace std;


void dfs2(int src,vector <int> adj[],vector <bool> &vis,map <char,int>  &mp,int& ans,string s){
    mp[s[src-1]]++;
    ans=max(ans,mp[s[src-1]]);
    for(int x: adj[src]){
        if(vis[x]==false){
            dfs(x,adj,vis,mp,ans,s);
        }
    }
}

void dfs(int src,vector <int> adj[],vector <bool> &vis,stack <int> &s){
    vis[src]=true;

    for(int x: adj[src]){
        if(vis[x]==false){
            dfs(x,adj,vis,s);
        }
    }
    s.push(src);
}


int beautifulPath(){
    int n;
    int m;
    cin>>n>>m;
    string s;
    cin>>s;
    int a1[m];
    int a2[m];
    vector <int> adj[n+1];
    vector <int> trans[n+1];

    for(int i=0;i<m;i++){
        cin>>a1[i];


    }

    for(int i=0;i<m;i++){
        cin>>a2[i];
    }

    for(int i=0;i<m;i++){
        adj[a1[i]].push_back(a2[i]);
        trans[a2[i]].push_back(a1[i]);

    }
    stack <int> st;
    vector <bool> vis(n+1,false);
    for(int i=1;i<=n;i++){
        if(vis[i]==false){
            dfs(i,adj,vis,st);
        }
    }
    vector <bool> vis1(n+1,false);
     int ans=INT_MAX;
    while(!st.empty()){
        int src=st.top();
        st.pop();

        if(vis1[src]==false){
            map <char,int> mp;
           
            dfs2(src,trans,vis1,mp,ans,s);
        }
    }
    if(ans==INT_MAX){
        return -1;
    }
    return ans;
    
}








int main(){

    return 0;
}