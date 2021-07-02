//https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1/#

//TC=O(V+E) SC=O(V)
bool dfs(int v, int par, bool vis[], vector<int>adj[])
    {
        vis[v] = 1;
        for(int i=0;i<adj[v].size();i++)
        {
            int child = adj[v][i];
            if(vis[child]==0)
            {
                if(dfs(child, v, vis, adj) == true)
                return true;
            }
            else
            {
                if(child!=par) /* ek edge sirf child aur parent ke beech hota h
                if a child is already visited tb woh uss node ka parent hi hona chahiye if not then there is a back edge hence cycle*/
                return true;
            }
        }
        return false;
    }
    //Function to detect cycle in an undirected graph.
	bool isCycle(int V, vector<int>adj[])
	{
	    // Code here
	    bool vis[V] = {0};
	    for(int u=0; u<V; u++) //to detect cycle in all connected components of graph
	    {
	        if(vis[u]==0) //run dfs only when node is unvisited
	        {
	            if(dfs(u, -1, vis, adj)) //kisi bhi connected comp me cycle mil gyi return true
	            return true;
	        }
	    }
	    return false;
	}