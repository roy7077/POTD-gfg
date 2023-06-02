
#define ll long long
class Solution{
public:

    int cnt=0;
    vector<int> store;

    void precompute() {
        int size = 1299723;
        store.resize(size, 0);

        for (int i = 2; i*i < size; i++) {
            for (int j = i*i; j < size; j += i) {
                store[j] = true;
            }
        }
    }
    
    void dfs(int node,vector<int>& visited,vector<vector<int>>& g)
    {
        visited[node]=1;
        cnt++;
        for(auto it:g[node])
        {
            if(!visited[it])
            dfs(it,visited,g);
        }
    }
    int helpSanta(int n, int m, vector<vector<int>>& g){
        
        vector<int> visited(n+1,0);
        int maxi=0;
        for(int i=0;i<=n;i++)
        {
            if(!visited[i])
            {
                dfs(i,visited,g);
                maxi=max(maxi,cnt);
                cnt=0;
            }
        }
        
        if(maxi==1)
        return -1;
        
        int count=0;
        for(int i=2;i<1299723;i++)
        {
            if(!store[i])
            count++;
            
            if(count==maxi)
            return i;
        }
        
        
    }
    
};

