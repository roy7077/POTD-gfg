// Time complexity - O(N*N)
// Space complexity- O(1)
class Solution
{   
    public:
    //Function to return sum of upper and lower triangles of a matrix.
    vector<int> sumTriangles(const vector<vector<int> >& matrix, int n)
    {
        int upper=0;
        int lower=0;

        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            upper+=matrix[i][j];
            
            for(int j=0;j<=i;j++)
            lower+=matrix[i][j];
        }
        
        return {upper,lower};
    }
};
