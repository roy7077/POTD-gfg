// Time complexity - O(N)
// Space complexity- O(1)
class Solution{
    public:
	int nthStair(int n){
	    int cnt=0;
	    for(int i=0;i<=n;i++)
	    {
	        if((n-i)%2==0)
	        cnt++;
	    }
	    return cnt;
	}
};
