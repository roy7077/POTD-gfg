// Topo sort
// BFS
class Solution
{
    public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        vector<int> adj[n];
        vector<int> indegree(n,0);
        
        for(auto it:prerequisites)
        {
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            q.push(i);
        }
        
        vector<int> ans;
        while(!q.empty())
        {
            int f=q.front();
            q.pop();
            
            ans.push_back(f);
            for(auto it:adj[f])
            {
                indegree[it]--;
                if(indegree[it]==0)
                q.push(it);
            }
        }
        
        for(auto it:indegree)
	    {
	        if(it>=1)
	        return {};
	    }
	    
        return ans;
    }
};

