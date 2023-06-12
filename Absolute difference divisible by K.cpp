/**---Important algorithm-----
 * 
 * (a*b)%k==0;
 * then it is sure that 
 * a is divisible by k and 
 * b is also divisible by k
 * 
 * (a-b)%k==0
 * then is is sure that
 * a%k==x
 * b%k==x
 * 
 * remainder for both should be same
 * 
 **/
#define ll long long
class Solution {
  public:
    long long countPairs(int n, int arr[], int k) {
        
        vector<int> v(k,0);
        for(int i=0;i<n;i++)
        v[arr[i]%k]++;
        
        ll cnt=0;
        for(auto it:v)
        cnt+=((double)(it*(it-1)))/2;
        
        return cnt;
        
        
    }
};

// time complexity -  O(N)
// space complexity - O(K)
