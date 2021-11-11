#include <bits/stdc++.h>

using namespace std;


bool isPossible(vector <string> mat,int i,int j,vector <vector <bool>> &vis,char c){
    
    if(i>=0 && i<mat.size() && j>=0 && j<mat[0].size() && mat[i][j]==c && vis[i][j]==false){
        return true;
    }
    return false;
}
int dfs(vector <string> mat,vector <vector <bool>> &vis,int x,int y,char c){

    vis[x][y]=true;

    int x_[8]={0,0,1,-1,1,1,-1,-1};
    int y_[8]={1,-1,0,0,1,-1,1,-1};
    int ans=1;
    for(int i=0;i<8;i++){
        if(isPossible(mat,x+x_[i],y+y_[i],vis,c)){

            ans+=dfs(mat,vis,x+x_[i],y+y_[i],c);
        }
    }

    return ans;

}

vector <int> maxAndMin(vector <string> mat){
    int n=mat.size();
    int m=mat[0].size();
    int maxiB=INT_MIN;
    int miniB=INT_MAX;
    int maxiR=INT_MIN;
    int miniR=INT_MAX;

    vector <vector <bool> > vis(n,vector <bool>(m,false));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j]==false && mat[i][j]=='B'){
                    
                    int ct1=dfs(mat,vis,i,j,'B');
                    cout<<"Blue :"<<ct1<<"  ";
                    maxiB=max(maxiB,ct1);
                    miniB=min(miniB,ct1);
            }
            else if(vis[i][j]==false && mat[i][j]=='R'){

                int ct=dfs(mat,vis,i,j,'R');
                cout<<"RED:  "<<ct<<"  ";
                maxiR=max(maxiR,ct);
                miniR=min(miniR,ct);
            }
        }
    }
    vector <int> ans;
    ans.push_back(max(maxiR,maxiB));
    ans.push_back(min(miniR,miniB));
    return ans;
}



int main(){
    string s1="RBBBRRR";
    string s2="RRBBRBR";
    vector <string> mat;
    mat.push_back(s1);
     mat.push_back(s2);
     vector <int> ans=maxAndMin(mat);

     cout<<ans[0]<<"  "<<ans[1]<<endl;

return 0;
}