#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;

void update(int ind,int val,int b[]){
      if(ind>=n)return;
      b[ind]+=val;
      update(ind|(ind+1),val,b);
}
int sum(int ind ,int b[]){
	if(ind<0)return 0;
	cout<<ind<<endl;
	return b[ind]+sum((ind & (ind+1))-1 , b);
}

void solve(){
	
	cin>>n;
	int a[n];
	int q;
    cin>>q;
	for(int i=0;i<n;i++)cin>>a[i];
    int b[n]={0};
    for(int i=0;i<n;i++)update(i,a[i],b);
	
	for(int i=0;i<q;i++){
        int type;
        cin>>type;

        if(type==1){
	       	int ii,val;
	       	cin>>ii>>val;
	       	update(ii,val,b);
	    }
        
        else{
	       	int r,l;
	       	cin>>l>>r;
	       	int rr=sum(r,b);
	       	int ll=sum(l-1,b);
	        cout<<rr<<" "<<ll<<endl;
        }
	}

}

signed main(){
	int t;
	// cin>>t;
	t=1;
	while(t--)solve();
}
