// Time complexity - O(N*N)
// Space complexity- O(1)
class Solution{
    public:
    /*Function to count zeros in each column
    * N : Number of rows and columns in array
    M is the matrix that is globally declared
    */
    int columnWithMaxZeros(vector<vector<int>>arr,int N){
        int index=-1;
        int maxi=0;
        for(int j=0;j<N;j++)
        {
            int cnt=0;
            for(int i=0;i<N;i++)
            {
                if(!arr[i][j])
                cnt++;
            }
            
            if(cnt>maxi)
            {
                maxi=cnt;
                index=j;
            }
        }
        return index;
    }
};
