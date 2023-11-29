// Time complexity - O(V)
// Space complexity- O(1)
class Solution {
    public:
    int isEulerCircuit(int V, vector<int>adj[]){
	    int odd=0;
	    for(int i=0;i<V;i++)
	    {
	        if(adj[i].size()&1)
	        odd++;
	    }
	    
	    if(odd==0)
	    return 2;
	    
	    if(odd==2)
	    return 1;
	    
	    return 0;
	}
};
