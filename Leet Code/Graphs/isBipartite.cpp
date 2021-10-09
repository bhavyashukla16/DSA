//https://leetcode.com/problems/is-graph-bipartite/

//Method 1: using DFS
int vis[103], col[103];
    bool dfs(int v, int c, vector<vector<int>>& graph)
    {
        vis[v]=1;
        col[v]=c;
        for(int j : graph[v])
        {
            if(vis[j]==0) {
                if(dfs(j, c^1, graph)==false)
                    return false;
            }
            else {
                if(col[v]==col[j])
                    return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        memset(vis, 0, sizeof(vis));
        for(int i=0;i<graph.size();i++) {
            if(vis[i]==0) {
                if(dfs(i, 1, graph) == false)
                    return false;
            }
        }
        return true;
    }

//METHOD 2: BFS
 int vis[103]={0}, col[103];
    bool bfs(int v, vector<vector<int>>& graph)
    {
        vis[v]=1;
        col[v]=1;
        queue<int> q;
        q.push(v);
        
        while(!q.empty())
        {
            int curr=q.front();
            q.pop();
            for(int child : graph[curr])
            {
                if(vis[child]==0) {
                    vis[child]=1;
                    col[child]=1-col[curr];
                    q.push(child);
                }
                else {
                    if(col[child]==col[curr])
                        return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        //memset(vis, 0, sizeof(vis));
        for(int i=0;i<graph.size();i++) {
            if(vis[i]==0) {
                if(bfs(i, graph) == false)
                    return false;
            }
        }
        return true;
    }