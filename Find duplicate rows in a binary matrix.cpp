//SIMPLE || SET || T - O(N*M) || S - O(N*M)
// Time complexity - O(M*N)
// Space complexity- O(M*N)
class Solution
{   
    public:
    vector<int> repeatedRows(vector<vector<int>> &matrix, int M, int N) 
    { 
        set<vector<int>> st;
        vector<int> ans;
        for(int i=0;i<M;i++)
        {
            if(st.count(matrix[i]))
            ans.push_back(i);
            else
            st.insert(matrix[i]);
        }
       return ans;
    } 
};