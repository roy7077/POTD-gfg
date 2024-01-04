//UNORDERED MAP
//Time complexity - O(N)
//Space complexity- O(N)
class Solution {
    public:
    int singleElement(int arr[] ,int N) {
        unordered_map<int,int> mp;
        for(int i=0;i<N;i++)
        mp[arr[i]]++;
        
        for(auto it:mp)
        {
            if(it.second==1)
            return it.first;
        }
        return -1;
    }
};

//BIT MANIPULATION
//Time complexity - O(32*N)
//Space complexity- O(1)
class Solution {
    public:
    int singleElement(int arr[] ,int N) {
        int ans=0;
        int i=0;
        while(i<=31)
        {
            int cnt=0;
            int x=(1<<i);
            for(int i=0;i<N;i++)
            {
                if(arr[i]&x)
                cnt++;
            }
            
            if(cnt%3)
            ans=ans|(1<<i);
            
            i++;
        }
        return ans;
    }
};