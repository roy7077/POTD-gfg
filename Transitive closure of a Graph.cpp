class Solution{
    public:   
    void dfs(vector<int>* adj,int node,vector<int>& visited)
    {
        visited[node]=1;
        for(auto it:adj[node])
        {
            if(!visited[it])
            dfs(adj,it,visited);
        }
    }
    
    vector<vector<int>> transitiveClosure(int N, vector<vector<int>> graph)
    {         
        //making adj list
        vector<int> adj[N];
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(graph[i][j])
                adj[i].push_back(j);
            }
        }
        
        vector<vector<int>> ans;
        for(int i=0;i<N;i++)
        {
            vector<int> visited(N,0);
            dfs(adj,i,visited);
            ans.push_back(visited);
        }
        
        return ans;
    }       
};