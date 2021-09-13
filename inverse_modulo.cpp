#include <bits/stdc++.h>
using namespace std;
#define int long long

int fact[100005];
int invfact[100005];
int mod=1000000007;
int n=100000;

int inv(int base){
   int modified=mod-2;
   int ans=1;
   int p=base;
   for(int i=0;i<31;i++)
      {
            if(modified&(i<<i))
               ans*=p;
            p=(p*p)%mod;
            ans%=mod;
      }
      return ans;
}


void fact_invfact(){
   fact[0]=1;
   for(int i=1;i<=100005;i++)
      fact[i]=(fact[i-1]*i)%mod;
   invfact[1]=1;
   invfact[0]=1;
   invfact[n]=inv(fact[n]);
   for(int i=n-1;i>1;i--)
      invfact[i]=((1+i)*invfact[i+1])%mod;
} 



signed main(){
   fact_invfact();
}
