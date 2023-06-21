class Solution {
  public:
    int sumOfNaturals(int n) {
        
        int mod=1e9+7;
        long long temp=n;
        long long sum=(temp*(temp+1))/2;
        
        return sum%mod;
    }
};