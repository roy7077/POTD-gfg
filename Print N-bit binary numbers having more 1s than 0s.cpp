// Recursion
// Time complexity - O(2^n)
// Space complexity- O(2^n)
class Solution{
    public:
    void help(int n,string s,int countOne,vector<string>& ans)
    {
        //base case
        if(n==0)
        {
            ans.push_back(s);
            return ;
        }
        
        //recursive calls
        //and small calculation
        help(n-1,s+'1',countOne+1,ans);
        if(countOne>0)
        help(n-1,s+'0',countOne-1,ans);
    }
	vector<string> NBitBinary(int n)
	{
	    vector<string> ans;
	    help(n,"",0,ans);
	    return ans;
	}
};