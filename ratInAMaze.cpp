 #include <bits/stdc++.h>

 using namespace std;
 bool isPossible(int i, int j, vector < vector < int >> & m, int n, vector < vector < bool >> & isIncluded) {
     if (i < n && i >= 0 && j >= 0 && j < n && m[i][j] == 1 && isIncluded[i][j] == false) {
         return true;
     }
     return false;
 }
 void recPath(vector < vector < int >> & m, int i, int j, int n, vector < string > & ans, string & st, vector < vector < bool >> & isIncluded) {
     if (i == n - 1 && j == n - 1) {
         ans.push_back(st);
         return;
     }
     if (isPossible(i + 1, j, m, n, isIncluded)) {
         st += 'D';
         isIncluded[i + 1][j] = true;
         recPath(m, i + 1, j, n, ans, st, isIncluded);
         st.pop_back();
         isIncluded[i + 1][j] = false;

     }
     if (isPossible(i, j - 1, m, n, isIncluded)) {
         st += 'L';
         isIncluded[i][j - 1] = true;
         recPath(m, i, j - 1, n, ans, st, isIncluded);
         st.pop_back();
         isIncluded[i][j - 1] = false;
     }
     if (isPossible(i, j + 1, m, n, isIncluded)) {
         st += 'R';
         isIncluded[i][j + 1] = true;
         recPath(m, i, j + 1, n, ans, st, isIncluded);
         st.pop_back();
         isIncluded[i][j + 1] = false;
     }
     if (isPossible(i - 1, j, m, n, isIncluded)) {
         st += 'U';
         isIncluded[i - 1][j] = true;
         recPath(m, i - 1, j, n, ans, st, isIncluded);
         st.pop_back();
         isIncluded[i - 1][j] = false;
     }

     return;
 }
 vector < string > findPath(vector < vector < int >> & m, int n) {
     // Your code goes here
     int i = 0;
     int j = 0;
     vector < string > ans;
     string st = "";
     vector < vector < bool >> isIncluded(n, vector < bool > (n, false));
     if (m[0][0] == 1) {
         isIncluded[0][0] = true;
         recPath(m, i, j, n, ans, st, isIncluded);
     }
     return ans;

 }
