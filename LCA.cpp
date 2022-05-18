#include <bits/stdc++.h> 
using namespace std;
#define int long long
int mod=998244353 ;

void process(vector<int> &T, vector<vector<int>> &P) {
   int i, j;
   int N=T.size();
   for (i = 0; i < N; i++)
     P[i][0] = T[i];

   for (j = 1; 1 << j < N; j++)
     for (i = 0; i < N; i++)
       if (P[i][j - 1] != -1)
         P[i][j] = P[P[i][j - 1]][j - 1];
 }

void dfs(int node,vector<vector<int>> &G,vector<int> &T,vector<int> &L,int level,int par=-1){
    
    L[node]=level;

    for(int i=0;i<G[node].size();i++){
        int ch=G[node][i];
        if(ch==par)continue;
        T[ch]=node;
        dfs(ch,G,T,L,sum,totsum,level+1,s,node);
    }
}

int query(vector<vector<int>> &P, vector<int> &T,vector<int> &L, int p, int q) {
  int tmp, log, i;
  int N=P.size();
  //if p is situated on a higher level than q then we swap them
  if (L[p] < L[q])
    tmp = p, p = q, q = tmp;

  //we compute the value of [log(L[p)]
  for (log = 1; 1 << log <= L[p]; log++);
  log--;

  //we find the ancestor of node p situated on the same level
  //with q using the values in P
  for (i = log; i >= 0; i--)
    if (L[p] - (1 << i) >= L[q])
      p = P[p][i];

  if (p == q)
    return p;

  //we compute LCA(p, q) using the values in P
  for (i = log; i >= 0; i--)
    if (P[p][i] != -1 && P[p][i] != P[q][i])
      p = P[p][i], q = P[q][i];

  return T[p];
}


void solve(){
    int n;
    cin>>n;
    vector<vector<int>> G(n+1);
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }


    vector<int> T(n+1),L(n+1);
    vector<vector<int>> P(n+1,vector<int>(26,-1));
    dfs(1,G,T,L,0);
  
    process(T,P);

    int q;
    cin>>q;
    
    for(int i=0;i<q;i++){
        int u,v;
        cin>>u>>v;
        int lca=query(P,T,L,u,v);
    }
}
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    // fact_invfact();
    // t=1;
    // pre();
    while(t--)
        solve();
}
