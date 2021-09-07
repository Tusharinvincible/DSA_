// // Given an array A containing 2*N+2 positive numbers, out of which 2*N numbers
// exist in pairs whereas the o
// ther two number occur exactly once and are distinct. Find the other two numbers.
#include <bits/stdc++.h>

using namespace std;

vector < int > singleNumber(vector < int > nums) {
    
    int ans = 0;
    for (int i = 0; i < nums.size(); i++) {
        ans = ans ^ nums[i];
    }

    int rsb = ans & -ans;
    int ans1 = 0;
    int ans2 = 0;
    for (int i = 0; i < nums.size(); i++) {
        if ((nums[i] & rsb) == 0) {
            ans1 = ans1 ^ nums[i];
        } else {
            ans2 = ans2 ^ nums[i];
        }
    }

    vector < int > v;
    v.push_back(ans1);
    v.push_back(ans2);
    sort(v.begin(), v.end());

    return v;
}

int main() {

    return 0;

}