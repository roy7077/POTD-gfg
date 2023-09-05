class Solution {
    public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int,int>>edges) {
        
        vector<vector<int>> adj(V);
        for(auto it:edges)
        {
            adj[it.first].push_back(it.second);
            adj[it.second].push_back(it.first);
        }
        
        return adj;
    }
};