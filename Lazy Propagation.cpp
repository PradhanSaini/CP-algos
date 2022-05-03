#include <bits/stdc++.h> 
using namespace std;
#define int long long
int mod=1e9+7;

class ele
{
public:
    int sum=0,val=0;
    
};

void line(){
    cout<<"--------------"<<endl;
}

int qtype1(int a,int b){
    return (a+b);
}

int qtype2(int a,int b){
    return (a+b);
}


void build(ele seg[], int seg_ind, int arr_l, int arr_r,int arr[]) {
    if (arr_l == arr_r) {
        seg[seg_ind].sum = arr[arr_l];
    } 
    else {
        int tm = (arr_l + arr_r) / 2;
        build(seg, seg_ind*2, arr_l, tm,arr);
        build(seg, seg_ind*2+1, tm+1, arr_r,arr);
        seg[seg_ind].sum = qtype1(seg[seg_ind*2].sum,seg[seg_ind*2+1].sum);
    }
}

int Q(ele seg[],int seg_ind, int arr_l, int arr_r, int l, int r) {
    // cout<<"---->"<<l<<" "<<r<<endl;
    if (l > r) 
        return 0;
    if (l == arr_l && r == arr_r) {
        return seg[seg_ind].sum;
    }
    int arr_m = (arr_l + arr_r) / 2;
    // updating children
    int t=seg[seg_ind].val;
    if(t){
        // cout<<"yes";
        seg[seg_ind].val=0;
        seg[seg_ind*2].sum+=(arr_m-arr_l+1)*t;
        seg[seg_ind*2].val+=t;
        seg[seg_ind*2+1].sum+=(arr_r-arr_m)*t;
        seg[seg_ind*2+1].val+=t;
    }
    return qtype2(Q(seg,seg_ind*2, arr_l, arr_m, l, min(r, arr_m))
           , Q(seg,seg_ind*2+1, arr_m+1, arr_r, max(l, arr_m+1), r));
}

void update(ele seg[],int seg_ind, int arr_l, int arr_r, int l,int r,int new_val,int arr[]) {
    if (l > r) 
        return ;
    if (l == arr_l && r == arr_r) {
        seg[seg_ind].val+=new_val;
        seg[seg_ind].sum+=new_val*(r-l+1);
        return;
    }
    int arr_m = (arr_l + arr_r) / 2;
    update(seg,seg_ind*2, arr_l, arr_m, l, min(r, arr_m),new_val,arr);
    update(seg,seg_ind*2+1, arr_m+1, arr_r, max(l, arr_m+1), r,new_val,arr);
    seg[seg_ind].sum = qtype1(seg[seg_ind*2].sum,seg[seg_ind*2+1].sum)+seg[seg_ind].val*(arr_r-arr_l+1);
}

void solve(){
    int n,q;
    cin>>n>>q;
    int arr[n]={0};
    // for(int i=0;i<n;i++)
    //     cin>>arr[i];
    ele seg[4*n];
    // build(seg,1,0,n-1,arr);
    // for(int i=1;i<7;i++)cout<<'('<<seg[i].sum<<','<<seg[i].val<<')';
    // cout<<endl;
    // int q;
    // cin>>q;
    for(int i=0;i<q;i++)
    {   int qq;
        cin>>qq;
        if(qq==1){
            int l,r,val;
            cin>>l>>r>>val;
            // l and r are 1 indexed
            l--,r--;// now 0 indexed
            update(seg,1,0,n-1,l,r,val,arr);
        }
        else {
            int l,r;
            cin>>l>>r;
            // l and r are 1 indexed
            l--,r--;// now 0 indexed
            cout<<Q(seg,1,0,n-1,l,r)<<endl;
            // line();
        }
        // for(int i=1;i<7;i++)cout<<'('<<seg[i].sum<<','<<seg[i].val<<')';
        // cout<<Q(seg,1,0,n-1,0,n-1)<<endl;
        // cout<<endl;
    }

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    // cin>>t;
    t=1;
    int i=1;
    while(t--)
        {
            solve();
        }
}
