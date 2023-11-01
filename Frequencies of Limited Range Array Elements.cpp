/*-----BRUTE FORCE -----> OPTIMIZED APPROACH --------------*/

//UNORDERED MAP 
// Time complexity - O(N)
// Space complexity- O(N)
class Solution{
    public:
    void frequencyCount(vector<int>& arr,int N, int P)
    { 
        unordered_map<int,int> mp;
        for(auto it:arr)
        mp[it]++;
        
        for(int i=0;i<N;i++)
        arr[i]=mp[i+1];
    }
};

//IN-PLACE
// Time complexity - O(N)
// Space complexity- O(1)
class Solution{
    public:
    void frequencyCount(vector<int>& arr,int N, int P)
    { 
        for(int i=0;i<N;i++)
        {
            if(arr[i]>N)
            arr[i]=0;
        }
        
        int maxi=N+1;
        for(auto& it:arr)
        {
            int orgi=it%maxi;
            int newval=it/maxi;
            
            if(orgi==0)
            continue;
            
            int orgi1=arr[orgi-1]%maxi;
            int newval1=arr[orgi-1]/maxi;
            newval1++;
            arr[orgi-1]=(newval1*maxi)+orgi1;
        }
        
        for(auto& it:arr)
        it/=maxi;
    }
};
