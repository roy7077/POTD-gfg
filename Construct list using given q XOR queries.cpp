/*
 Time complexity - O(Q*logQ)
 Space complexity- O(Q)
*/
class Solution {
    public:
    vector<int> constructList(int n, vector<vector<int>> &q) {
        vector<int> ans;
        int xorr=0;
        for(int i=n-1;i>=0;i--)
        {
            if(!q[i][0])
            ans.push_back(q[i][1]^xorr);
            else
            xorr^=q[i][1];
        }
        ans.push_back(xorr^0);
        sort(ans.begin(),ans.end());
        return ans;
    }
};