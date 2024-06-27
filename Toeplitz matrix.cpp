// Time complexity - O(N*M)
// Space complexity- O(1)

bool isToeplitz(vector<vector<int>>& mat) {
    
    int n=mat.size();
    int m=mat[0].size();
    
    //first
    for(int j=m-1;j>=0;j--)
    {
        int k=j;
        int i=0;
        int num=mat[i][j];
        while(i<n and k<m)
        {
            if(mat[i][k]!=num)
            return 0;
            
            i++;
            k++;
        }
    }
    
    //second
    for(int i=1;i<n;i++)
    {
        int j=0;
        int k=i;
        int num=mat[k][0];
        while(k<n and j<m)
        {
            if(mat[k][j]!=num)
            return 0;
            
            k++;
            j++;
        }
    }
    
    return 1;
}