#define ll long long
class Solution {
    public:
    long long maxSum(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<int> v;
        int n=arr.size();
        int i=0;
        int j=arr.size()-1;
        
        bool flag=1;
        while(i<=j)
        {
            if(flag)
            v.push_back(arr[j--]);
            else
            v.push_back(arr[i++]);
            
            flag=(!flag);
        }
        
        ll sum=0;
        for(int i=0;i<n-1;i++)
        sum+=abs(v[i]-v[i+1]);
        
        sum+=abs(v[n-1]-v[0]);
        return sum;
    }
};


// 8 1 4 2
// 7+3+2+6
