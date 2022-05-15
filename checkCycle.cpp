bool iscycle(vector<vector<int>> &G){
    int n=G.size()-1;
    int tot=0;
    int in[n+1]={0};
    queue<int> q;
    for(int i=1;i<=n;i++){
        for(int j=0;j<G[i].size();j++)
        in[G[i][j]]++;
    }
    for(int i=1;i<=n;i++)if(in[i]==0)q.push(i);
    while(q.size()){
        int node=q.front();
        q.pop();
        tot++;
        for(int i=0;i<G[node].size();i++){
            int ch=G[node][i];
            in[ch]--;
            if(in[ch]==0)q.push(ch);
        }
    }
    return tot<n;
}
