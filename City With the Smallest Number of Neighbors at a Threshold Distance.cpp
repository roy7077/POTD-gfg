/* Method - 1
   Floyd warshall Algorithm
   Time complexity - O(N^3)
   Space complexity- O(N*N)
*/
class Solution {
    public:
    int findCity(int n, int m, vector<vector<int>>& edges,int distanceThreshold) {
        
        //adjacency matrix
        vector<vector<int>> floyd(n,vector<int>(n,1e9));
        for(auto it:edges)
        {
            floyd[it[0]][it[1]]=it[2];
            floyd[it[1]][it[0]]=it[2];
        }
        
        //floyd warshall
        for(int via=0;via<n;via++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                floyd[i][j]=min(floyd[i][j],floyd[i][via]+floyd[via][j]);
            }
        }
        
        //City With the Smallest Number of Neighbors at a Threshold Distance
        int node=-1;
        int mini=1e9;
        for(int i=0;i<n;i++)
        {
            int cnt=0;
            for(int j=0;j<n;j++)
            {
                if(i==j)
                continue;
                
                if(floyd[i][j]<=distanceThreshold)
                cnt++;
            }
            
            if(cnt<mini)
            {
                mini=cnt;
                node=i;
            }
            else if(cnt==mini)
            node=max(node,i);
        }
        return node;
    }
};


/* Method - 2
   Dijkstra Algorithm
   Time complexity - O (N*(V+ElogV)) 
   Space complexity- O((N*N)+(N+N))
*/
typedef pair<int,int> pi;
class Solution {
    public:
    void dijkstra(vector<pi>* adj,int node,vector<int>& v)
    {
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        pq.push({0,node});
        v[node]=0;
        while(!pq.empty())
        {
            int n=pq.top().second;
            int d=pq.top().first;
            pq.pop();
            
            for(auto it:adj[n])
            {
                int distance=it.second+d;
                if(v[it.first]>distance)
                {
                    pq.push({distance,it.first});
                    v[it.first]=distance;
                }
            }
        }
    }
    int findCity(int n, int m, vector<vector<int>>& edges,int distanceThreshold) {
        
        //adjacency list
        vector<pi> adj[n];
        for(auto it:edges)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        //dijkstra algorithm
        int ans=1e9;
        int node=-1;
        for(int i=0;i<n;i++)
        {
            vector<int> minPath(n,1e9);
            dijkstra(adj,i,minPath);
            
            int cnt=0;
            for(int j=0;j<n;j++)
            {
                if(i==j)
                continue;
                
                if(minPath[j]<=distanceThreshold)
                cnt++;
            }
            
            if(cnt<ans)
            {
                ans=cnt;
                node=i;
            }
            else if(cnt==ans)
            node=max(node,i);
        }
        return node;
    }
};
