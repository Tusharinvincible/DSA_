// N Rectangular Blocks
// On the occasion of Diwali, Ninja received a game as gift from his father containing N rectangular blocks. The task of the game is to make the heights of these blocks in non increasing order without changing the given order of blocks provided you can rotate these blocks clockwise, i.e. width will become height and vice versa.
// Note: You can rotate any number of blocks or no blocks at all and you can't change the order of blocks
// Input Format:
// First line contains a single integer N - number of rectangular blocks. Next N lines contains two integers hi and wi denoting height and width of ith rectangular block
// Output Format:
// You have to print YES if height of blocks can be made in non decreasing order otherwise NO
// Constraints:
// 1 ≤ N ≤ 10^5 
// 1 ≤ hi, wi ≤ 10^9
// Sample Input 1
// 3  
// 2 4  
// 4 5  
// 3 6
// Sample Output 1
// YES
// Explanation
// Rotating first block will give us required non increasing order of height 
// Sample Input 2
// 4  
// 10 10  
// 8 8  
// 8 15  
// 9 9
// Sample Output 2
// NO
// Explanation
// Rotating any block won't lead us to the required order

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector <vector <int> > vec(n,vector <int> (2));

    for(int i=0;i<n;i++){
        cin>>vec[i][0]>>vec[i][1];
    }

    bool ans=true;

    for(int i=0;i<(n-1);i++){
        if(max(vec[i][0],vec[i][1])<min(vec[i+1][0],vec[i+1][1])){
            ans=false;
            break;
        }
    }

    if(ans){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}