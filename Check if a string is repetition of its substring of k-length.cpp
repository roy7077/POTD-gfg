// Time complexity - O(N)
// Space complexity- O(N)
class Solution{
   public:
	int kSubstrConcat (int n, string s, int k)
	{
	    if(n%k)
	    return 0;
	    
	    unordered_map<string,int> mp;
	    string st="";
	    st+=s[0];
	    for(int i=1;i<n;i++)
	    {
	        if(i%k==0)
	        {
	            mp[st]=1;
	            st="";
	            if(mp.size()>2)
	            return 0;
	        }
	        
	        st+=s[i];
	    }
	    
	    mp[st]=1;
	    if(mp.size()>2)
	    return 0;
	    
	    return 1;
	}
};