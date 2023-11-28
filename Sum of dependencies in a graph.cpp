// Time complexity - O(V)
// Space complexity- O(1)
class Solution {
    public:
    int sumOfDependencies(vector<int> adj[], int V) {
        
        int sum=0;
        for(int i=0;i<V;i++)
        sum+=adj[i].size();
        
        return sum;
    }
};