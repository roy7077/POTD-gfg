// Time complexity - O(N*N)
// Space complexity- O(N*N)
class Solution {
    public:
    vector<int> spirallyTraverse(vector<vector<int>> &mat) {
        vector<int> ans;
        int n=mat.size();
        int m=mat[0].size();
        
        int i1=0;
        int j1=0;
        int i2=n-1;
        int j2=m-1;
        int flag=1;
        
        while(i1<=i2 and j1<=j2)
        {
            // first row
            if(flag==1)
            {
                for(int j=j1;j<=j2;j++)
                ans.push_back(mat[i1][j]);
                
                i1++;
                flag=2;
                continue;
            }
            
            // last col
            if(flag==2)
            {
                for(int i=i1;i<=i2;i++)
                ans.push_back(mat[i][j2]);
                
                j2--;
                flag=3;
                continue;
            }
            
            // last row
            if(flag==3)
            {
                for(int j=j2;j>=j1;j--)
                ans.push_back(mat[i2][j]);
                
                i2--;
                flag=4;
                continue;
            }
            
            // first col
            if(flag==4)
            {
                for(int i=i2;i>=i1;i--)
                ans.push_back(mat[i][j1]);
                
                j1++;
                flag=1;
                continue;
            }
        }
        
        return ans;
    }
};
