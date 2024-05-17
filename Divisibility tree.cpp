// Method - 1
class Solution {
    public:
    pair<int,int> dfs(vector<int>* adj,int node,int parent)
    {
        int cnt=1;
        int ans=0;
        for(auto& it:adj[node])
        {
            if(it!=parent)
            {
                pair<int,int> fnCall=dfs(adj,it,node);
                ans+=fnCall.second;
                if(fnCall.first%2==0)
                ans++;
                else
                cnt+=fnCall.first;
            }
        }
        return {cnt,ans};
    }
	int minimumEdgeRemove(int n, vector<vector<int>>edges){
	  
	    vector<int> adj[n+1];
	    for(auto& it:edges)
	    {
	        adj[it[0]].push_back(it[1]);
	        adj[it[1]].push_back(it[0]);
	    }

	    return dfs(adj,1,-1).second;
	}
};


// Method - 2
class Solution {
    public:
    int dfs(vector<int>* adj,int node,int parent,int& ans)
    {
        int cnt=1;
        for(auto& it:adj[node])
        {
            if(it!=parent)
            {
                int cntNode=dfs(adj,it,node,ans);
                if(cntNode%2==0)
                ans++;
                else
                cnt++;
            }
        }
        return cnt;
    }
	int minimumEdgeRemove(int n, vector<vector<int>>edges){
	    
	    vector<int> adj[n+1];
	    for(auto& it:edges)
	    {
	        adj[it[0]].push_back(it[1]);
	        adj[it[1]].push_back(it[0]);
	    }
	    
	    int ans=0;
	    dfs(adj,1,-1,ans);
	    return ans;
	}
};
