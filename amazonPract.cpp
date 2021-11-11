#include <bits/stdc++.h>
using namespace std;



class EmployeeNode{
    public:
    int val;
    vector <EmployeeNode*> subEmployeeNode;

    EmployeeNode(int tenure){
        this->val=tenure;
    }

};

int postOrder(EmployeeNode* root,double &maxi,map <EmployeeNode*,int> &mp,EmployeeNode* &ans){
    if(root==NULL){
        return 0;

    }

    vector <EmployeeNode* > vec=root->subEmployeeNode;

    int sz=vec.size();
    int sum=0;
    mp[root]=1;
    for(int i=0;i<sz;i++){
       
        sum+=postOrder(vec[i],maxi,mp,ans);
         mp[root]+=mp[vec[i]];
    }
    
    if(mp[root]>1){
        if((double((root->val+sum)*1.0)/mp[root]) > maxi){
          //  cout<<"prev maxi:  "<<maxi<<" curr maxi:  "<<root->val/mp[root]<<endl;
        
            maxi=(double((root->val+sum)*1.0)/mp[root]);
            ans=root;
        }
        //maxi=max(maxi,(double(sum*1.0)/sz));
    }

   

    return root->val+sum;


}

EmployeeNode* getBusiest(EmployeeNode* president){
    if(president==NULL){
        return president;
    }

    double maxi=-1.0;
    EmployeeNode* ans;
    map <EmployeeNode*,int> mp;
    postOrder(president,maxi,mp,ans);

    //  for(auto it=mp.begin();it!=mp.end();it++){
    //     cout<<it->first->val <<"   "<<it->second<<"\n";
    // }

    // cout<<"maxi is:  "<<maxi;

    return ans;

    
}

int main(){

    EmployeeNode* root=new EmployeeNode(20);

    
    EmployeeNode* a=new EmployeeNode(12);
    


    

    EmployeeNode* b=new EmployeeNode(18);



    EmployeeNode* c=new EmployeeNode(11);
    
    EmployeeNode* d=new EmployeeNode(2);
    
    EmployeeNode* e=new EmployeeNode(3);
    
    
    EmployeeNode* f=new EmployeeNode(15);
    
    EmployeeNode* g=new EmployeeNode(8);
    
  
    root->subEmployeeNode={a,b};
    a->subEmployeeNode={c , d,e};
    b->subEmployeeNode={f,g};
    EmployeeNode* ans=getBusiest(root);
  //  cout<<"Ans ::"<<ans<<endl;

    cout<<"Ans is:  "<<ans->val;



    return 0;
}









