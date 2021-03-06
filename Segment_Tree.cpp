#include <bits/stdc++.h> 
using namespace std;
#define int long long


void line(){
    cout<<"--------------"<<endl;
}

int qtype1(int a,int b){
    return __gcd(a,b);
}

int qtype2(int a,int b){
    return a+b;
}


void build(int seg[], int seg_ind, int arr_l, int arr_r,int arr[]) {
    if (arr_l == arr_r) {
        seg[seg_ind] = arr[arr_l];
    } else {
        int tm = (arr_l + arr_r) / 2;
        build(seg, seg_ind*2, arr_l, tm,arr);
        build(seg, seg_ind*2+1, tm+1, arr_r,arr);
        seg[seg_ind] = qtype1(seg[seg_ind*2],seg[seg_ind*2+1]);
    }
}

int Q(int seg[],int seg_ind, int arr_l, int arr_r, int l, int r) {
    // cout<<"---->"<<l<<" "<<r<<endl;
    if (l > r) 
        return 0;
    if (l == arr_l && r == arr_r) {
        return seg[seg_ind];

    }
    int arr_m = (arr_l + arr_r) / 2;
    return qtype2(Q(seg,seg_ind*2, arr_l, arr_m, l, min(r, arr_m))
           , Q(seg,seg_ind*2+1, arr_m+1, arr_r, max(l, arr_m+1), r));
}

void update(int seg[],int seg_ind, int arr_l, int arr_r, int pos, int new_val,int arr[]) {
    if (arr_l == arr_r) {
        arr[arr_l]=new_val;
        seg[seg_ind] = arr[arr_l];
    } else {
        int arr_m = (arr_l + arr_r) / 2;
        if (pos <= arr_m)
            update(seg,seg_ind*2, arr_l, arr_m, pos, new_val,arr);
        else
            update(seg,seg_ind*2+1, arr_m+1, arr_r, pos, new_val,arr);
        seg[seg_ind] = qtype1(seg[seg_ind*2] , seg[seg_ind*2+1]);
    }
}

void solve(){
    int nn,n;
    cin>>n;
    // n=(1<<nn);
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int seg[4*n]={0};
    build(seg,1,0,n-1,arr);
    // for(int i=0;i<4*n;i++)cout<<seg[i]<<" ";
    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {   int qq;
        cin>>qq;
        if(qq==2)
        
        {
            int ind,val;
            cin>>ind>>val;
            // ind is 1 indexed
            ind--;
            update(seg,1,0,n-1,ind,val,arr);
        }
        else
        {
            int l,r;
            cin>>l>>r;
            // l and r are 1 indexed
            l--,r--;
            cout<<Q(seg,1,0,n-1,l,r)<<"   ";
            // line();
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
