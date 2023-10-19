class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    vector<int> dis(V,1e9);
	    queue<pair<int,int>> q;
	    q.push({0,0});
	    
	    while(!q.empty())
	    {
	        auto f=q.front();
	        q.pop();
	        int d=f.first;
	        int node=f.second;
	        
	        if(node==X)
	        return d;
	        
	        for(auto it:adj[node])
	        {
	            int dist=1+d;
	            if(dist<=dis[it])
	            {
	                dis[it]=dist;
	                q.push({dist,it});
	            }
	        }
	    }
	    
	    return dis[X]>=1e9 ? -1:dis[X];
	}
};
