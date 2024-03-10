//Unordered map & String
/* Method - 1
   Time complexity - O(N)
   Space complexity- O(N+N)
*/
class Solution{
    public:
	string removeDuplicates(string str) {
	    unordered_map<char,int> mp;
	    string ans="";
	    for(auto it:str)
	    {
	        if(mp.count(it)==0)
	        {
	            mp[it]++;
	            ans+=it;
	        }
	    }
	    return ans;
	}
};


//Unordered map & Pointer
/* Method - 2
   Time complexity - O(N)
   Space complexity- O(N)
*/
class Solution{
    public:
	string removeDuplicates(string str) {
	    unordered_map<char,int> mp;
	    int i=0;
	    for(auto it:str)
	    {
	        if(mp.count(it)==0)
	        {
	            mp[it]=1;
	            str[i]=it;
	            i++;
	        }
	    }
	    return str.substr(0,i);
	}
};