class Solution {
  public:
    int isPossible(int N, int arr[]) {
        
        long long sum=0;
        for(int i=0;i<N;i++)
        sum+=arr[i];
        
        if(!(sum%3))
        return 1;
        else
        return 0;
    }
};
