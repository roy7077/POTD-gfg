class Solution {
    public:
    long long sumMatrix(long long n, long long q) {
        return max((long long)0,(q-1)-max((long long)0,(q-(n+1))*2));
    }
};
