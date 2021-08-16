#include <bits/stdc++.h>
using namespace std;
class point{
    public:
    int i;
    int j;
    int step;
    point(int _i,int _j,int _step){
        i=_i;
        j=_j;
        step=_step;
    }
};

bool isPossible(int i,int j,int row,int col,vector <vector <bool>> &isIncluded,vector <vector<int> > &grid){
    if(i>=0 && i<row && j>=0 && j<col && isIncluded[i][j]==false && grid[i][j]==1){
        return true;
    }

    return false;
}

int rottenOranges(vector <vector<int> > &grid){
    int row=grid.size();
    int col=grid[0].size();
    queue <point> q;
    int totalOranges=0;
    vector <vector <bool>> isIncluded(row,vector <bool> (false,col));
    for(int i=0;i<row;i++){

        for(int j=0;j<col;j++){

            if(grid[i][j]==2){
                isIncluded[i][j]=true;

                 point p(i,j,0);

                 q.push(p);
                 totalOranges++;
            }
            else if(grid[i][j]==1){
                totalOranges++;

            }
        }

    }
    cout<<"Total Oranges: "<<totalOranges<<endl;
    int k=0;
    int maxi=0;
    while(!q.empty()){
       
            k++;
            point temp=q.front();
            int tempX=temp.i;
            int tempY=temp.j;
            int tempStep=temp.step;
           

            if(isPossible(tempX-1,tempY,row,col,isIncluded,grid)){
            
                point p1(tempX-1,tempY,tempStep+1);
                isIncluded[tempX-1][tempY]=true;
                q.push(p1);
            }
              if(isPossible(tempX,tempY-1,row,col,isIncluded,grid)){
            
                point p1(tempX,tempY-1,tempStep+1);
                isIncluded[tempX][tempY-1]=true;
                q.push(p1);
            }
              if(isPossible(tempX+1,tempY,row,col,isIncluded,grid)){
            
                point p1(tempX+1,tempY,tempStep+1);
                isIncluded[tempX+1][tempY]=true;
                q.push(p1);
            }
              if(isPossible(tempX,tempY+1,row,col,isIncluded,grid)){
            
                point p1(tempX,tempY+1,tempStep+1);
                isIncluded[tempX][tempY+1]=true;
                q.push(p1);
            }
           
         q.pop();
        maxi=max(maxi,tempStep);
        
        
    }
    cout<<"Total Oranges After:  "<<k<<endl;
    if(k==totalOranges)
        return maxi;
    return -1;
    
   


}









int main(){
    int row,col;
    cout<<"Enter row and column: ";
    cin>>row>>col;
    vector <vector <int> > grid(row,vector <int> (col,0));

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>grid[i][j];
        }
    }
    cout<<rottenOranges(grid)<<endl;





    return 0;
}