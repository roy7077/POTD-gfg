// Time complexity - O(1)
// Space complexity- O(1)
class Solution {
    public:
    bool divisorGame(int n) {
        if(n&1)
        return 0;
        else
        return 1;
    }
};