class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        
        int mx = INT_MIN;
        int total =0;
        for(int i=0;i<n;i++)
        {

            int row_sum =0,col_sum =0;
            for(int j=0;j<n;j++)
            {
                row_sum += matrix[i][j];
                col_sum += matrix[j][i];
                total+= matrix[i][j];
                
            }
            mx = max(mx,max(row_sum,col_sum));
            
        }
     return (n*mx-total);
    } 

};