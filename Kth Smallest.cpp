// Time complexity - O(NlogK)
// Space complexity- O(K)
class Solution {
    public:
    int kthSmallest(vector<int> &arr, int k) {
        priority_queue<int> pq;
        for(auto& it:arr)
        {
            if(pq.size()<k)
            pq.push(it);
            else
            {
                if(pq.top()>it)
                {
                    pq.pop();
                    pq.push(it);
                }
            }
        }
        return pq.top();
    }
};
