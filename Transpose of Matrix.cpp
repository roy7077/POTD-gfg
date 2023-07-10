class Solution
{   
    public:  
    //Function to find transpose of a matrix.
    void transpose(vector<vector<int> >& matrix, int n)
    { 
        int i=0;
        int j=0;
        while(i<n and j<n)
        {
            int k=i;
            int l=j;
            
            while(k<n and l<n)
            {
                swap(matrix[i][l],matrix[k][j]);
                l++;
                k++;
            }
            i++;
            j++;
        }
    }
};