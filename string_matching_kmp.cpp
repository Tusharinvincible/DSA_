#include <bits/stdc++.h>
using namespace std;


        void calcLps(vector <int> &lps,string pat){
            int len=0;
            lps[0]=0;
            int n=pat.size();
            int i=1;
            
            while(i<n){
                if(pat[len]==pat[i]){
                    len++;
                    lps[i]=len;
                    i++;
                }
                else{
                    if(len!=0){
                        len=lps[len-1];
                    }
                    else{
                        lps[i]=0;
                        i++;
                    }
                }
            }
        }
        vector <int> search(string pat, string txt)
        {   
            int m=pat.size();
            int n=txt.size();
            vector <int> lps(m,0);
            calcLps(lps,pat);
            
            int i=0;
            int j=0;
            vector <int> ans;
            while(i<n){
                if(pat[j]==txt[i]){
                    i++;
                    j++;
                }
                
                if(j==m){
                    ans.push_back(i-j+1);
                    j=lps[j-1];
                }
                else if(i<n && pat[j]!=txt[i]){
                    if(j!=0){
                        j=lps[j-1];
                    }
                    else{
                        i++;
                    }
                }
            }
            
            return ans;
            
        }