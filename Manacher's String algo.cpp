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
   cout<<endl<<ans<<endl;
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

            while(i-d1[i]>=0 and i+d1[i]<n and s[i-d1[i]]==s[i+d1[i]])
            d1[i]++;
            
            if(i+d1[i]>r)
            {
                r=i+d1[i]-1;
                l=i-d1[i]+1;
            }
        }
   return d1;     
}

void  fun(string s)
{
   vector<int> v1=manachar(s);
   string mod=modified(s);
   vector<int> v2=manachar(mod);
   for(int i=0;i<v1.size();i++)
      cout<<v1[i]<<" ";
   cout<<endl;
   for(int i=0;i<v2.size();i++)
      if(mod[i]=='#')
            cout<<v2[i]/2<<" ";




        
}

int main(){
   string s;
   while(cin>>s)
   fun(s);
   return 0;
}
