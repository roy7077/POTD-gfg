// Eulers cycle or not
// each node should have even degree
class Solution {
    public:
	int isPossible(vector<vector<int>>paths){
	    for(int i=0;i<paths.size();i++)
	    {
	        int cnt=0;
	        for(int j=0;j<paths[0].size();j++)
	        cnt+=paths[i][j];
	        
	        if(cnt&1)
	        return 0;
	    }
	    return 1;
	}

};