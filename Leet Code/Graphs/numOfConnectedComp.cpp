//https://leetcode.com/problems/number-of-provinces/

int vis[203]={0};
    void dfs(int v, vector<vector<int>>& isConnected) {
        vis[v]=1;
        for(int i=0; i<isConnected[v].size(); i++)
        {
            if(isConnected[v][i]==1)
            {
                if(vis[i]==0)
                    dfs(i, isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int cc=0;
        for(int i=0;i<isConnected.size();i++)
        {
            if(vis[i]==0) {
                dfs(i, isConnected);
                cc++;
            }
        }
        return cc;
    }