//https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1#

//TC=O(V + E) V is for initialising the visited array and E is cause we r operating on all the edges only
//SC=O(V) visited array, stack me ek baar me saare nodes toh honge nhi so its size < visited array
// BFS and DFS have the exact same algorithm, the difference is jst in the Data Structure used
//Here we use a Stack!
void dfs(int v, vector<int> adj[], int vis[], vector<int> &ans)
    {
        vis[v]=1;
        ans.push_back(v);
        for(int i=0; i<adj[v].size(); i++)
        {
            int child = adj[v][i];
            if(vis[child]==0)
            dfs(child, adj, vis, ans);
        }
    }
	//Function to return a list containing the DFS traversal of the graph.
	vector<int>dfsOfGraph(int V, vector<int> adj[])
	{
	    // Code here
	    vector<int> ans;
	    int vis[V]={0};
	    dfs(0, adj, vis, ans);
	    return ans;
	}