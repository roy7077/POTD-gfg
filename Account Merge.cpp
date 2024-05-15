class DisjointSetSize{
    vector<int> size;
    vector<int> parent;
    
    public:
    DisjointSetSize(int n)
    {
        size.resize(n+1,0);
        parent.resize(n+1,0);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
            size[i]=1;
        }
    }
    
    int findUPar(int node)
    {
        if(node==parent[node])
        return node;
        
        return parent[node]=findUPar(parent[node]);
    }
    
    void unionBySize(int u,int v)
    {
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        
        if(ulp_u==ulp_v)
        return ;
        
        if(size[ulp_u]<size[ulp_v])
        {
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else
        {
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};

class Solution{
    public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        int n=accounts.size();
        
        DisjointSetSize ds(n);
        unordered_map<string,int> mp;
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<accounts[i].size();j++)
            {
                string s=accounts[i][j];
                if(mp.count(s))
                {
                    int p1=mp[s];
                    int p2=i;
                    ds.unionBySize(p1,p2);
                }
                else
                mp[s]=i;
            }
        }
        
        unordered_map<int,vector<string>> mp2;
        for(auto it:mp)
        {
            int p1=ds.findUPar(it.second);
            mp2[p1].push_back(it.first);
        }
        
        vector<vector<string>> ans;
        for(auto& it:mp2)
        {
            sort(it.second.begin(),it.second.end());
            int ind=mp[it.second[0]];
            it.second.insert(it.second.begin(),accounts[ind][0]);
            ans.push_back(it.second);
    
        }
        
        return ans;
    }
};
