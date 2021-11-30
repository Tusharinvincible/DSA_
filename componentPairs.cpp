#include <bits/stdc++.h>
using namespace std;
/*

Pccoe organised a dance competition in which any student from any branch or division can participate.But there are some rules to it.

Rules

1.The team can contain only two members.

2.The 2 dancers cannot be from the same division but can be from same branch.

It was difficult for the students to form a team so they requested Might Guy for help. He tried his best and just was able to form pairs of students from same division.

N denotes the number of dancers(0,2...,N)

M denotes number of pairs Guy was able to form.

N=7 M=3

0 2

2 3

4 5

The total number of students were 6 numbered (0,1,2,3,4,5,6) Pair formed by Guy (0,2) (2,3) (4,5)

Dancers numbered [0,2,3] belong to same division and those numbered [4,5] belong to other same division and the dancers numbered 1 and 6 belong to 2 different divisions as they are not in the pairs.

Guy is also alot confused he requires your help. You are given the above input.You have to find the maximum number of valid pairs.

Input Format

The first line contains integers N and M denoting number of dancers and number of pairs respectively.
The next M line contains pair of students from same division.
Constraints

1<=N<=10^5

1<=M<=10^3

Output Format

Calculate the total number of valid pairs which can be formed.

Sample Input 0

5 2
0 1
2 4
Sample Output 0

8
Explanation 0

Dancers numbered [0,1] belong to same division and those numbered [2,4] belong to same division and the dancer numbered 3 belong to an another different division.

So the valid pairs which can be formed are (0,2),(0,4),(0,3),(1,2),(1,4),(1,3),(2,3),(4,3).

Note:The valid pairs are formed on the basis of the above rules.

So total number of pairs are 8.



*/



int dfs(int src,vector <int> adj[],vector <bool> &vis){
    vis[src]=true;
    int ct=1;
    for(int x: adj[src]){
        if(vis[x]==false){
            ct+=dfs(x,adj,vis);
        }
    }
    return ct;
}

int main() {
    int n,m;
    cin>>n>>m;
    
    vector <int> adj[n];
    
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    vector <bool> vis(n,false);
    vector <int> ans;
    for(int i=0;i<n;i++){
        if(vis[i]==false){
            int ct=dfs(i,adj,vis);
            ans.push_back(ct);
        }
    }
    long long pairs=0;
    int z=ans.size();
    for(int i=0;i<z;i++){
        pairs+=(ans[i]*(n-ans[i]));
        n=n-ans[i];
    }
    cout<<pairs<<endl;
    
    return 0;
}