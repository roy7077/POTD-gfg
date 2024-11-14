// Time complexity - O(NlogK)
// Space complexity- O(K)
class Solution {
    public:
    void nearlySorted(vector<int>& arr, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        int j=0;
        int i=0;
        while(j<=k)
        {
            pq.push(arr[j]);
            j++;
        }
        
        while(j<arr.size())
        {
            arr[i]=pq.top();
            pq.pop();
            
            pq.push(arr[j]);
            j++;
            i++;
        }
        
        while(!pq.empty())
        {
            arr[i]=pq.top();
            pq.pop();
            i++;
        }
    }
};
