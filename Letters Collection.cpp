class Solution{
    public:
    vector<int> matrixSum(int n, int m, vector<vector<int>> mat, int q, vector<int> queries[])
    {
        vector<int> ans;
        for(int it=0;it<q;it++)
        {
            int sum=0;
            int r=queries[it][0];
            int i=queries[it][1];
            int j=queries[it][2];
            if(r==1)
            {
                if(i-1>=0 and j-1>=0)
                sum+=mat[i-1][j-1];
                
                if(i-1>=0)
                sum+=mat[i-1][j];
                
                if(i-1>=0 and j+1<m)
                sum+=mat[i-1][j+1];
                
                if(j+1<m)
                sum+=mat[i][j+1];
                
                if(i+1<n and j+1<m)
                sum+=mat[i+1][j+1];
                
                if(i+1<n)
                sum+=mat[i+1][j];
                
                if(i+1<n and j-1>=0)
                sum+=mat[i+1][j-1];
                
                if(j-1>=0)
                sum+=mat[i][j-1];
            }
            else
            {
                //j-2th col , j+2th col
                for(int k=i-2;k<=i+2;k++)
                {
                    if(k>=0 and k<n and j-2>=0)
                    sum+=mat[k][j-2];
                    
                    if(k>=0 and k<n and j+2<m)
                    sum+=mat[k][j+2];
                }
                
                //i-2th row and i+2th row
                for(int k=j-2;k<=j+2;k++)
                {
                    if(i-2>=0 and k>=0 and k<m)
                    sum+=mat[i-2][k];
                    
                    if(i+2<n and k>=0 and k<m)
                    sum+=mat[i+2][k];
                }
                
                //excluding 4 corners that taken twice
                if(i-2>=0 and j-2>=0)
                sum-=mat[i-2][j-2];
                
                if(i+2<n and j-2>=0)
                sum-=mat[i+2][j-2];
                
                if(i-2>=0 and j+2<m)
                sum-=mat[i-2][j+2];
                
                if(i+2<n and j+2<m)
                sum-=mat[i+2][j+2];
                
            }
            
            ans.push_back(sum);
        }
        
        return ans;
    }
};