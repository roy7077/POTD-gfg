class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	   
	    priority_queue<int> pq;
	    for(int i=0;i<n;i++)
	    pq.push(arr[i]);
	    
	    vector<int> ans;
	    for(int i=0;i<k;i++)
	    {
	        ans.push_back(pq.top());
	        pq.pop();
	    }
	    
	    return ans;
	}

};

// time complexity  - O(k*logN)
// space complexity - O(N)
