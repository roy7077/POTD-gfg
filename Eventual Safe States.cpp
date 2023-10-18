class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        
        //making rev adj list
        vector<int> Rev[V];
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<adj[i].size();j++)
            Rev[adj[i][j]].push_back(i);
        }
        
        //indegree
        vector<int> indegree(V,0);
        for(auto it:Rev)
        {
            for(auto x:it)
            indegree[x]++;
        }
        
        //free node queue
        queue<int> q;
        for(int i=0;i<V;i++)
        {
            if(indegree[i]==0)
            q.push(i);
        }
        
        //ans vector
        vector<int> ans;
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            ans.push_back(it);
            for(auto x:Rev[it])
            {
                indegree[x]--;
                if(indegree[x]==0)
                q.push(x);
            }
        }
        
        sort(ans.begin(),ans.end());
        return ans;
    }
};
