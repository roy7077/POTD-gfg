// TWO  APPROACHES 

// DFS
// Time complexity - O(N+M)
// Space complexity - O(N)
class Solution {
    public:
    
    void dfs(vector<int>* adj,int node,vector<int>& visited)
    {
        visited[node]=1;
        for(auto it:adj[node])
        {
            if(!visited[it])
            dfs(adj,it,visited);
        }
    }
    int isTree(int n, int m, vector<vector<int>> &edg) {
        
        if((n-m)!=1)
        return 0;
        
        vector<int> adj[n];
        for(auto it:edg)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> visited(n,0);
        dfs(adj,0,visited);
        
        for(auto it:visited)
        {
            if(it==0)
            return 0;
        }
        
        return 1;
    }
};

//ITERATIVE || SET 
// Time complexity - O(MlogM)
// Space complexity - O(2*N+N)
class Solution {
    public:
    int isTree(int n, int m, vector<vector<int>> &adj) {
        
        if(n==1 and m==0)
        return 1;
        
        set<pair<int,int>> st;
        vector<int> inout(n,0);
        
        int maxi=1e5;
        for(auto it:adj)
        {
            if(st.count({it[0],it[1]}) or st.count({it[1],it[0]}))
            return 0;
            
            if(it[0]==it[1])
            return 0;
            
            st.insert({it[0],it[1]});
            st.insert({it[1],it[0]});
            
            //outgoing
            int out1=inout[it[0]]/maxi;
            int in1=inout[it[0]]%maxi;
            
            inout[it[0]]=((out1+1)*maxi)+in1;
            
            //incomming
            out1=inout[it[1]]/maxi;
            in1=inout[it[1]]%maxi;
            
            inout[it[1]]=(out1*maxi)+(in1+1);
        }
        
        for(int i=0;i<n;i++)
        {
            int in=inout[i]%maxi;
            int out=inout[i]/maxi;
            
            if(in>=2 and out>=2)
            return 0;
            
            if(out>=2 and in>=2)
            return 0;
            
            if(in==0 and out==0)
            return 0;
        }
        
        return 1;
    }
};