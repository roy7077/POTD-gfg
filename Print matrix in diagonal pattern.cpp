// Method - 1
// Time complexity - O(N*N)
// Space complexity- O(N*N)
class Solution{
    private:
    bool isPossible(int i,int j,int n,int m)
    {
        return i<n and j<m and i>=0 and j>=0;
    }
    public:
    vector<int> matrixDiagonally(vector<vector<int>>&mat)
    {
        vector<int> ans;
        int n=mat.size();
        int m=mat[0].size();
        
        // 1st half
        int i=0;
        int j=0;
        bool flag=1;
        while(isPossible(i,j,n,m))
        {
            if(flag)
            {
                while(isPossible(i,j,n,m))
                {
                    ans.push_back(mat[i][j]);
                    i--;
                    j++;
                }
                i=0;
            }
            else
            {
                while(isPossible(i,j,n,m))
                {
                    ans.push_back(mat[i][j]);
                    i++;
                    j--;
                }
                j=0;
            }
            flag=(!flag);
        }
        
        //2nd half
        if(n&1)
        {
            i=1;
            j=m-1;
            flag=0;
        }
        else
        {
            i=n-1;
            j=1;
            flag=1;
        }
        while(isPossible(i,j,n,m))
        {
            if(flag)
            {
                while(isPossible(i,j,n,m))
                {
                    ans.push_back(mat[i][j]);
                    i--;
                    j++;
                }
                i+=2;
                j--;
            }
            else
            {
                while(isPossible(i,j,n,m))
                {
                    ans.push_back(mat[i][j]);
                    i++;
                    j--;
                }
                i--;
                j+=2;
            }
            flag=(!flag);
        }
        return ans;
    }
};
