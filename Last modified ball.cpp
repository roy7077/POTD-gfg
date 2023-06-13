class Solution {
  public:
    int solve(int N, vector<int> A) {
        
        for(int i=N-1;i>=0;i--)
        {
            if(A[i]<9)
            return i+1;
        }
    }
};

// time complexity  - O(N)
// space complexity - O(1)