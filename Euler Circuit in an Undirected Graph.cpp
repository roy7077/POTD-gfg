
// Method - 1
// Time complexity - O(N)
// Space complexity- O(N)
class Solution {
    public:
	bool isEularCircuitExist(int n, vector<int>adj[]){
	    unordered_map<int,int> mp;
	    for(int i=0;i<n;i++)
	    {
	        if(adj[i].size()>=1)
	        mp[adj[i][0]]++;
	        
	        if(adj[i].size()>=2)
	        mp[adj[i][1]]++;
	    }
	    
	    for(auto it:mp)
	    {
	        if(it.second&1)
	        return 0;
	    }
	    
	    return 1;
	}

};

// Method - 2
// Time complexity - O(N)
// Space complexity- O(1)
class Solution {
    public:
	bool isEularCircuitExist(int n, vector<int>adj[]){
	    for(int i=0;i<n;i++)
	    {
	        if(adj[i].size()&1)
	        return 0;
	    }
	    
	    return 1;
	}

};
