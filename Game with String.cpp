
/* Method - 1
   unordered map & priority queue
   Time complexity - O(n+klog(p))
   Space complexity- O(2*N)
*/
class Solution{
    public:
    int minValue(string s, int k){
        unordered_map<char,int> mp;
        for(auto it:s)
        mp[it]++;
        
        priority_queue<int> pq;
        for(auto it:mp)
        pq.push(it.second);
        
        while(k)
        {
            int f=pq.top();
            pq.pop();
            f--;
            pq.push(f);
            k--;
        }
        
        int cnt=0;
        while(!pq.empty())
        {
            int f=pq.top();
            pq.pop();
            cnt+=(f*f);
        }
        return cnt;
    }
};

/* Method - 2
   Sorting & priority queue
   Time complexity - O(nlogn+klog(p))
   Space complexity- O(N)
*/
class Solution{
    public:
    int minValue(string s, int k){
        
        sort(s.begin(),s.end());
        priority_queue<int> pq;
        int cnt=1;
        for(int i=1;i<s.length();i++)
        {
            if(s[i]==s[i-1])
            cnt++;
            else
            {
                pq.push(cnt);
                cnt=1;
            }
        }
        
        if(cnt)
        pq.push(cnt);
        
        while(k)
        {
            int f=pq.top();
            pq.pop();
            f--;
            pq.push(f);
            k--;
        }
        
        cnt=0;
        while(!pq.empty())
        {
            int f=pq.top();
            pq.pop();
            cnt+=(f*f);
        }
        return cnt;
    }
};
