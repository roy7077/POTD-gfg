/*
 Method - 1
 Unordered Map
 Time complexity - O(N)
 Space complexity- O(N)
*/
class Solution {
    public:
    int findPair(int n, int x, vector<int> &arr) {
        unordered_map<int,int> mp;
        for(auto& it:arr)
        mp[it]++;
        
        for(auto& it:mp)
        {
            int req=x+it.first;
            if(req==it.first)
            {
                if(it.second>=2)
                return 1;
                
                continue;
            }
            
            if(mp.count(req))
            return 1;
        }
        return -1;
    }
};


/*
 Method - 2
 Sorting + Binary Search
 Time complexity - O(N*LogN)
 Space complexity- O(1)
*/
class Solution {
    public:
    bool binarySearch(vector<int>& arr,int& val,int& ind)
    {
        int n=arr.size();
        int s=0;
        int e=n-1;
        while(s<=e)
        {
            int mid=(s+e)/2;
            if(arr[mid]==val)
            {
                if(mid==ind)
                {
                    if(mid+1<=e and arr[mid+1]==val)
                    return 1;
                    
                    if(mid-1>=s and arr[mid-1]==val)
                    return 1;
                    
                    return 0;
                }
                return 1;
            }
            else if(arr[mid]>val)
            e=mid-1;
            else
            s=mid+1;
        }
        return 0;
    }
    int findPair(int n, int x, vector<int> &arr) {
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++)
        {
            int req=x+arr[i];
            if(binarySearch(arr,req,i))
            return 1;
        }
        return -1;
    }
};