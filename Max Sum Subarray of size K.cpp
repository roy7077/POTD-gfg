// Time complexity - O(N)
// Space complexity- O(1)
#define ll long long
class Solution{   
    public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        ll sum=0;
        for(int i=0;i<K;i++)
        sum+=Arr[i];
        
        int j=K;
        int i=0;
        ll maxi=sum;
        while(j<N)
        {
            sum+=Arr[j];
            sum-=Arr[i];
            i++;
            j++;
            
            if(sum>maxi)
            maxi=sum;
        }
        return maxi;
    }
};