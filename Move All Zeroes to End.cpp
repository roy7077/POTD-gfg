class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
       int i=0;
	    int j=0;
	    int n=arr.size();
	    while(j<n)
	    {
	        if(arr[j]!=0)
	        {
	            int temp=arr[j];
	            arr[j]=arr[i];
	            arr[i]=temp;
	            i++;
	        }
	        j++;
	    }
    }
};
