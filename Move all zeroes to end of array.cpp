/*-------TWO APPROACHES || EASY AND BEST SOLUTION -----------------*/

/*------------------EXTRA SPACE APPROACH---------------------*/
// Time complexity - O(N)
// Space complexity- O(N)
class Solution{
    public:
	void pushZerosToEnd(int arr[], int n) {
	    vector<int> temp(n,0);
	    int j=0;
	    for(int i=0;i<n;i++)
	    {
	        if(arr[i]!=0)
	        {
	            temp[j]=arr[i];
	            j++;
	        }
	    }
	    
	    for(int i=0;i<n;i++)
	    arr[i]=temp[i];
	}
};


/*-----------------TWO POINTER APPROACH---------------*/
// Time complexity - O(N)
// Space complexity- O(1)
class Solution{
    public:
	void pushZerosToEnd(int arr[], int n) {
	    int i=0;
	    int j=0;
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