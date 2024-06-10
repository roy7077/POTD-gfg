// Time complexity - O(NlogN)
// Space complexity- O(1)
class Solution {
    public:
    static bool cmp(char a, char b)
    {
        return int(a)<int(b);
    }
    void matchPairs(int n, char nuts[], char bolts[]) {
        sort(nuts,nuts+n,cmp);
        sort(bolts,bolts+n,cmp);
    }
};

