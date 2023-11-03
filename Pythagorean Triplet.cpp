// Time complexity - O(NlogN)
// Space complexity- O(1)
class Solution{
    public:
	// Function to check if the
	// Pythagorean triplet exists or not
	bool checkTriplet(int arr[], int n) {
	    
	    sort(arr,arr+n,greater<int>());
	    for(int i=0;i<n;i++)
	    {
	        int c=arr[i]*arr[i];
	        int j=i+1;
	        int k=n-1;
	        
	        while(j<k)
	        {
	            int a=arr[j]*arr[j];
	            int b=arr[k]*arr[k];
	            if((a+b)==c)
	            return 1;
	            else if((a+b)<c)
	            k--;
	            else
	            j++;
	        }
	    }
	    return 0;
	}
};
