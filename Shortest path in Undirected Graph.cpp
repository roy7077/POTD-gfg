class Solution {
    public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        
        // making an adj list
        vector<int> adj[N];
        for(auto& it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        // dijkstra algorithm
        vector<int> dis(N,1e9);
        dis[src]=0;
        queue<int> q;
        q.push(src);
        
        int distance=0;
        while(!q.empty())
        {
            distance++;
            int size=q.size();
            while(size--)
            {
                int node=q.front();
                q.pop();
                
                for(auto& it:adj[node])
                {
                    if(dis[it]>distance)
                    {
                        dis[it]=distance;
                        q.push(it);
                    }
                }
            }
        }
        
        // if we cannot reach to vertices
        // make it -1
        for(auto& it:dis)
        {
            if(it>=1e9)
            it=-1;
        }
        
        return dis;
    }
};
