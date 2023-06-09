
class Solution
{
	public:
	
	    void helper(vector<string>& ans,string v,string s,map<char,int>& mp)
	    {
	        // base case
	        if(v.length()==s.length())
	        {
	            ans.push_back(v);
	            return ;
	        }
	        
	        for(int j=0;j<s.length();j++)
	        {
	            if(mp[s[j]]!=0)
	            {
	                mp[s[j]]--;
	                helper(ans,v+s[j],s,mp);
	                mp[s[j]]++;
	            }
	        }
	    }
		vector<string>find_permutation(string S)
		{
		    vector<string> ans;
		    string v="";
		    map<char,int> mp;
		    for(auto it:S)
		    mp[it]++;
		    
		    set<string> st;
		    helper(ans,v,S,mp);
		    
		    for(auto it:ans)
		    st.insert(it);
		    
		    ans.clear();
		    for(auto it:st)
		    ans.push_back(it);
		    
		    sort(ans.begin(),ans.end());
	        return ans;
		}
};

// time complexity - O(n^n)
// space compleixity - O(n)

