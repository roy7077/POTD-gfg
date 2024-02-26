

/* Power set
   Time complexity - O(N*2^n)
   Space complexity- O(N*N)
*/
class Solution{
	    public:
		vector<string> AllPossibleStrings(string s){
		    int n=s.length();
		    vector<string> ans;
		    for(int i=0;i<(1<<n);i++)
		    {
		        string temp="";
		        for(int j=0;j<n;j++)
		        {
		            if(i&(1<<j))
		            temp+=s[j];
		        }
		        if(temp.length())
		        ans.push_back(temp);
		    }
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};

/* Recursion
   Time complexity - O(N*2^n)
   Space complexity- O(N*N)
*/
class Solution{
	    public:
	    void help(string& s,int i,string temp,vector<string>& ans)
	    {
	        //base case
	        if(i>=s.length())
	        {
	            if(temp.length())
	            ans.push_back(temp);
	            
	            return ;
	        }
	        
	        //recursive calls
	        //and small calculation
	        help(s,i+1,temp,ans);
	        help(s,i+1,temp+s[i],ans);
	    }
		vector<string> AllPossibleStrings(string s){
		    int n=s.length();
		    vector<string> ans;
		    help(s,0,"",ans);
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};
