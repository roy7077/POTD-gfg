// Time complexity - O(1)
// Space complexity- O(1)
class Solution
{
    public:
    // Function to check if Kth bit is set or not.
    bool checkKthBit(int n, int k)
    {
        if(n&(1<<k))
        return 1;
        else
        return 0;
    }
};