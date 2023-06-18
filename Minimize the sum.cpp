class Solution {
public:
    int minimizeSum(int N, vector<int> arr) 
    {
        
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto it:arr)
        pq.push(it);
        
        int sum=0;
        while(pq.size()>1)
        {
            int a=pq.top();
            pq.pop();
            int b=pq.top();
            pq.pop();
            
            sum+=a+b;
            pq.push(a+b);
        }
        
        return sum;
    }
};

// Time Complexity: O(N * log(N))
// Auxiliary Space: O(N)