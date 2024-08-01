// Time complexity - O(N*M)
// Space compleixty- O(1)
class Solution {
    public:
    vector<int> spirallyTraverse(vector<vector<int> > &matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int i1=0;
        int i2=n-1;
        int j1=0;
        int j2=m-1;
        vector<int> ans;
        int dir=1;
        while(i2>=i1 and j1<=j2)
        {
            // if dir = 1, that's mean left to right
            if(dir==1)
            {
                for(int k=j1;k<=j2;k++)
                ans.push_back(matrix[i1][k]);
                
                i1++;
                dir=2;
                continue;
            }
        
            // if dir = 2, that's mean up to down
            if(dir==2)
            {
                for(int k=i1;k<=i2;k++)
                ans.push_back(matrix[k][j2]);
                
                j2--;
                dir=3;
                continue;
            }
            
            // if dir = 3, that's mean right to left
            if(dir==3)
            {
                for(int k=j2;k>=j1;k--)
                ans.push_back(matrix[i2][k]);
                
                i2--;
                dir=4;
                continue;
            }
            
            // if dir = 4, that's mean down to up
            if(dir==4)
            {
                for(int k=i2;k>=i1;k--)
                ans.push_back(matrix[k][j1]);
                
                j1++;
                dir=1;
                continue;
            }
        }
        return ans;
    }
};

