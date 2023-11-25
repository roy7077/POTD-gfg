// Time complexity - O(N)
// Space complexity- O(1)
class Solution{
	public:
	void shuffleArray(int arr[],int n)
	{
	    int maxi=1e5;
	    int i=0;
	    int j=n/2;
	    
	    while(j<n)
	    {
	        arr[i]=(arr[j]*maxi)+arr[i];
	        i++;
	        j++;
	    }
	    
	    i=(n/2)-1;
	    j=n-1;
	    
	    while(i>=0)
	    {
	        arr[j]=arr[i]/maxi;
	        arr[j-1]=arr[i]%maxi;
	        j-=2;
	        i--;
	    }
	    
	}
};