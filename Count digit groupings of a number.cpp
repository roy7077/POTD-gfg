// TWO APPROACHES || MEMOIZATION || TABULATION

// MEMOIZATION
class Solution{
	public:
	int help(string& s,int i,int pre,vector<vector<int>>& memo)
	{
	    //base case
	    if(i<0)
	    return 1;
	    
	    //memo check
	    if(pre!=-1 and memo[i][pre]!=-1)
	    return memo[i][pre];
	    
	    //recursive calls
	    //and small calculation
	    int sum=0;
	    int ans=0;
	    string str="";
	    for(int j=i;j>=0;j--)
	    {
	        sum+=s[j]-'0';
	        if(sum<=pre or pre==-1)
	        ans+=help(s,j-1,sum,memo);
	        else
	        break;
	    }
	    
	    if(pre==-1)
	    return ans;
	    
	    return memo[i][pre]=ans;
	}
	int TotalCount(string str){
	    vector<vector<int>> memo(str.length()+1,vector<int>(1000,-1));
	    return help(str,str.length()-1,-1,memo);
	}
};


// TABULATION
class Solution{
	public:
	int TotalCount(string str){
	    
	    int sumOfdigit=0;
	    for(auto it:str)
	    sumOfdigit+=(it-'0');
	    
	    vector<vector<int>> dp(str.length()+1,vector<int>(sumOfdigit+1,0));
	    
	    for(int i=str.length()-1;i>=0;i--)
	    {
	        for(int pre=0;pre<=sumOfdigit;pre++)
	        {
	            int sum=0;
	            int ans=0;
	            for(int j=i;j<str.length();j++)
	            {
	                sum+=(str[j]-'0');
	                if(sum>=pre)
	                {
	                    if(j+1>=str.length())
	                    ans++;
	                    else
	                    ans+=dp[j+1][sum];
	                }
	            }
	            dp[i][pre]=ans;
	        }
	    }
	    
	    return dp[0][0];
	}
};
