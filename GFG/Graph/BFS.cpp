//https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1#

//TC=O(V+E) V is for initialising the visited array and E is cause we r operating on all the edges only
//SC=O(V) visited array, queue me ek baar me saare nodes toh honge nhi so its size < visited array
//Here we use a Queue!
void bfs(int v, vector<int> adj[], bool vis[], vector<int> &ans)
    {
	    queue<int> q;
	    vis[v] = true;
	    q.push(v);
	    
	    while(!q.empty())
	    {
	        int temp = q.front();
	        ans.push_back(temp);
	        q.pop();
	        for(int i=0; i<adj[temp].size(); i++)
	        {
	            int child = adj[temp][i];
	            if(vis[child]==0)
	            {
	                vis[child] = true;
	                q.push(adj[temp][i]);
	            }
	        }
	    }
    }
    //Function to return Breadth First Traversal of given graph.
	vector<int>bfsOfGraph(int V, vector<int> adj[])
	{
	    // Code here
	   vector<int> ans;
	   bool vis[V] = {false};
	   bfs(0, adj, vis, ans);
	   return ans;
	}