// Method - 1
// Merge
// Time complexity - O(N+M)
// Space complexity- O(N+M)
class Solution {
    public:
    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2) {
        vector<int> v;
        int i=0;
        int j=0;
        int n=arr1.size();
        int m=arr2.size();
        
        while(i<n and j<m)
        {
            if(arr1[i]<arr2[j])
            {
                v.push_back(arr1[i]);
                i++;
            }
            else
            {
                v.push_back(arr2[j]);
                j++;
            }
        }
        
        while(i<n)
        {
            v.push_back(arr1[i]);
            i++;
        }
        
        while(j<m)
        {
            v.push_back(arr2[j]);
            j++;
        }
        
        if(v.size()&1)
        return v[v.size()/2];
        
        return v[v.size()/2]+v[(v.size()/2)-1];
    }
};

// 1 2 3 4 5 6



