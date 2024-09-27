typedef pair<int,int> pi;
class Solution {
    public:
    vector<int> max_of_subarrays(int k, vector<int> &arr) {
        priority_queue<pi> pq;
        int n = arr.size();
        int i = 0;
        int j = 0;
        
        while(j < k && j < n)
        pq.push({arr[j], j++});
        
        vector<int> ans;
        ans.push_back(pq.top().first); 
        
        // Start sliding the window
        while(j < n) 
        {
            pq.push({arr[j], j}); 
            i++;  
            
            while(!pq.empty() && pq.top().second < i)
            pq.pop();
            
            ans.push_back(pq.top().first);
            j++;
        }
        return ans;
    }
};
