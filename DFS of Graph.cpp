class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(vector<int>* adj,int node,vector<int>& visited,vector<int>& ans)
    {
        ans.push_back(node);
        visited[node]=1;
        for(auto it:adj[node])
        {
            if(!visited[it])
            dfs(adj,it,visited,ans);
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        
        vector<int> ans;
        vector<int> visited(V,0);
        
        dfs(adj,0,visited,ans);
        return ans;
    }
};