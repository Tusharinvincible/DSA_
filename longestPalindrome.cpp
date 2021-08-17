#include <bits/stdc++.h>

using namespace std;

string isPalindrome(int i, int j, string s) {
  int ct = 0;
  string s1 = "";
  string s2 = "";
  int n = s.size();
  if (i == j) {
    s2 += s[j];
    ct++;
    i--;
    j++;

  }
  while (i >= 0 && j < n && s[i] == s[j]) {
    s1 += s[i];
    s2 += s[j];

    ct += 2;
    i--;
    j++;
  }
  reverse(s1.begin(), s1.end());
  return s1 + s2;
}
string longestPalindrome(string s) {
  int len = -1;
  int n = s.size();
  string ans = "";
  string ans1 = "";
  string ans2 = "";
  int k = 0;
  for (int i = 0; i < n; i++) {
    ans1 = isPalindrome(i, i, s);
    //cout<<ans1<<endl;
    k = ans1.size();
    if (k > len) {
      ans = ans1;
      len = k;
    }

    if (i < (n - 1)) {
      ans2 = isPalindrome(i, i + 1, s);
      //cout<<ans2<<endl;
      k = ans2.size();
      if (k > len) {
        ans = ans2;
        len = k;
      }
    }
  }

  //cout<<ans<<endl;
  return ans;

}
int main() {
  string s = "babad";
  cout << longestPalindrome(s) << endl;
}