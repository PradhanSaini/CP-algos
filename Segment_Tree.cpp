#include <bits/stdc++.h> 
using namespace std;
#define int long long

int qtype(int a,int b){
    return a+b;
}

int store(int a[],int ind){
    return a[ind];
}


void build(int t[], int v, int tl, int tr,int a[]) {
    if (tl == tr) {
        t[v] = store(a,tl);
    } else {
        int tm = (tl + tr) / 2;
        build(t, v*2, tl, tm,a);
        build(t, v*2+1, tm+1, tr,a);
        t[v] = qtype(t[v*2],t[v*2+1]);
    }
}

int Q(int t[],int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return qtype(Q(t,v*2, tl, tm, l, min(r, tm))
           , Q(t,v*2+1, tm+1, tr, max(l, tm+1), r));
}

void update(int t[],int v, int tl, int tr, int pos, int new_val,int a[]) {
    if (tl == tr) {
        a[tl]=new_val;
        t[v] = store(a,tl);
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(t,v*2, tl, tm, pos, new_val,a);
        else
            update(t,v*2+1, tm+1, tr, pos, new_val,a);
        t[v] = qtype(t[v*2] , t[v*2+1]);
    }
}

void solve(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int seg[4*n]={0};
    build(seg,1,0,n-1,a);

    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        int qq;
        cin>>qq;
        if(qq==1){
            int ind,val;
            cin>>ind>>val;
            //ind 0-indexed
            update(seg,1,0,n-1,ind,val,a);
        }
        else{
            int l,r;
            cin>>l>>r;
            // l and r 0-indexed
            cout<<Q(seg,1,0,n-1,l,r)<<endl;
        }

    }

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    // cin>>t;
    t=1;
    while(t--)
        solve();
    // cout<<sqrt(28899);
}
