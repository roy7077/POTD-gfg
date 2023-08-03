class Solution {
  public:
     
     void dfs_toposort(vector<pair<int,int>>* adj,int node,vector<int>& visited,stack<int>& st)
     {
        visited[node]=1;
        for(auto it:adj[node])
        {
            if(visited[it.first]==0)
            dfs_toposort(adj,it.first,visited,st);
        }
        
        st.push(node);
     }
     
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        
        //creating a adj list
        vector<pair<int,int>> adj[N];
        for(auto it:edges)
        {
            int u=it[0];
            int v=it[1];
            int w=it[2];
            
            adj[u].push_back({v,w});
        }
        
        vector<int> visited(N,0);
        stack<int> st;
        
        for(int i=0;i<N;i++)
        {
            if(visited[i]==0)
            dfs_toposort(adj,i,visited,st);
        }
        
        vector<int> ans(N,1e9);
        ans[0]=0;
        
        while(!st.empty())
        {
            int node=st.top();
            st.pop();
            
            int dis=ans[node];
            for(auto it:adj[node])
            {
                int dis2=it.second;
                dis2+=dis;
                
                if(dis2<ans[it.first])
                ans[it.first]=dis2;
            }
        }
        
        for(int i=0;i<N;i++)
        {
            if(ans[i]>=1e9)
            ans[i]=-1;
        }
        
        return ans;
    }
};