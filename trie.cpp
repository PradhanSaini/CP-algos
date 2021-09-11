#include <bits/stdc++.h>

using namespace std;

class trie{
public:
   unordered_map<char,trie*> mp;
   bool isend=0;

};

void fill(string s,trie *node,int ind){
   if(ind==s.size())
   {
      node->isend=1;
      return;
   }
   if(node->mp.find(s[ind])==node->mp.end())
   {
      node->mp[s[ind]]=new trie();
      node=node->mp[s[ind]];
      fill(s,node,ind+1);
      return ;
   }
   node=node->mp[s[ind]];
   fill(s,node,ind+1);

}

bool check(string s,trie* node,int ind)
{
   if(s.size()==ind)
   {
      return node->isend;
   }
   if(node->mp.find(s[ind])!=node->mp.end())
      return check(s,node->mp[s[ind]],ind+1);
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
