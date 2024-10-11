// Time complexity - O(N)
// Space complexity- O(1)
class Solution {
    public:
    vector<int> rearrange(vector<int>& arr) {
        
        int n=arr.size();
        int i=0;
        while(i<n)
        {
            if(arr[i]!=-1 and arr[arr[i]]!=arr[i])
            swap(arr[i],arr[arr[i]]);
            else
            i++;
        }
        return arr;
        
        // int n=arr.size();
        // bool isZero=0;
        // for(auto& it:arr)
        // {
        //     if(it==-1)
        //     it=n;
        //     else if(it==0)
        //     isZero=1;
        // }
        
        // int maxi=1e5+1;
        // for(int i=0;i<arr.size();i++)
        // {
        //     if((arr[i]%maxi)>=n)
        //     continue;
            
        //     int ori=arr[arr[i]%maxi]%maxi;
        //     int newNumber=arr[i]%maxi;
            
        //     arr[arr[i]%maxi]=newNumber*maxi+ori;
        // }
        
        // if(isZero)
        // arr[0]=0;
        // else
        // arr[0]=-1;
        
        // for(int i=1;i<arr.size();i++)
        // {
        //     int ori=arr[i]%maxi;
        //     int newNumber=arr[i]/maxi;
            
        //     if(newNumber>=n or newNumber<=0)
        //     arr[i]=-1;
        //     else
        //     arr[i]=newNumber;
        // }
        
        // return arr;
    }
};
