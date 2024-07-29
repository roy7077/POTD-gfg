// User function template for C++

// Time complexity - O(N+M)
// Space complexity- O(1)
class Solution {
    public:
    int rowWithMax1s(vector<vector<int> > &arr) {
        int n=arr.size();
        int m=arr[0].size();
        int j=m-1;
        int i=0;
        int ind=-1;
        while(j>=0 and i<n)
        {
            if(arr[i][j])
            {
                ind=i;
                j--;
            }
            else
            i++;
        }
        
        return ind;
    }
};

/*
0 0 0 1 1 1 1 1 1
0 0 0 0 1 1 1 1 1
0 0 0 0 1 1 1 1 1
*/
