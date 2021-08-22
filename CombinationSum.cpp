#include <bits/stdc++.h>

using namespace std;

void recCombSum(vector < int > & A, int idx, int n, vector < int > & temp, vector < vector < int >> & ans, int sum, int B) {
    if (idx >= n) {
        return;

    }
    if (sum > B) {
        return;
    }
    if (sum == B) {
        //sort(temp.begin(),temp.end());
        ans.push_back(temp);
        return;
    }

    sum += A[idx];
    temp.push_back(A[idx]);
    recCombSum(A, idx, n, temp, ans, sum, B);
    sum -= A[idx];
    temp.pop_back();

    recCombSum(A, idx + 1, n, temp, ans, sum, B);

}
vector < vector < int > > combinationSum(vector < int > & A, int B) {

    sort(A.begin(), A.end());
    
    A.erase(unique(A.begin(), A.end()), A.end());
    
    vector < vector < int >> ans;
    
    vector < int > temp;
    
    int sum = 0;
    
    int idx = 0;
    
    int n = A.size();
    
    recCombSum(A, idx, n, temp, ans, sum, B);

    return ans;
}

int main() {
//Expected Time Complexity: O(X2 * 2N), where X is average of summation B/arri for every number in the array.
    return 0;
}
