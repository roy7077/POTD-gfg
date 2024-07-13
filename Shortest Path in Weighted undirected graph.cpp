typedef pair<int,int> pi;
class Solution {
    public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        
        // making adj list
        vector<vector<int>> adj[n+1];
        for(auto& it:edges)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        // calculating shortest path
        vector<int> dis(n+1,1e9);
        vector<int> parent(n+1,0);
        for(int i=0;i<=n;i++)
        parent[i]=i;
        
        dis[1]=0;
        
        priority_queue <pi, vector<pi>, greater<pi>> pq;
        pq.push({0,1});
        
        while(!pq.empty())
        {
            int node=pq.top().second;
            int d=pq.top().first;
            pq.pop();
            
            if(node==n)
            break;
            
            for(auto& it:adj[node])
            {
                int distance=d+it[1];
                if(distance<dis[it[0]])
                {
                    parent[it[0]]=node;
                    dis[it[0]]=distance;
                    pq.push({distance,it[0]});
                }
            }
        }
        
        
        // making ans
        vector<int> ans;
        int node=n;
        while(parent[node]!=node)
        {
            ans.push_back(node);
            node=parent[node];
        }
        ans.push_back(node);
        
        reverse(ans.begin(),ans.end());
        
        if(ans.size()<=1)
        return {-1};
        
        ans.insert(ans.begin(),dis[n]);
        return ans;
    }
};
