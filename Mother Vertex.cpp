class Solution 
{
    public:
    void dfs(vector<int>* adj,int node,vector<int>& visited,unordered_map<int,int>& mp)
    {
        visited[node]=1;
        mp[node]=1;
        for(auto it:adj[node])
        {
            if(mp.count(it)==0)
            dfs(adj,it,visited,mp);
        }
    }
    
	int findMotherVertex(int V, vector<int>adj[])
	{
	    vector<int> visited(V,0);
	    for(int i=0;i<V;i++)
	    {
	        if(!visited[i])
	        {
	            unordered_map<int,int> mp;
	            dfs(adj,i,visited,mp);
	            
	            if(mp.size()==V)
	            return i;
	        }
	        
	    }
	    
	    return -1;
	}

};