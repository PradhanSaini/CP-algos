#include <bits/stdc++.h>

using namespace std;

class trie{
public:
   unordered_map<char,trie*> node;
   bool isend=0;

};

void fill(string s,trie *root,int ind){
   if(ind==s.size())
   {
      root->isend=1;
      return;
   }
   if(root->node.find(s[ind])==root->node.end())
   {
      root->node[s[ind]]=new trie();
      root=root->node[s[ind]];
      fill(s,root,ind+1);
      return ;
   }
   root=root->node[s[ind]];
   fill(s,root,ind+1);

}

bool check(string s,trie* root,int ind)
{
   if(s.size()==ind)
   {
      return root->isend;
   }
   if(root->node.find(s[ind])!=root->node.end())
      return check(s,root->node[s[ind]],ind+1);
   return 0;
}

int main(){
   trie * root=new trie();

   int n;
   cin>>n;

   for(int i=0;i<n;i++)
   {
      string s;
      cin>>s;
      fill(s,root,0);
   }

   int q;
   cin>>q;

   for(int i=0;i<q;i++)
   {
      string s;
      cin>>s;
      cout<<check(s,root,0)<<endl;
   }
}
