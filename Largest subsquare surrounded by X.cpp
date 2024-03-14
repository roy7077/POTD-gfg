// Method - 1
// Time complexity - O(N*N)
// Space complexity- O(2*N*N)
class Solution {
    public:
    int largestSubsquare(int n, vector<vector<char>> a) {
        vector<vector<int>> v1(n,vector<int>(n,0));
        vector<vector<int>> v2(n,vector<int>(n,0));
        
        // col
        for(int i=0;i<n;i++)
        {
            int sum=0;
            for(int j=n-1;j>=0;j--)
            {
                if(a[i][j]=='O')
                {
                    sum=0;
                    v1[i][j]=0;
                }
                else
                {
                    sum++;
                    v1[i][j]=sum;
                }
            }
        }
        
        // rows
        int maxi=10002;
        for(int j=0;j<n;j++)
        {
            int sum=0;
            for(int i=n-1;i>=0;i--)
            {
                if(a[i][j]=='O')
                sum=0;
                else
                {
                    sum++;
                    v2[i][j]=sum;
                }
            }
        }
        
        
        //finding max submatrix
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][j]=='O')
                continue;
                
                int size=min(v1[i][j],v2[i][j]);
                
                while(size>ans)
                {
                    if((v1[i+size-1][j])>=size and (v2[i][j+size-1])>=size)
                    ans=size;
                    
                    size--;
                }
            }
        }
        return ans;
    }
};


// Method - 2
// Time complexity - O(N*N)
// Space complexity- O(N*N)
class Solution {
    public:
    int largestSubsquare(int n, vector<vector<char>> a) {
        vector<vector<int>> v(n,vector<int>(n,0));
        
        // col
        for(int i=0;i<n;i++)
        {
            int sum=0;
            for(int j=n-1;j>=0;j--)
            {
                if(a[i][j]=='O')
                {
                    sum=0;
                    v[i][j]=0;
                }
                else
                {
                    sum++;
                    v[i][j]=sum;
                }
            }
        }
        
        // rows
        int maxi=10002;
        for(int j=0;j<n;j++)
        {
            int sum=0;
            for(int i=n-1;i>=0;i--)
            {
                if(a[i][j]=='O')
                sum=0;
                else
                {
                    sum++;
                    int ori=v[i][j];
                    int ne=maxi*sum;
                    v[i][j]=(ne+ori);
                }
            }
        }
        
        
        //finding max submatrix
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][j]=='O')
                continue;
                
                int maxCol=v[i][j]%maxi;
                int maxRow=v[i][j]/maxi;
                
                int size=min(maxCol,maxRow);
                
                while(size>ans)
                {
                    if((v[i+size-1][j]%maxi)>=size and (v[i][j+size-1]/maxi)>=size)
                    ans=size;
                    
                    size--;
                }
            }
        }
        return ans;
    }
};
