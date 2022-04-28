#include <bits/stdc++.h>

using namespace std;

string modified(string s)
{
   string ans;
   ans=s[0];
   for(int i=1;i<s.size();i++)
      {
         ans+='#';
         ans+=s[i];
      }
   return ans;
}

vector<int> manachar(string s){
        int n=s.size();
        vector<int> d1(n);

        for(int i=0,l=0,r=-1;i<n;i++)
        {
            if(i<=r)
                d1[i]=min(d1[l+r-i],r-i+1);
            else d1[i]=1;
            int k=d1[i];
            while(i-k>=0 and i+k<n and s[i-k]==s[i+k])
            {
               d1[i]++;
               k++;
            }
            
            if(i+k>r)
            {
                r=i+k-1;
                l=i-k+1;
            }
        }
   return d1;     
}

// aaaabb
//v1= 1 2 2 1 1 1  on element
//v2= 1 2 1 0 1    between element

void  manacharAlgo(string s)
{
   int n=s.size();
   vector<int> v1=manachar(s);
   string mod=modified(s);
   vector<int> v22=manachar(mod);

   vector<int> v2;
   for(int i=0;i<v22.size();i++)
      if(mod[i]=='#')
         v2.push_back(v22[i]/2);

}

int main(){
   string s;
   while(cin>>s)
   manacharALgo(s);
   return 0;
}
