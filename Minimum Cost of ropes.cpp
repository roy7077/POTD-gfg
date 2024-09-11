// Time complexity - O(NlogN)
// Space complexity- O(N)
#define ll long long
class Solution {
    public:
    long long minCost(vector<long long>& arr) {
        priority_queue<ll,vector<ll>,greater<ll>> pq;
        for(auto& it:arr)
        pq.push(it);
        
        ll minCost=0;
        while(pq.size()>1)
        {
            ll first=pq.top();
            pq.pop();
            
            ll second=pq.top();
            pq.pop();
            
            ll sum=first+second;
            minCost+=sum;
            pq.push(sum);
        }
        return minCost;
    }
};
