class Solution
{
    private:
    void dfstopo(vector<int>& visited,vector<int> adj[],stack<int>& st,int node)
    {
        visited[node]=1;
        for(auto it:adj[node])
        {
            if(!visited[it])
            dfstopo(visited,adj,st,it);
        }
        st.push(node);
        return ;
    }
	public:
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> visited(V,0);
	    stack<int> st;
	    for(int i=0;i<V;i++)
	    {
	        if(!visited[i])
	        {
	            dfstopo(visited,adj,st,i);
	        }
	    }
	    vector<int> ans;
	    while(!st.empty())
	    {
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	}
};