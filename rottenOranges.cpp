#include <bits/stdc++.h>
using namespace std;

class point{
    public:
    int x;
    int y;
    int step;
    point(int x,int y,int step){
        this->x=x;
        this->y=y;
        this->step=step;
    }
};

int minTimeToRottenOranges(vector <vector<int>> mat){
    // 2->rotten
    // 0-> empty
    // 1-> orange

    int row=mat.size();
    int col=mat[0].size();
    int totalOranges=0;
    int rottenI=-1;
    int rottenJ=-1;
    queue <point> q;
    vector <vector <bool>> isInc(row,vector<bool> (false,col));
      
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(mat[i][j]==2){
                
                rottenI=i;
                rottenJ=j;
                 isInc[rottenI][rottenJ]=true;
                point p1(rottenI,rottenJ,0);
                q.push(p1);
                totalOranges++;
            }
            else if(mat[i][j]==1){
                totalOranges++;
            }
        }
    }
    
    int cnt=0;
     point p(rottenI,rottenJ,0);
  
    
    
    int maxi=0;
    while(!q.empty()){
        cnt++;
        int x=q.front().x;
        int y=q.front().y;
        int step=q.front().step;
        q.pop();
        if(x>0){
            if(isInc[x-1][y]==false && mat[x-1][y]==1){
                isInc[x-1][y]=true;
                p.x=(x-1);
                p.y=(y);
                p.step=step+1;
                q.push(p);
            }
            
        }
        if(y>0){
              if(isInc[x][y-1]==false && mat[x][y-1]==1){
                isInc[x][y-1]=true;
                p.x=(x);
                p.y=(y-1);
                p.step=(step+1);
                q.push(p);
            }

        }
        if(x<(row-1)){
            if(isInc[x+1][y]==false && mat[x+1][y]==1){
                isInc[x+1][y]=true;
                p.x=(x+1);
                p.y=y;
                p.step=(step+1);
                q.push(p);
            }
        }
        if(y<(col-1)){
            if(isInc[x][y+1]==false && mat[x][y+1]==1){
                isInc[x][y+1]=true;
                p.x=x;
                p.y=y+1;
                p.step=(step+1);
                q.push(p);
            }
        }
        maxi=max(step,maxi);
    }
    if(cnt==totalOranges){
        return maxi;
    }
    return -1;
}


int main(){
    vector <vector <int> > v(3,vector <int> (3,0));
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
      
      cin>>v[i][j];

        }
    }
    cout<<minTimeToRottenOranges(v)<<endl;


    return 0;
}