for(int i=1;i<=n;i++){
        queue<int> q;
        int vis[n+1];
        int par[n+1]={0};
        memset(vis,-1,sizeof vis);
        vis[i]=0;
        q.push(i);
        while(q.size()){
            int node=q.front();
            q.pop();
            for(int j=0;j<G[node].size();j++){
                int ch=G[node][j];
                if(par[node]==ch)continue;
                if(vis[ch]!=-1){
                    ans=min(vis[node]+vis[ch]+1,ans);
                }
                else{
                    par[ch]=node;
                    vis[ch]=vis[node]+1;
                    q.push(ch);
                }
            }
        }
    }
