#define ll long long
class Solution {
  public:
    long long maxDiamonds(int A[], int N, int K) {
        
        priority_queue<int> pq;
        for(int i=0;i<N;i++)
        pq.push(A[i]);
        
        
        ll ans=0;
        for(int i=0;i<K;i++)
        {
            int temp=pq.top();
            pq.pop();
            
            ans+=temp;
            pq.push(temp/2);
        }
        
        return ans;
    }
};

//time complexity  - O(NlogN)
//space complexity - O(N)