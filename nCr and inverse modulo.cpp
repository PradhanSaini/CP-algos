#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N=200002;
int fact[N];
int invfact[N];
int mod=1000000007;


int inv(int base){
   int modified=mod-2;
   int ans=1;
   int p=base;
   for(int i=0;i<31;i++)
      {
            if(modified&(1<<i))
               ans*=p;
            p=(p*p)%mod;
            ans%=mod;
      }
      return ans;
}

void fact_invfact(){
   fact[0]=1;
   for(int i=1;i<=N;i++)
      fact[i]=(fact[i-1]*i)%mod;
   invfact[1]=1;
   invfact[0]=1;
   invfact[N]=inv(fact[N]);
   for(int i=N-1;i>1;i--)
      invfact[i]=((1+i)*invfact[i+1])%mod;
} 

int power(int a,int b){
    if (b == 0)return 1;
    if (b == 1)return a;
    int ret = power(a,b/2);
    if (b%2 == 0)return (ret * ret)%mod;
    return ((ret * ret)%mod * a)%mod;
}

int nCr(int n,int r)
{
   return (((fact[n]*invfact[r])%mod)*invfact[n-r])%mod;
}

void solve(){
       cout<<nCr(15,6);
}

signed main(){
   fact_invfact();
   solve();
}
