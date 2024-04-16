
// Method - 1
// Time complexity - O(NlogN+Q*(logN))
// Space complexity- O(1)
class Solution {
    public:
    int binarySearch(vector<int>& b,int x)
    {
        int s=0;
        int e=b.size()-1;
        int ind=-1;
        
        while(s<=e)
        {
            int mid=(s+e)/2;
            if(b[mid]<=x)
            {
                ind=mid;
                s=mid+1;
            }
            else
            e=mid-1;
        }
        
        return ind;
    }
    vector<int> countElements(vector<int> &a, vector<int> &b, int n, vector<int> &query, int q) {
        
        sort(b.begin(),b.end());
        vector<int> ans;
        for(auto it:query)
        {
            int ind=binarySearch(b,a[it]);
            ans.push_back(ind+1);
        }
        return ans;
    }
};


// Method - 2
// Prefix sum
// Time complexity - O(10^5+Q)
// Space complexity- O(10^5)
class Solution {
    public:
    vector<int> countElements(vector<int> &a, vector<int> &b, int n, vector<int> &query, int q) {
        int size=1e5;
        int pre[size+1]={0};
        for(auto it:b)
        pre[it]++;
        
        for(int i=1;i<=size;i++)
        pre[i]+=pre[i-1];
        
        vector<int> ans;
        for(auto it:query)
        ans.push_back(pre[a[it]]);
    
        return ans;
    }
};