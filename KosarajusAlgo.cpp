  void dfsTopoSort(vector <int> adj[],int src,stack <int> &st, vector <bool> &visited){
        visited[src]=true;
        for(int x: adj[src]){
            if(visited[x]==false){
                dfsTopoSort(adj,x,st,visited);
            }
        }
        st.push(src);
    }
    
    void dfs(vector <int> trans[],int sc,vector <int> &temp,vector <bool> &isIncluded){
        isIncluded[sc]=true;
        temp.push_back(sc);
        for(int x: trans[sc]){
            if(isIncluded[x]==false){
                dfs(trans,x,temp,isIncluded);
            }
        }
    }
    vector<vector<int>> tarjans(int V, vector<int> adj[])
    {
        //code here
        vector <int> trans[V];
        for(int i=0;i<V;i++){
            for(int x:adj[i]){
                trans[x].push_back(i);
                
            }
        }
        vector <bool> visited(V,false);
        
        stack <int> st;
        for(int i=0;i<V;i++){
            if(visited[i]==false){
                 dfsTopoSort(adj,i,st,visited);
            }
        }
       
        
        vector <vector <int> > ans;
        vector <bool> isIncluded(V,false);
        while(!st.empty()){
            int sc=st.top();
          
            vector <int> temp;
            if(isIncluded[sc]==false){
                dfs(trans,sc,temp,isIncluded);
                if(temp.size()==1){
                    ans.push_back(temp);
                }else{
                sort(temp.begin(),temp.end());
                ans.push_back(temp);
                }
            }
              st.pop();
            
            
        }
        sort(ans.begin(),ans.end());
        
        return ans;
        
        
        
    }
