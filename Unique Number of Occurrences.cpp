class Solution
{
    public:
    bool isFrequencyUnique(int n, int arr[])
    {
        unordered_map<int,int> m1,m2;
        for(int i=0;i<n;i++)
        m1[arr[i]]++;
        
        for(auto it:m1)
        {
            if(m2.count(it.second))
            return false;
            
            m2[it.second]++;
        }
        
        return true;
    }
};