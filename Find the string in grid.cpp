//Time  complexity- O(N*M*8*k)
//Space complexity- O(8+8)
class Solution {
public:
    
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    
        int x[8]={-1,-1,-1,0,0,1,1,1};
        int y[8]={-1,0,1,-1,1,-1,0,1};
        vector<vector<int>> ans;
        int n=grid.size();
        int m=grid[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==word[0])
                {
                    for(int k=0;k<8;k++)
                    {
                        int delr=x[k];
                        int delc=y[k];
                        
                        int row=i;
                        int col=j;
                        int ind=0;
                        
                        while(row>=0 and row<n and col>=0 and col<m
                         and ind<word.length() and grid[row][col]==word[ind])
                         {
                             row+=delr;
                             col+=delc;
                             ind++;
                         }
                          
                         if(ind==word.length())
                         {
                             ans.push_back({i,j});
                             break;
                         }
                    }
                }
            }
        }
        
        return ans;
	}
};