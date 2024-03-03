
// Time complexity - O(NlogN)
// Space complexity- O(N)
class Solution{
    public:
    static bool cmp(string& s1,string& s2)
    {
        if((s1+s2)>(s2+s1))
        return 1;
        else
        return 0;
    }
	string printLargest(int n, vector<string> &arr) {
	    sort(arr.begin(),arr.end(),cmp);
	    string ans="";
	    for(auto& it:arr)
	    ans+=it;
	    
	    return ans;
	}
};
