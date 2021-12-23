/*

Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.


*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
//     bool check(int i,int j,int m,int n,vector<vector<char>>& board){
//         int tempx=i-1;
//         bool c1=false;
//         bool c2=false;
//         bool c3=false;
//         bool c4=false;
//         while(tempx>=0){
//             if(board[tempx][j]=='X'){
//                 c1=true;
//                 break;
//             }
//             tempx--;
//         }
//         tempx=i+1;
        
//         while(tempx<m){
//             if(board[tempx][j]=='X'){
//                 c2=true;
//                 break;
//             }
//             tempx++;
//         }
        
//         int tempj=j-1;
//         while(tempj>=0){
//             if(board[i][tempj]=='X'){
//                 c3=true;
//                 break;
//             }
//             tempj--;
//         }
//         tempj=j+1;
        
//         while(tempj<n){
//              if(board[i][tempj]=='X'){
//                 c4=true;
//                 break;
//             }
//             tempj++;
            
//         }
        
//         return c1&&c2&&c3&&c4;
//     }
    
//     [["O","X","X","O","X"]
//      ["X","O","O","X","O"],
//      ["X","O","X","O","X"],
//      ["O","X","O","O","O"],
//      ["X","X","O","X","O"]]
    
    
    
    
    
//     [["O","X","X","O","X"],
//     ["X","X","X","X","O"],
//     ["X","X","X","X","X"],
//     ["O","X","O","O","O"],
//     ["X","X","O","X","O"]]
    
    
    
    
    bool isPossible(int i,int j,int m,int n,vector<vector<char>>& board){
        if(i>=0 && j>=0 && i<m && j<n && board[i][j]=='O'){
            return true;
        }
        return false;
    }
        
        
        
    int x[4]={0,0,1,-1};
    int y[4]={1,-1,0,0};
    void dfs(int i,int j,int m,int n,vector<vector<char>>& board){
        board[i][j]='Y';
        for(int k=0;k<4;k++){
            int newi=i+x[k];
            int newj=j+y[k];
            if(isPossible(newi,newj,m,n,board)){
                dfs(newi,newj,m,n,board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++){
           if(board[i][0]=='O'){
               dfs(i,0,m,n,board);
           }
            if(board[i][n-1]=='O'){
                dfs(i,n-1,m,n,board);
            }
        }
        
        for(int i=0;i<n;i++){
            if(board[0][i]=='O'){
                dfs(0,i,m,n,board);
            }
            if(board[m-1][i]=='O'){
                dfs(m-1,i,m,n,board);
            }
        }
        
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
            
        }
         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='Y'){
                    board[i][j]='O';
                }
            }
            
        }
        
        
    }
};